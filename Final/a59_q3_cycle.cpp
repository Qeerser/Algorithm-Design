#include<iostream>
#include <vector>
using namespace std;

void DFS(int a, int parent, vector<vector<int>> &G ,vector<bool> &visited,vector<int> &from , vector<pair<int,int>> &stop){
    visited[a] = true;
    for(auto b : G[a]){
        if(visited[b] == false){
            visited[b] = true;
            from[b] = a;
            DFS(b , a, G, visited , from , stop);
        }
        else if (b != parent) {stop.push_back({a,b});return ;}
    }
}

int main()
{
    int n , count = 1;
    cin >> n ;

    vector<vector<int>> G(n);
    vector<int> from(n , -1);
    vector<bool> visited(n);
    vector<pair<int,int>> s;
    for (int i = 0 ; i < n ; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    DFS(0 , -1, G, visited , from , s);
    int stop = s[0].first;
    while (stop != s[0].second){
        count++;
        stop = from[stop];
    }
    cout << count;
}