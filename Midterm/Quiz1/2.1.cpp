#include<iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void combi(int n,vector<int> &sol,int len , int k , int chosen,set<int> t,int &sum,map<int,vector<int>> date){
    if(sol[len-1] )for (auto i : date[len-1]) if(!t.count(i))t.insert(i);
    if(chosen > sum)return;
    if (len < n && t.size() != k) { 
        if (chosen < k){
            sol[len] = 1;
            combi(n,sol,len+1,k,chosen+1,t,sum,date);
        }
            
        sol[len] = 0;
        combi(n,sol,len+1,k,chosen,t,sum,date);
        
       
    }
    else{
       // for (auto &x : sol)cout << x;
        //cout<< endl;
        if(t.size() == k)sum = min(sum,chosen);
        }
    
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int  n,k;
    cin >> k >> n;
    set<int> t;
    vector<int> sol(n);
    map<int,vector<int>> date;
    int r = n;
    vector<pair<int,int>> mu;
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
    combi(n,sol,0,k,0,t,r,date);
    cout << r ;
}