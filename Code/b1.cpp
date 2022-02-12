#include <bits/stdc++.h>
using namespace std;

const int MAXA = 1e6 + 10;

// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Function to find gcd of array of
// numbers
int findGCD(int arr[], int l, int k)
{
    int res = arr[l];
    for (int i = l + 1; i < l + k; i++)
    {
        res = gcd(arr[i], res);
        if (res == 1)
            return 1;
    }
    return res;
}

int findMaxGCD(int arr[], int n, int k)
{
    int res = 1;
    for (int i = 1; i <= n - k + 1; i++)
    {
        res = max(res, findGCD(arr, i, k));
    }
    return res;
}

int cnt[MAXA];

void increase(int x, int k, int& curGCD) {
    int i = 2;
    int a = x;
    for (int i = 2; i <= sqrt(a); ++i) {
        int q, t = 1;
        for (q = i; x % q == 0; q *= i) {
            ++cnt[q];
            if (cnt[q] == k)
                t = q;
        }
        q /= i;
        x /= q;
        curGCD *= t;
    }

    if (x > 1) {
        ++cnt[x];
        if (cnt[x] == k)
            curGCD *= x;
    }
}

void decrease(int x, int k, int& curGCD) {
    int i = 2;
    int a = x;
    for (int i = 2; i <= sqrt(a); ++i) {
        int q, t = 1;
        for (q = i; x % q == 0; q *= i) {
            --cnt[q];
            if (cnt[q] == k - 1)
                t = q;
        }
        q /= i;
        x /= q;
        curGCD /= t;
    }

    if (x > 1) {
        --cnt[x];
        if (cnt[x] == k - 1)
            curGCD /= x;
    }
}

int solve2(int a[], int n, int k) {
    int curGCD = 1, res = 1;
    for (int i = 1; i <= k; ++i) {
        increase(a[i], k, curGCD);
    }

    res = max(res, curGCD);

    for (int i = 2; i <= n - k + 1; ++i) {
        decrease(a[i - 1], k, curGCD);
        increase(a[i + k -1], k, curGCD);
        res = max(res, curGCD);
    }

    return res;
}

int main(int argc, char const *argv[])
{
    int n, k, a[1000];
    cin >> n >> k;
    // Input
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // Output
    cout << findMaxGCD(a, n, k) << "\n";
    cout << solve2(a, n, k);
    return 0;
}
