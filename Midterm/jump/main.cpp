#include<iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> S(n), dp(n);  
    for (int i = 0 ; i < n ; i++ ) cin >> S[i];
    dp = S;
    for (int i = 1 ; i < n ; i++) {
        int add = -9999999;
        for (int k = 1; k <= 3; k++) if (i - k >= 0) add = max(add, dp[i - k]);
        dp[i] += add ;
    }
    cout << dp[n - 1];
          
}
