#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;
int a[1000000];
int mcm(int l, int r)
{
    if (l == r)
        return 0;
    int minCost = 99999999;

    if (dp[l][r] != 0)
        return dp[l][r];

    for (int i = l; i < r; i++)
    {
        int my_cost = mcm(l, i) + mcm(i + 1, r) + (a[l] * a[i + 1] * a[r + 1]);
        minCost = min(minCost, my_cost);
    }
    dp[l][r] = minCost;
    return minCost;
}

int main()
{
    int n;
    cin >> n;
    dp.resize(n + 1);

    for (auto &i : dp)
        i.resize(n + 1);
    for (int i = 0; i <= n; i++)
        cin >> a[i];
    cout << mcm(0, n - 1);
    return 0;
}