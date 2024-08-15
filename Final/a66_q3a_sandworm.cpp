#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int di[] = {1, -1, 0, 0}; 
const int dj[] = {0, 0, -1, 1};

int main()
{
    int r, c, k, count = 0;
    cin >> r >> c >> k;

    vector<vector<int>> N(r, vector<int>(c));
    vector<vector<int>> sb(r, vector<int>(c));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> N[i][j];
        }
    }
    queue<pair<int, int>> q;
    q.push({0, 0});

    while (q.size() != 0)
    {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int dx = x + di[i];
            int dy = y + dj[i];

            if (dx < 0 || dx >= r || dy < 0 || dy >= c || N[dx][dy] == 1)
                continue;
            count++;
            N[dx][dy] = 1;
            q.push({dx, dy});
        }
    }
    

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> sb[i][j];
        }
    }

    vector<pair<int,int>> w(k);
    for (int i = 0; i < k; i++) {
         int x ,y ;
        cin >> x >> y;
        w[i] = {x,y};
    }

    int count2 = 0;

    for (auto [x , y ] : w)
    {   
        x--,y--;
        if(N[x][y] == 0 ) continue;
        auto S = sb;
       int c2 = 0;
        queue<pair<int, int>> q1;
        q1.push({x, y});

        while (q1.size() != 0)
        {
            auto [x, y] = q1.front();
            q1.pop();
            for (int i = 0; i < 4; i++)
            {
                int dx = x + di[i];
                int dy = y + dj[i];

                if (dx < 0 || dx >= r || dy < 0 || dy >= c || S[dx][dy] == 1) continue;

                c2++;
                S[dx][dy] = 1;
                q1.push({dx, dy});
            }
        }
        count2 = max(count2 , c2);
    }

    cout << count + count2;
}