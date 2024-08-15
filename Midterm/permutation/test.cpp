#include<iostream>
#include <vector>
using namespace std;

void perm_k(int n,vector<int> &sol ,int len , vector<bool> &used , int k){
    if (len < k){
        for (int i = 0; i < n ; i++){
            if(!used[i]){
            used[i] = false;
            sol[len] = i;
            perm_k(n,sol,len+1,used,k);
            used[i] = false;
            }
           
        }
    }else {
        for (auto &x : sol)cout << x;
        cout << endl;
    }
    }

int main()
{
    int n = 3;
    int k = 2;
    vector<int> sol(k);
    vector<bool> used(n);
    perm_k(n,sol,0,used,k);
    return 0;
}