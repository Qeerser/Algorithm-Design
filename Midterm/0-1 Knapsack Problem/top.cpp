#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> I, W;
vector<map<int, pair<int, vector<int>>>> dp;
pair<int, vector<int>> solve(int a, int b)
{
    if (a == -1 || b == 0)
    {
        vector<int> I ;
        return {0, I};
    }
    if (dp[a].count(b) != 0)
    {
        return dp[a][b];
    }

    if (b < W[a])
    {
        auto r = solve(a - 1, b);
        dp[a][b] = r;
        return r;
    }

    auto r1 = solve(a - 1, b);
    auto r2 = solve(a - 1, b - W[a]);
    r2.first += I[a];
    if (r1 < r2)
    {
        r1 = r2;
        r1.second.push_back(a);
    }

    dp[a][b] = r1;
    return r1;
}

int main()
{
    int n, w;
    cin >> n >> w;
    I.resize(n);
    W = I;
    dp.resize(n);
    for (int i = 0; i < n; i++)
        cin >> I[i];
    for (int i = 0; i < n; i++)
        cin >> W[i];
    auto r = solve(n - 1, w);
    cout << r.first << "\n";
    cout << r.second.size() << "\n";
    for (auto &i : r.second)
        cout << i + 1 << " ";
}