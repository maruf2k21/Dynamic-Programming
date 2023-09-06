#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

const int mx = 1e5 + 123;
int dp[mx];
int arr[mx];
int solve(int idx)
{
    if (idx == 0)
        return 0;
    if (dp[idx != -1])
        return dp[idx];
    int cost = INT_MAX;
    // way1
    // if (idx - 1 >= 0)
    cost = min(cost, solve(idx - 1) + abs(arr[idx] - arr[idx - 1]));
    // way 2
    // if (idx - 2 >= 0)
    if (idx > 1)
        cost = min(cost, solve(idx - 2) + abs(arr[idx] - arr[idx - 2]));
    return dp[idx] = cost;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << solve(n - 1);

    return 0;
}
