#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void perm_kn(int n , vector<int> &sol , int len , vector<bool> &used,vector<int>&a,vector<int>&b){
    if (len < n ) {
        for (int i = 0; i < n ; i++) {
            
            auto idx = find(b.begin(),b.end(),i);
            if(idx != b.end()){
                int z = idx - b.begin();
                if(!used[a[z]]) continue;
            }

            if (used[i] == false){
                used[i] = true;
                sol[len] = i;
                perm_kn(n,sol,len +1 , used ,a,b);
                used[i] = false;
            }
            
        }
    }
    else {
        for (auto &x : sol) cout << x << " ";
        cout <<endl ; 
     }
}
 
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> b(m);
    for (int i = 0 ; i < m ; i++){
        cin >> a[i] >> b[i];
    }

    vector<int> sol(n);
    vector<bool> used(n);
    perm_kn(n,sol,0,used,a,b);
    return 0;
}