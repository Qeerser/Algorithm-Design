#include<iostream>
#include <vector>
using namespace std;

void permn_k(int n , vector<int> &sol,int len , int k , vector<pair<int,int>> mon, vector<int> &terrent,int w,int &less){
    if (len < k)
        {
            for (int i = 0 ; i < n; i++){
            sol[len] = i ;
            permn_k(n,sol,len+1,k,mon,terrent,w,less);
            }
        }
    else {
        int i = 0;
        for (auto &x  : sol){
            if (abs(terrent[i] - mon[x].first) <= w && mon[x].second > 0)mon[x].second--;
            i++;
         } 
        int sum = 0;
        for (auto [y,h] :  mon){
            sum += h;
        }
        less = min(sum,less);
       
    }
}
int main()
{
    int n,m,k,w;
    cin >> n >> m >> k >> w;
    vector<pair<int,int>> mon(m);
    vector<int> terrent(k);
    for (int i = 0; i < m;i++) cin >> mon[i].first;
    for (int i = 0; i < m;i++) cin >> mon[i].second;
    for (int i = 0; i < k;i++) cin >> terrent[i];
    int less = 1000;
     for (auto [y,h] :  mon){
            less += h;
     }
   
    vector<int> sol(k);
    
    permn_k(m,sol,0,k,mon,terrent,w,less);
    cout << less;
    return 0;
}