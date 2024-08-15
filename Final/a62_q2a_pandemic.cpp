#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int di[] = {1 , -1 , 0 , 0};
const int dj[] = {0 , 0 , 1 , -1};

struct Node
{
    int x , y , d;
};

int main()
{
    int r , c, t , count = 0;
    cin >> r >> c >>t;
    queue<Node> q;
    vector<vector<int>> Map(r , vector<int>(c));

    for (int i = 0 ; i < r ; i++){
        for (int j = 0 ; j < c ; j++){
            cin >> Map[i][j];
            if(Map[i][j] == 1) q.push({ i , j , 0}) ;
        }
    }
    
    while (q.size() != 0){
        Node current = q.front();
        q.pop();
        int x = current.x ,  y = current.y ,d = current.d;
        count++;
        if (d == t) continue;
        for (int i = 0 ; i < 4 ; i++){
            int dx = x + di[i];
            int dy = y + dj[i];

            if (dx < 0 || dy < 0 || dx >= r || dy >= c || Map[dx][dy] == 2)continue;
            if (Map[dx][dy] == 0) {
                Map[dx][dy] = 1;
                q.push({dx , dy , d + 1});
            }

        }
    }

    cout << count;
}