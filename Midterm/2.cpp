#include<iostream>
#include<vector>
#include <set>
using namespace std;

vector<set<int>> M;
vector<bool> P;
set<int> F;
bool solve(int n ,int b){
    P[n] = true;
    bool check = false;
    if (M[n].size() > 2 ) check = true ;
    for (auto &i : M[n]){
        if(i != n && F.find(i) != F.end() && b != i) check = true;
        if(P[i] && M[i].size() > 2 ) check =  true;
        if(P[i]) continue;
        F.insert(i);
        if (solve(i , n)) check = true;
    }
    return false || check;
}

int main()
{
        int v , e , count = 0;
        cin >> v >> e;
        vector<set<int>> m(v);
        M = m;
        vector<bool> p(v);
        P = p;
        set<int> f;
         F = f;
        bool have = false;
        for (int j = 0 ; j < e; j++){
            int a , b;
            cin >> a >> b;
            M[a].insert(b);
            M[b].insert(a);
        }
        
        for (int x = 0 ;x < v ; x++){
            if (P[x]) continue;
            if(F.find(x) != F.end()) continue;
            if (!solve(x , -1)) {count++;
                cout << x << "\n";
            }
        }
        cout << count;
    
    
}