#include<iostream>
#include<vector>
using namespace std;


int main()
{
    int n,k ;
    cin >> n >> k;

    vector<long long> dp(n + 1) , S(k);
    for (int i = 0; i < k ; i++) cin >> S[i];
    for (auto &i : S) dp[i] = 1;
    for(int i = 1 ; i < n ; i++){
        for(auto &j : S) 
        if(i + j <= n) dp[i + j] =  (dp[i + j] +  dp[i] % 1000003) % 1000003;
    }

    cout <<  dp[n];
}       