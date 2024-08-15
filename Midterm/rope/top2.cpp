#include<iostream>
#include <vector>

using namespace std;


vector<int> S(3),dp;
vector<bool> dps;
int solve (int n, int k){
    if (n < 0) return -1;
    if (n == 0) return 0;
    if(dps[n]) return dp[n];
    

    int m = 1 + max(solve (n - S[0],k + 1),max( solve (n - S[1],k + 1), solve (n - S[2],k + 1)));
    dp[n] = m;
    dps[n] = true;
    return  m;
}

int main()
{
    int n ;
    cin >> n;
    dp.resize(n + 1);
    dps.resize(n + 1);
    for (auto &i : S) cin >> i;
    cout << solve(n  ,0);
}