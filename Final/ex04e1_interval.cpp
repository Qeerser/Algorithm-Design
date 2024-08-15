#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N , c = 0 , S = -1;
    cin >> N;
    vector<pair<int,int>> Data(N);
    for (int i = 0 ; i < N; i++) cin >> Data[i].second;
    for (int i = 0 ; i < N; i++) cin >> Data[i].first;
    sort(Data.begin(), Data.end());

    for (auto [Stop , Start] : Data){
        if(Start >= S) {
            c++;
            S = Stop;
        }
    }
    cout << c;
}