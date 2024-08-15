#include<iostream>

#include <vector>
using namespace std;
vector<vector<int>> table;
int count = 0;
vector<bool> pass;
bool solve(int idx , int parent){
    pass[idx] = true;
    if (table[idx].size() > 2) return false;
    if (table[idx].size() == 0)return true;
    if (table[idx].size() == 1 && pass[table[idx].front()])return true;
    for (int i : table[idx]){
        if (pass[i]) continue;
        return solve(i,idx);
    }
    return false;
}

int main()
{
    int v , e ;
    cin >> v >> e;
    table.resize(v);
    pass.resize(v);
    for (int i = 0 ; i < e ; i++){
        int a, b;
        cin >> a >> b;
        table[a].push_back(b);
        table[b].push_back(a);
    }

     for (int i = 0 ; i < v ; i++){
        if (pass[i]) continue;
        if (solve(i,i)) count ++;
    }

    cout << count;
}