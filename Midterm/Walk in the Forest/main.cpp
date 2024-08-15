#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, m ;
    cin >> n >> m;
    vector<vector<int>> B(n + 1) ,dp;
    for(auto &i : B) i.resize(m + 1);
    dp = B;
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= m; j++)cin >>B[i][j];
    }
    dp[n][m] = B[n][m];

    for (int i = n - 1 ; i >= 1 ; i--) dp[i][m] = B[i][m] + dp[i + 1][m];
    for (int i = m - 1 ; i >= 1 ; i--) dp[n][i] = B[n][i] + dp[n][i + 1];
    

    for (int i = n -1 ; i >= 1 ; i--){
        for (int j = m -1 ; j >= 1; j--){
            dp[i][j] = B[i][j] + max(max(dp[i ][j + 1],dp[i + 1][j]), dp[i + 1][j + 1] + B[i + 1][j + 1]);
        }
    }
    cout << dp[1][1];
}