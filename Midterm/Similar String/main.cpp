#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 1 << 17;
char a[MAXN];
char b[MAXN];

string c, d;

bool solve(int l, int r) {
    if (l + 1 == r) {
        return (a[l] == b[l] && a[r] == b[r]) || (a[l] == b[r] && a[r] == b[l]);
    }

    int m = (l + r) / 2;

    bool r1 = solve(l, m);
    bool r2;

    if (!r1) {
        reverse(a + l, a + r + 1);
        r1 = solve(l, m);
        r2 = solve(m + 1, r);
        reverse(a + l, a + r +1);
        return r1 and r2;
    }
    r2 = solve(m + 1, r);

    return r1 && r2;
}

int main() {
    cin >> c >> d;

    for (int i = 0; i < c.length(); i++) {
        a[i] = c[i];
        b[i] = d[i];
    }

    cout << (solve(0, c.length() - 1) ? "YES" : "NO") << endl;

    return 0;
}