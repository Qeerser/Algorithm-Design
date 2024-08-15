#include<iostream>
using namespace std;

int mss(int n,int m, int k){
    if (m == 1) return n %k;
    int r = mss(n,m/2,k);
    r  = (r * r)%k;
    if (m % 2 == 0) return r;
    return (r *(n%k)) % k;
}

int main()
{
    int n,m, k;
    cin >> n >> m >> k;
    cout << mss(n,m,k);
}