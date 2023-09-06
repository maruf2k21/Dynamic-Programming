#include <bits/stdc++.h>
using namespace std;
// 10 9 2 5 3 7 101 18
const int mx = 1e5 + 123;
int dp[mx];
int lis(int i,vector<int>& nums)
{
    if (dp[i] != -1)
        return dp[i];
    int ans = 1;
    for (int j = 0; j < i; j++)
    {
        if (arr[i] > arr[j])
        {
            ans = max(ans, lis(j, arr) + 1);
        }
    }
    return dp[i] = ans;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(int);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, lis(i, arr));
    }
    cout << ans << endl;

    return 0;
}