#include <iostream>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    int L[N];
    for (int i = 0; i < N; i++) cin >> L[i];

    for (int i = 0; i < M; i++)
    {
        int x;
        cin >> x;

        int l = 0,r = N-1 ,ans = -1;
        while (l <= r){
            int m = (l + r) / 2;

            if(L[m] <= x) l = m + 1, ans = L[m];
            else r = m - 1;
        }
        cout << ans << "\n";
    }
    return 0;
}