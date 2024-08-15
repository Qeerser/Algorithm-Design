#include<iostream>
#include <vector>
using namespace std;

int DFS(int n , vector<vector<int>> &G ,vector<int> &B  ,vector<bool> &visited){
    visited[n] = true;
    int damage = B[n];
    for (auto j : G[n]){
        if (visited[j] == false){
            visited[j] = true;
            damage += DFS(j , G , B , visited);
        }
    }
    return damage;
}

int main()
{
    int n , m , k;
    cin >> n >> m >> k;
    vector<int> B(n);
    vector<vector<int>> G(n);
    vector<int> fire(k);
    vector<bool> visited(n);
    for (int i = 0 ; i < n ; i++) cin >> B[i];
    for (int i = 0 ; i < k ; i++) cin >> fire[i];
    for (int i = 0 ; i < m ; i++) {
        int a , b;
        cin >> a >> b;
        G[a].push_back(b);
    }
     int count = 0 ;
    for(auto j : B) count += j;

    for (auto i : fire ) {
        if (visited[i] == false) count -= DFS(i , G , B ,visited);
        cout << count << " ";
    }
}