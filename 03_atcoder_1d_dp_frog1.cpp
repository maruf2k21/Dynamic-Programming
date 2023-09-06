#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl '\n'
#define ll long long int
#define all(v) v.begin(), v.end()
#define pb push_back //
#define mp make_pair
#define fi first                         //
#define se second                        //
#define yes cout << "YES" << endl        //
#define no cout << "NO" << endl          //
#define M 1000000007                     // 1e9+7
#define gcd(a, b) __gcd(a, b)            //
#define lcm(a, b) a *b / gcd(a, b)       //
#define memz(a) memset(a, 0, sizeof(a))  //
#define memn(a) memset(a, -1, sizeof(a)) //

const int mx = 1e5 + 123;
int dp_cost[mx];
// bottom up approach
int cost(int arr[], int idx, int size, int k)
{
    if (idx >= size - 1)
        return 0;
    if (dp_cost[idx] != -1)
        return dp_cost[idx];

    int sum[k + 1]; // storing result for each way
    for (int i = 1; i < k + 1; i++)
        sum[i] = INT_MAX;
    for (int i = 1; i < k + 1; i++)
    {
        if (idx + i < size)
        {
            sum[i] = abs(arr[idx + i] - arr[idx]) + cost(arr, idx + i, size, k);
        }
    }
    int mn = INT_MAX;
    for (int i = 1; i < k + 1; i++)
    {
        mn = min(mn, sum[i]);
    }
    return dp_cost[idx] = mn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;
    int arr[n];
    for (auto &u : arr)
        cin >> u;
    memn(dp_cost);
    cout << cost(arr, 0, n, k) << endl;

    return 0;
}
