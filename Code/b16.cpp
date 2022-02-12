#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10;

int n;
int parent[MAXN];
long long dist[MAXN], cnt[MAXN], dist_child[MAXN];
vector<int> g[MAXN];

// cnt[u] = number of node in sub-tree with root u
// dist_child[u] = sum distance from u to its child
void calcDistChild(int u) {
    cnt[u] = 1;
    dist_child[u] = 0;

    // calculate cnt and dist_child from u's children
    for (auto v: g[u]) {
        if (!parent[v]) {
            parent[v] = u;
            calcDistChild(v);
            // update visited branch v into cnt[u] and dist_child[u]
            cnt[u] += cnt[v];
            dist_child[u] += cnt[v] + dist_child[v];
        }
    }
}

// dist[u] = distance from u to all other node
void calcDist(int u) {
    if (parent[u] == -1) // root have dist = dist_child
        dist[u] = dist_child[u];
    else {
        int p = parent[u];
        // dist_parent[u] = (dist[p] but exclude branch u) + (all node that is not child of u)*1
        // dist[u] = dist_parent[u] + dist_child[u]
        dist[u] = dist[p] - (cnt[u] + dist_child[u])
                + (n - cnt[u]) + dist_child[u];
    }

    // calculate dist for child of u
    for (auto v: g[u]) {
        if (parent[v] == u)
            calcDist(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    parent[1] = -1;
    calcDistChild(1);
    calcDist(1);

    long long res = 0;
    for (int u = 1; u <= n; ++u)
        res += dist[u];
    cout << res / 2;

    return 0;
}
