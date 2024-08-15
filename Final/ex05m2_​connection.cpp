#include<iostream>
#include<vector>
#include <queue>

using namespace std;

void DFS(int a , vector<int> &depth,vector<vector<int>> &G){
	queue<int> q;
	q.push(a);
	 depth[a] = 0;
	 while (q.size() != 0){
		int u = q.front();
		q.pop();
		for (auto i : G[u]){
			if (depth[i] == -1){
				depth[i] = depth[u] + 1;
				q.push(i);
			}
    }}
}

int main()
{
    int n , e , k;
    cin >> n >> e >> k ;
    vector<vector<int>> G(n);
    for (int i = 0 ; i < e ; i++){
        int a ,b ;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    pair<int ,int> o  = {0,0};
     for (int i = 0 ; i < n ; i++){
        vector<int> depth(n , -1);
        int count = 0;
       
        DFS(i, depth , G);
        for (auto j : depth) if (j>= 0 && j <= k) count++;
		
        o = max(o,{count , i});
     }
    cout << o.first ;
}