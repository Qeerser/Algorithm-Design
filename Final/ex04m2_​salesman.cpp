#include<iostream>
#include <vector>
using namespace std;


vector<int> dist;
int M ;
int dis(int a , int b){
    if (a > b) swap(a,b);
    return min((dist[b] - dist[a]),dist[M] - dist[b] + dist[a]);
}

int main()
{
    int N ;
    cin >> N >> M;
    vector<int> Path(M + 1);
    dist.resize(M + 1);
    vector<pair<int,int>> Portal(N);
    for (int i = 0 ; i < M ; i++) cin >> Path[i];
    Path[M] = Path[0];
    for (int i = 1 ; i <= M ; i++) {
        cin >> dist[i];
        dist[i] += dist[i - 1];
    }
    for (int i = 0 ; i < N ; i++) cin >> Portal[i].first >> Portal[i].second;
    
    for(auto [pi , po] : Portal){
        int s = Path[0];
        int c = 0;
        for (int i = 1 ; i <= M ; i++){
            int d = dis(s , Path[i]);
            d = min (d,dis(s , pi) + dis(po, Path[i]));
            d = min (d,dis(s , po) + dis(pi, Path[i]));
            c += d;
           
            s = Path[i];
        }
        cout << c << "\n";
    }


    return 0;
}