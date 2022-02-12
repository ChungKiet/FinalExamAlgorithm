#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 1e6;
const long long MAXX = 1e9;

int n;
long long t;
int a[MAXN];

int L[MAXN];    // Min cost of digging from sections i and those to the left
int R[MAXN];    // Min cost of digging from sections i and those to the right
int result = 0; // The lowest depth that could be dug up (inclusive)

// Calcualte value of L[MAXN] in each binary search
void calCostLeft(int depth)
{
    // Reset
    for (int i = 0; i < n; i++)
        L[i] = 0;
    int stop = n - 1; // Act as a stop point.
    // All sections behind the stop point have not been account into the cost L[i]
    int prevCost = 0; // The cost of digging ONLY the previous section (the right one)
    // Traverse all elements in the array of sections
    for (int i = n - 1; i >= 0; i--)
    {
        // Check if there is a section to the right
        if (i != n - 1)
        {
            // Calculate the cost of digging ONLY the previous section (the right one)
            prevCost = a[i + 1] - depth + 1;
            // Use prefix sum to reduce complexity
            // Calculate the COST of digging from i to the stop point
            L[i] = L[i + 1] - prevCost + (i - stop);
        }
        // Exit if stop is out of bound
        if (stop == -1)
            continue;
        // Calculate the COST of from the stop point to index -1
        for (int j = stop; j >= -1; j--)
        {
            // Check if j is out of bound
            if (j == -1)
            {
                stop = j;
                break;
            }
            // Check if height at j satisfies the constraint.
            // If yes, set a stop point and break
            if (i - j > a[j] - depth)
            {
                stop = j;
                break;
            }
            // Otherwise, add the cost of digging section j into L[i]
            L[i] += a[j] - depth - (i - j) + 1;
        }
    }
}

// Calcualte value of R[MAXN] in each binary search
void calCostRight(int depth)
{
    // Reset values
    for (int i = 0; i < n; i++)
        R[i] = 0;
    int stop = 0; // Act as a stop point.
    // All sections behind the stop point have not been account into the cost R[i]
    int prevCost = 0; // The cost of digging ONLY the previous section (the left one)
    // Traverse all elements in the array of sections
    for (int i = 0; i < n; i++)
    {
        // Check if there is a section to the left
        if (i != 0)
        {
            // Calculate the cost of digging ONLY the previous section (the left one)
            prevCost = a[i - 1] - depth + 1;
            // Use prefix sum to reduce complexity
            // Calculate the COST of digging from i to the stop point
            R[i] = R[i - 1] - prevCost + (stop - i);
        }
        // Exit if stop is out of bound
        if (stop == n)
            continue;
        // Calculate the COST of from the stop point to index n
        for (int j = stop; j <= n; j++)
        {
            // Check if j is out of bound
            if (j == n)
            {
                stop = j;
                break;
            }
            // Check if height at j satisfies the constraint.
            // If yes, set a stop point and break
            if (j - i > a[j] - depth)
            {
                stop = j;
                break;
            }
            // Otherwise, add the cost of digging section j into R[i]
            R[i] += a[j] - depth - (j - i) + 1;
        }
    }
}

// Perform binary search on the depth
void binarySearch(int l, int r)
{
    if (l > r)
        return;
    // Get the current depth
    int mid = (l + r) / 2;
    // Get cost of digging to the left and the right
    calCostLeft(mid);
    calCostRight(mid);
    // minCost is the minimal cost of digging to the depth of mid
    int minCost = MAXX;
    // Find minCost in all sections
    for (int i = 0; i < n; i++)
    {
        int costAtI = a[i] - mid + 1;
        minCost = min(minCost, L[i] + R[i] - costAtI);
    }
    // Continuing the search, check if minCost <= T
    if (minCost <= t)
    {
        // Assign as the current answer
        result = mid;
        // Increase depth
        binarySearch(l, mid - 1);
    }
    else
    {
        // Decrease depth
        binarySearch(mid + 1, r);
    }
}

int main(int argc, char const *argv[])
{
    int minHeight = MAXX;
    int maxHeight = -MAXX;
    // Input
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        minHeight = min(minHeight, a[i]); // Tim do cao nho nhat trong cac doan
        maxHeight = max(maxHeight, a[i]); // Tim do cao lon nhat trong cac doan
    }
    // Output
    binarySearch(minHeight - t, maxHeight);
    // Result is the lowest depth that we could have dug up,
    // so the depth the we reach is (result - 1)
    result -= 1;
    cout << result;
    return 0;
}

/*
4 3
1 2 2 1

ans: 0

4 3
1 1 1 1

ans: -1
*/
