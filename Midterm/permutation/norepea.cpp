#include<iostream>
#include<vector>
using namespace std;

void perm_kn(int n , vector<int> &sol , int len , vector<bool> &used , int k){
    if (len < k ) {
        for (int i = 1; i <= n ; i++) {
            
            sol[len] = i;
            perm_kn(n,sol,len +1 , used, k);
            // if (used[i] == false){
            //     used[i] = true;
            //     sol[len] = i;
            //     perm_kn(n,sol,len +1 , used, k);
            //     used[i] = false;
            // }
            
        }
    }
    else {
        for (auto &x : sol) cout << x;
        cout <<endl ; 
     }
}
 
int main()
{
    vector<int> sol(2);
    vector<bool> used(2);
    perm_kn(4,sol,0,used,2);
}