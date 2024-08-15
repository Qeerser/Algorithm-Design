#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

const int di[] = {1, -1, 0, 0}; // Up, Down, Left, Right
const int dj[] = {0, 0, -1, 1};

struct Node {
  int i, j, w;
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> grid(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> grid[i];
  }

  queue<Node> q;
  q.push({1, 1, 0});  // Push start coordinate

  vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));

  while (!q.empty()) {
    Node current = q.front();
    q.pop();

    int i = current.i, j = current.j, w = current.w;

    if (visited[i][j]) {
      continue; // Already visited
    }

    visited[i][j] = true;

    if (i == n && j == m) {
      cout << w << endl;
      return 0;
    }

    for (int k = 0; k < 4; ++k) {
      int ni = i + di[k];
      int nj = j + dj[k];

      if (ni < 1 || ni > n || nj < 1 || nj > m || grid[ni][nj - 1] == '#') {
        continue; // Out of bounds or obstacle
      }

      q.push({ni, nj, w + 1});
    }
  }

  cout << "-1" << endl; // No path found
  return 0;
}
