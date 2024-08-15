#include<iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int n , e, k ,count = 0;
    cin >> n >> e >> k;
    vector<vector<int>> G(n + 1);
    vector<int> depth(n + 1 , -1);
    depth[0] = 0;

    for(int i = 0 ; i < e ; i++){
        int a, b ; 
        cin >> a >> b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);

    }
    queue<int> q;
    q.push(0);
    while( q.size() > 0){
        int u = q.front();
        q.pop();
        if(depth[u] == k) {
            
            count++;
            continue;
        } 
        for(auto a : G[u]){
            if(depth[a] == -1){
                depth[a] = 1 + depth[u];
                q.push(a);
            }
        }
    }

    cout << count;
}