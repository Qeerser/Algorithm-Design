#include<iostream>
#include<vector>
#include <set>
using namespace std;

vector<set<int>> M;
vector<bool> P;
set<int> F;
bool solve(int n ,int b){
    P[n] = true;
    for (auto &i : M[n]){
        if(i != n && F.find(i) != F.end() && b != i) return true;
        if(P[i]) continue;
        F.insert(i);
        if (solve(i , n)) return true;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0 ; i < t ; i++){
        int v , e;
        cin >> v >> e;
        vector<set<int>> m(v);
        M = m;
        vector<bool> p(v);
        P = p;
        set<int> f;
        bool have = false;
        for (int j = 0 ; j < e; j++){
            int a , b;
            cin >> a >> b;
            M[a].insert(b);
            M[b].insert(a);
        }
        
        for (int x = 0 ;x < v ; x++){
            if(F.find(x) != F.end()) continue;
            F = f;
            have = solve(x , -1);
            if (have) break;
        }

        cout << (have ? "YES" : "NO") << "\n";
    }
    
}