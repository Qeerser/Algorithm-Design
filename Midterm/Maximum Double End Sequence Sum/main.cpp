#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> S, I;

int solve(int l, int r)
{
    if (l == r) return I[l];
    int m = (l + r) / 2;

    int R1 = max(solve(l, m), solve(m + 1, r));

    map<int, int> L, R;
    for (int i = m; i >= l; i--)
        L[I[i]] = max(( L.find(I[i]) == L.end()?  -100000:L[I[i]]),  S[m] - S[i - 1]);

    for (int i = m + 1; i <= r; i++)
        R[I[i]] = max(( R.find(I[i]) == R.end()?  -100000:R[I[i]]),  S[i] - S[m]);
        
    for (auto &i : L) {
    auto it = R.find(i.first);
    if (it != R.end())R1 = max(R1,i.second + it->second);
    }
    
    return R1;
}

int main()
{
    int n;
    cin >> n;
    S.resize(n + 1), I.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> I[i];
        S[i] = I[i] + S[i - 1];
    }
    cout << solve(1, n);
}