#include<iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<set<int>> G(n);
    vector<int> pre(n);
    vector<int> order;
    for (int i = 0 ; i < n ; i++){
        int m , a;
        cin >> m;
        pre[i] = m;
        for (int j = 0 ; j < m ; j++){
            cin >> a;
            G[a].insert(i);
        }
    }
    
    queue<int> q; 
    for (int i = 0 ; i < n ; i++) if (pre[i] == 0) q.push(i);

    while(q.size() != 0){
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (auto b : G[u]){
            pre[b]--;
            if(pre[b] == 0) q.push(b);
        }
    }

    for (int i : order) cout << i << " ";
}