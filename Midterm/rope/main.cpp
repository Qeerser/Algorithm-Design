#include<iostream>
#include <vector>
using namespace std;




int main()
{
    int n;
    cin >> n;
    vector<int> S(3), dp(n + 1);  
    for (int i = 0 ; i < 3 ; i++ ) cin >> S[i];

    for (int i = 0 ; i <= n ; i++) {
        for (auto &k : S) if (i + k <= n) dp[i + k] = max(dp[i + k],dp[i] + 1);
    }
    cout << dp[n];
          
}
