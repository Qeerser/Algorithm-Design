#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, k, idx = 1;
   cin >> n >> k;
    vector<vector<int>> dp(n + 1);
    for(auto &i : dp) i.resize(idx++);
    for (int i = 0; i <= n; i++){
        dp[i][0] = 1;
        if (i <= k) dp[i][i] = 1;
    }

    for (int j = 1; j <= k; j++){
        for(int i = j + 1; i <= n ; i++){
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
    cout << dp[n][k];
}