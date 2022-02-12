#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<pair<int, int>> a, int n, int m) {
  sort(a.begin(), a.end(), [](const auto &a, const auto &b) {
    return a.first - a.second >= b.first - b.second;
  });
  vector<int> dp(n + m + 1, 0);
  for (auto p : a) {
    for (int i = n + m; i >= 1; --i) {
      dp[i] = max(dp[i], dp[i - 1] + (i <= n? p.first : p.second));
    }
  }
  return dp[n + m];
}

int main(){
    freopen("input.txt", "r", stdin);

    int k, n, m;
    cin >> k >> n >> m;

    vector< pair<int, int>> A(k+1);

    for (int i = 1; i <= k; i++){
        int x,y;
        cin >> x >> y;
        A[i] = {x,y};
    }
    cout << solve(A, n, m);

    return 0;
}
