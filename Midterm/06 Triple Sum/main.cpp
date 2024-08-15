#include<iostream>
#include <vector>
#include <set>
using namespace std;

void perm_kn(int n , vector<int> &sol , int len , vector<bool> &used , int k, set<int> &sum , vector<int> &lib){
    if (len < k ) {
        for (int i = 0; i < n ; i++) {
            if (used[i] == false){
                used[i] = true;
                sol[len] = i;
                perm_kn(n,sol,len +1 , used, k,sum,lib);
                used[i] = false;
            }
        }
    }
    else {
        int a = 0;
        for (auto &x : sol){ a += lib[x];}
        sum.insert(a);
     }
}

int main()
{
    int n , m ;
    cin >> n >> m ;
    vector<int> lib(n);
    for (int i = 0 ; i < n ; i++) cin >> lib[i];
    vector<bool> used(n);
    vector<int> sol(3);
    set<int> sum;
    perm_kn(n, sol , 0 ,  used,3,sum , lib);

    for (int i = 0 ; i < m ; i ++){
        int target ;
        cin >> target; 
        if (sum.find(target) != sum.end()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}