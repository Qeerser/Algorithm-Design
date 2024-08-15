#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int di[] = {1, -1, 0, 0};
const int dj[] = {0, 0, -1, 1};

int main() {
  cin.tie(0)->ios::sync_with_stdio(false);

  int r, c, k;
  cin >> r >> c >> k;

  // Validate input values
  if (r < 1 || r > 700 || c < 1 || c > 700 || k < 0 || k > 100000) {
    cerr << "Invalid input values. R, C must be between 1 and 700, and K must be between 0 and 100,000." << endl;
    return 1; // Exit with error code
  }

  vector<vector<int>> N(r, vector<int>(c));
  vector<vector<int>> originalN(r, vector<int>(c)); // Store initial N grid
  vector<vector<int>> S(r, vector<int>(c));

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> originalN[i][j];
    }
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> S[i][j];
    }
  }

  vector<pair<int, int>> w(k);
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    w[i] = {x, y};
  }

  int count = 0; // Count of reachable cells from starting point (N, 1, 1)
  int count2 = 0; // Count of reachable cells for each wormhole traversal

  // Handle starting point (N, 1, 1)
  queue<pair<int, int>> q;
  q.push({0, 0});

  while (q.size() != 0) {
    auto [x, y] = q.front();
    q.pop();

    N[x][y] = 1; // Mark as visited

    for (int i = 0; i < 4; i++) {
      int dx = x + di[i];
      int dy = y + dj[i];

      if (dx < 0 || dx >= r || dy < 0 || dy >= c || N[dx][dy] == 1) continue;

      count++;
      N[dx][dy] = 1;
      q.push({dx, dy});
    }
  }

  for (auto [x, y] : w) {
    x--, y--; // Convert coordinates to 1-based indexing

    if (N[x][y] == 0) continue; // Skip if not a valid starting point

    S = originalN; // Reset S grid to original state

    int c2 = 0; // Count of reachable cells for this wormhole

    queue<pair<int, int>> q1;
    q1.push({x, y}); // Start BFS from wormhole position

    while (q1.size() != 0) {
      auto [x, y] = q1.front();
      q1.pop();

      N[x][y] = 1; // Mark as visited in N grid
      S[x][y] = 1; // Mark as visited in S grid

      for (int i = 0; i < 4; i++) {
        int dx = x + di[i];
        int dy = y + dj[i];

        if (dx < 0 || dx >= r || dy < 0 || dy >= c || S[dx][dy] == 1) continue;

        c2++;
        S[dx][dy] = 1;
        q1.push({dx, dy});
      }
    }

    count2 = max(count2, c2);
  }

  cout << count  << endl;

  return 0;
}
