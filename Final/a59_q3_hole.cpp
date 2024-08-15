#include<iostream>
#include <vector>
#include<queue>
using namespace std;
const int di[] = {1, -1, 0, 0}; // Up, Down, Left, Right
const int dj[] = {0, 0, -1, 1};
struct Node
{
    int x , y , h;
};


int main()
{   
    int n , a ,b ; 
    cin >> n >> a >> b;
    a--,b--;
    vector<vector<int>> H(1000 ,vector<int>(1000 , -1));
    for (int i = 0 ; i < n ; i++){
        int x , y;
        cin >> x >> y;
        x-- ,y--;
        H[x][y] = 1;
    }
    int c = 9999999;
    queue<Node> q;
    q.push({a,b , 0});
    while (q.size() != 0){
        Node current = q.front();
        q.pop();
        if (current.x < 1 || current.x >= 999 || current.y < 1 || current.y >= 999 ) {
            c = min(c , current.h);
            continue;
        }
        for(int i = 0 ; i < 4 ; i++){
            int dx = di[i] + current.x;
            int dy = dj[i] + current.y;


            if (dx < 0 || dx >= 1000 || dy < 0 || dy >= 1000 ) continue;

            if(H[dx][dy] == -1) {
                H[dx][dy] = 0 ;
                q.push({dx , dy , current.h});
                }
            if(H[dx][dy] == 1) {
                H[dx][dy] = 0 ;
                q.push({dx , dy , current.h + 1});
                }

        }
    }
    
    cout << c;
}