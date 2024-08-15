#include <iostream>
#include <vector>
using namespace std;

void ot(vector<vector<pair<int, int>>> dp, int i, int j)
{
    if (i == j)
    {
        cout << "B" << i + 1;
        return;
    }
    if (i + 1 == j)
    {
        cout << "B" << i + 1 << "B" << j + 1 << "";
        return;
    }

    cout << "(";
    ot(dp, i, dp[i][j].second);
    cout << ") (";
    ot(dp, dp[i][j].second + 1, j);
    cout << ")";
    // out <<" a"<<"n"<< endl;
}

int main()
{
    int n, k = 1, minValue = 1 << 24;
    cin >> n;
    vector<int> a(n + 1);
    vector<vector<pair<int, int>>> dp(n + 1);
    for (auto &i : dp)
        i.resize(n + 1);
    for (int i = 0; i <= n; i++)
        cin >> a[i];

    for (int i = 0; k < n; i++)
    {
        // cout << i<< "" << i+k <<endl;
        pair<int, int> minSelect = {1 << 24, 0};
        for (int j = i; j < i + k; j++)
        {
            int value = dp[i][j].first + dp[j + 1][i + k].first + (a[i] * a[j + 1] * a[i + k + 1]);
            minSelect = min(minSelect, {value, j});
        }
        dp[i][i + k] = minSelect;
        // cout <<  minSelect.first <<" "<<minSelect.second  <<"\n" ;
        if ((i + k) == n - 1)
            i = -1, k++;
    }
    cout << dp[0][n - 1].first << endl;
    ot(dp, 0, n - 1);
}