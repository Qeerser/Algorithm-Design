#include<iostream>
#include<vector>
#include<set>
#include <algorithm>
using namespace std;

vector<pair<int,vector<int>>> S;
int Min_i,M;
int solve(int n,set<int> list,int m){
    if(list.empty()){ Min_i = m ; return m;}
    if (m >= Min_i)return m;
    if(n == M) return (list.empty()? m: M );
   
    auto tmb = list;
    for (auto &i : S[n].second) tmb.erase(i);

    return min(solve(n + 1,tmb,m + 1),solve(n + 1,list,m)); 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    M = m;
    Min_i = m;
    S.resize(m);
    vector<bool> sol(n);
    set<int> list; 
    for (int i = 1; i <= n ; i++)list.insert(i);


    // Your existing code
     for(int i = 0 ; i< m; i++){
        int d;
        cin >> d;
        S[i].first = n - d;
        S[i].second.resize(d);
        for (int j = 0 ; j < d ; j++) cin >> S[i].second[j];
        
    }
    sort(S.begin(),S.end());
    cout << solve(0,list,0);

}

