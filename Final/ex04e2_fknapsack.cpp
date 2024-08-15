#include <iomanip>
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    double W , V = 0;
    int N;
    cin >> W >> N;
    vector<pair<double,double>> Data(N);
    vector<pair<double,int>> sortl(N);
    for (int i = 0 ; i < N ; i++)
    {
        cin >> Data[i].second;
    }
    for (int i = 0 ; i < N ; i++)
    {
        cin >> Data[i].first;
        sortl[i].first = Data[i].second / Data[i].first ;
        sortl[i].second = i;
    }
    sort(sortl.rbegin() , sortl.rend());
    

    for (auto [w,i] : sortl){
        if (W > Data[i].first){
            V += Data[i].second;
            W -= Data[i].first;
        }
        else {
            V += w * W;
            break;
        }
    }
     cout << setprecision(4) << fixed;
    cout << V << endl;
    return 0;
}