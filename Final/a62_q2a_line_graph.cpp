#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool solve(int n, int parent, vector<set<int>> &M, vector<bool> &visited)
{
    if (M[n].size() > 2 ) return true;
    visited[n] = true;
    bool c = false;
    for (auto b : M[n])
    {
        if (visited[b] == false)
        {
            c = c || solve(b, n, M, visited);
        }
        else if (b != parent)
            return true;
    }
    return c;
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<set<int>> M(v);
    vector<bool> visited(v);

    for (int j = 0; j < e; j++)
    {
        int a, b;
        cin >> a >> b;
        M[a].insert(b);
        M[b].insert(a);
    }
    int count = 0;
    for (int x = 0; x < v; x++)
    {
        if (visited[x] == true) continue;
        if (!solve(x, -1, M, visited)) count++;
    }
    cout << count << "\n";
}