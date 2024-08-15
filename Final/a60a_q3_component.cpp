#include<iostream>
#include <vector>
using namespace std;

void DFS(int n , vector<vector<int>> &G ,vector<bool> &visited){
    visited[n] = true;
    for (auto j : G[n]){
        if (visited[j] == false){
            visited[j] = true;
            DFS(j , G , visited);
        }
}
}

int main()
{
    int  v , e , count = 0;
    cin >> v >> e;
    vector<vector<int>> G(v);
    vector<bool> visited(v);
    for (int i = 0 ; i < e ; i++) {
        int a , b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 0 ; i < v ; i++) {
        if (visited[i] == false) {
            count++;
            DFS(i , G  ,visited);
        }
    }
    cout << count ;
}