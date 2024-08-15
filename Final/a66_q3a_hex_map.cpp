#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int int_max = 99999999;
const int dx[6]  = {0, 0, -1, -1, 1, 1};
const int dy1[6] = {1, -1, -1, 0, -1, 0};
const int dy2[6] = {1, -1, 0, 1, 0, 1};

struct Node
{
    int x, y;
};

int main()
{
    int R, C, x1, y1, x2, y2;
    cin >> R >> C >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;
    vector<vector<int>> dist(C, vector<int>(R, int_max));
    vector<vector<int>> w(C, vector<int>(R));

    vector<pair<Node, Node>> G;
    
    
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> w[j][i];
                  
        }
    }
    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < R; j++)
        {
            
            for (int k = 0 ; k < 6 ; k++){
                int di = i + dx[k];
                int dj = j + ((i % 2 == 0)?dy1[k]:dy2[k]);

                if(di < 0 || di >= C || dj < 0 || dj >= R)continue;
                G.push_back({{i,j} ,{di,dj}});
            }
             
        }
    }

    dist[x1][y1] = w[x1][y1];
    for (int i = 0; i < R * C; i++)
    {
        for (auto [a, b] : G)
        {
            if (dist[b.x][b.y] > dist[a.x][a.y] + w[b.x][b.y])
                dist[b.x][b.y] = dist[a.x][a.y] + w[b.x][b.y];
                //if(dist[b.x][b.y] < 0) cout << "error" <<a.x << a.y << " " << b.x<<b.y;
        }
    }
    
    cout <<  dist[x2][y2]  ; 
}