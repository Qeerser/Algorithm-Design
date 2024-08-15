#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N ,A, B;
vector<long long> path;

long long attack(int l , int r){
    long long cnt = upper_bound(path.begin(),path.end(),r) - lower_bound(path.begin(),path.end(),l);
    if (!cnt) return A;
    long long m = (l + r)/ 2;

    long long res = B * cnt * (r - l +1);
    if (l < r){
        res = min(res,attack(l, m) + attack(m + 1,r));
    }
    return res;
}

int main()
{   
    long long  p, k;
    cin >> p >> k >> A >> B;
    N = 1 << p;
    path.resize(k);
    for (auto &x : path) cin >> x;
    sort(path.begin(),path.end());
    cout << attack(1,N);
}