#include<iostream>
#include<map>
using namespace std;

int N ,A, B;
map<int,int> path;

pair<long long,long long> attack(int l , int r){
    if (l == r){
        long long d, k = 0;
        if(path.count(l)) {
            k = path[l];
            d = B*k;
            }
        else d = A;
        return {d,k};
    }
    int m = (l + r) / 2;

    auto [r1,k1] = attack(l, m);
    auto [r2,k2] = attack(m + 1,r);

    long long c = (k1 + k2) ? B * (k1 + k2)*(r - l + 1):A;

    return {min(c,r1 + r2),k1 + k2};
}

int main()
{   
    int  p, k;
    cin >> p >> k >> A >> B;
    N = 1 << p;
    for (int i = 0 ; i < k ; i++) {
        int x;
        cin >> x;
        path[x-1]++;
    }
    cout << attack(0,N-1).first;
}