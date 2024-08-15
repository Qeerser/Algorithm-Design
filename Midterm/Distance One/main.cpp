#include<iostream>
#include <vector>
using namespace std;
int main()
{
    int n ,k;
    cin >> n >> k;
    vector<int> dp(n);
    dp[n - k] = 1 <<(k - 1);
    for (int i = n - k  ; i > 0 ; i--){
        dp[i - 1] += dp[i];
        if (i - k >= 0) dp[i - k] += dp[i];
    }
    
    cout << dp[0];
}