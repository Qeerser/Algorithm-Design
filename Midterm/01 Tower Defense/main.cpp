#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, k, w;
    cin >> n >> m >> k >> w;
    vector<pair<int,int>> position;
    vector<int> health;
    vector<int> turrent;
    for (int i = 0 ; i <  m ; i++)
    {
        int p ;
        cin >> p;
        position.push_back(make_pair(p,i));
    }
    sort(position.begin(),position.end());

    for (int i = 0 ; i <  m ; i++) {
        int x ;
        cin >> x ;
        health.push_back(x);
    }

    for (int i = 0 ; i <  k ; i++) {
        int x ;
        cin >> x ;
        turrent.push_back(x);
    }

    sort(turrent.begin(), turrent.end());
    for (auto t : turrent)
    {
        for (auto y :position)
        {
            if (y.first >= t-w && y.first <= t+w && health[y.second] > 0 )
            {
                --health[y.second];
                break;
            }
        }

    }
    int x;
    for (int h : health) x += h;
    cout << x;
}
