#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

void combi(int n, vector<int> &sol, int len, int k, int chosen, vector<bool> t, int &minElements, map<int, vector<int>> &date,vector<pair<int,int>> &mu) {
    // Your existing code with modifications
    if(sol[len-1] ) for (auto i : date[mu[n-len].second]) t[i-1] = true;
    bool at = true;
    for (auto x : t) at = at && x;
    if(chosen > minElements)return;
    if (len < n && !at) { 
        if (chosen < k){
            sol[len] = 1;
            combi(n,sol,len+1,k,chosen+1,t,minElements,date,mu);
        }
        sol[len] = 0;
        combi(n,sol,len+1,k,chosen,t,minElements,date,mu);
    }
    else{
       // for (auto &x : sol)cout << x;
        //cout<< endl;
        if(at)minElements = min(minElements,chosen);
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> k >> n;

    vector<bool> t(k);
    vector<int> sol(n);
    map<int, vector<int>> date;
    int minElements = k;
    vector<pair<int,int>> mu;

    // Your existing code
     for(int i = 0 ; i< n; i++){
        int d;
        cin >> d;
        for (int j = 0 ; j < d ; j++){
            int p ;
            cin >> p;
            mu.push_back(make_pair(d,i));
            date[i].push_back(p);
        }
    }

    sort(mu.begin(),mu.end());
    combi(n, sol, 0, k, 0, t, minElements, date,mu);
    cout << minElements;

}
