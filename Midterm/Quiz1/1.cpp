#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<int, vector<int>> lib;
    int ma = 0;
    int mi = -999;
    int mz = -999;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ma += x;
        
        if (lib.count(x) != 0)
        {
            auto &it = lib[x];
            it[2] += ma;
            it[1] = max(it[1] + it[2], x);
            it[0] = max(it[0], it[1]);
            it[2] = -ma;
            mz = max(mz, it[0]);
        }
        else
        {
            vector<int> y(3);
            lib[x] = y;
            lib[x][0] = -999;
            lib[x][2] = -ma + x;
        }
        mi = max(mi, x);
    }
    cout << max(mi, mz);
}