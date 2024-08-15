#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int R, C, a2, b2;
vector<vector<int>> table;
vector<vector<int>> dp;
vector<vector<bool>> pass;
vector<vector<bool>> cass;

int solve(int x, int y) {
    pass[x][y] = true;
    if (x == a2 && y == b2) return table[a2][b2];
    if (cass[x][y] == true) return dp[x][y];

    vector<pair<int, int>> l;
    if (x % 2 == 1)
        l = {{x - 1, y - 1}, {x - 1, y}, {x + 1, y - 1}, {x + 1, y}, {x, y - 1}, {x, y + 1}};
    else
        l = {{x - 1, y}, {x - 1, y + 1}, {x + 1, y}, {x + 1, y + 1}, {x, y - 1}, {x, y + 1}};

    int m = numeric_limits<int>::max();
    for (auto [i, j] : l) {
        if (i < 1 || j < 1 || i > R || j > C) continue;
        if (!pass[i][j]) m = min(m, solve(i, j));
    }
    dp[x][y] = table[x][y] + m;
    cass[x][y] = true;
    return dp[x][y];
}

int main() {
    int a1, b1;
    cin >> R >> C >> a1 >> b1 >> a2 >> b2;
    table.resize(R + 1, vector<int>(C + 1));
    dp.resize(R + 1, vector<int>(C + 1));
    pass.resize(R + 1, vector<bool>(C + 1));
    cass.resize(R + 1, vector<bool>(C + 1));

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> table[i][j];
        }
    }

    cout << solve(a1, b1) << endl;
}