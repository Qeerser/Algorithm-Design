#include<iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main()
{
    int n , t1 ,t2 ,t3;
    cin >> n >> t1 >> t2 >>t3;

    t1--,t2--,t3--;
    vector<vector<int>> G(n);
    vector<vector<int>> depths(3 , vector<int>(n, -1));

    for (int i = 0 ; i < n ; i++){
        int m , a;
        cin >> m;
        for (int j = 0 ; j < m ; j++){
            cin >> a;
            a--;
            G[i].push_back(a);
        }
    }
    
    int t[] = {t1 ,t2 ,t3};
    for (int i = 0 ; i < 3; i++){
        auto &depth = depths[i];
        auto &start = t[i];
        queue<int> q; 
        q.push(start);
        depth[start] = 0;
        while(q.size() != 0){
            int u = q.front();
            q.pop();

            for (auto b : G[u]){
                if(depth[b] == -1){
                    depth[b] = depth[u] + 1;
                    q.push(b);
                } 
            }
        }
    }

    int o = 9999999;
    for (int i = 0 ; i < n ; i++){
        if (depths[0][i] == -1 || depths[1][i] == -1 || depths[2][i]== -1 ) continue;
        int m = max(depths[0][i],depths[1][i]);
        m = max(m,depths[2][i]);
        o = min(o,m);
    }
    cout << o;
}   