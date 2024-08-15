#include<iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> B(n) ,dp;
    for (int i = 1 ; i <= n ; i++)B[i - 1].resize(i);
   
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j <= i ; j++)cin >> B[i][j];
    }
    dp = B;
        
    for (int i = n - 2 ;i >= 0 ; i--){
        for (int j = 0 ; j <= i ;j++)dp[i][j] += max(dp[i + 1][j],dp[i + 1][j + 1]);
    }
    cout << dp[0][0];
    
}