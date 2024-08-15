#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool solve(int n, int parent , vector<set<int>> &M , vector<bool> &visited) {
    visited[n] = true;
    bool c = false;
    for(auto b : M[n]){
        if (visited[b] == false){
            c = c || solve(b, n , M , visited);
        }
        else if (b != parent) return true;
        }
    return c;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int v, e;
        cin >> v >> e;

        vector<set<int>> M(v);
        vector<bool> visited(v);

        bool have = false;
        for (int j = 0; j < e; j++) {
            int a, b;
            cin >> a >> b;
            M[a].insert(b);
            M[b].insert(a);
        }
        for (int x = 0; x < v; x++) {
            if (visited[x] == true) continue;
            have = solve(x, -1 , M , visited);
            if (have) break;
        }
        cout << (have ? "YES" : "NO") << "\n";
    }
}