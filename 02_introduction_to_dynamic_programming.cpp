#include <bits/stdc++.h>
using namespace std;

// dynamic programming
// {
//     solves problem optimally

// }
// calculate fibonacci number
// 0 1 1 2 3 5 8

// top down approach (basically recursion)
// we start from bigger problem and coninuously makes it small problem
// top down approach problem solving steps:
// 1.try to write the brute force recurssion for the problem
// 2.depending on the state take 1d,2d dp arrray

// botttom up approach(we can use recursion in it also)
// wer start from small problem then we continuously solve bigger problems using small problem knowledge

// Thic code is top down approach
int cnt = 0;
long long int fibo[1000]; // dynamic progeramming
bool vis[1000];           // dynamic programming
int fibonacci(int n)
{
    if (vis[n]) // memoize
    {
        return fibo[n];
    }
    cnt++;
    vis[n] = 1;
    if (n == 0)
    {
        fibo[n] = 0;
        return fibo[n];
    }
    if (n == 1 || n == 2)
    {
        fibo[n] = 1;
        return fibo[n];
    }
    return fibo[n] = fibonacci(n - 1) + fibonacci(n - 2); // memoize
}

int main()
{
    int nth;
    cout << "Enter number to see nth fibonacci: ";
    cin >> nth;
    cout << fibonacci(nth) << endl;
    cout << cnt << endl;

    return 0;
}