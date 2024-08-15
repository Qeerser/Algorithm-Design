#include<iostream>
#include <vector>
using namespace std;

vector<int> dp,S;
vector<bool> dps;

long long solve (int n){
    if (n == 0) return 1;
    if (n < 0) return 0;
    if (dps[n] == true) return dp[n];
    long long sum = 0;
    //cout << n; 
    for (auto &i : S) sum =  (sum +  solve(n - i) % 1000003) % 1000003 ;
    dps[n] = true;
    dp[n] = sum;
    return sum % 1000003 ;
}

int main()
{
    int n,k;
    cin >> n >> k;
    S.resize(k);
    dp.resize(n + 1);
    dps.resize(n + 1);
    for (int i = 0; i < k ; i++) cin >> S[i];

    cout << solve(n) ;
}