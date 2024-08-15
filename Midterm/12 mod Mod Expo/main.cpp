#include<iostream>
using namespace std;

int mss(int X,int N, int K){
    if (N == 0) return 1;
    int r = mss(X,N / 2,K);
    r  = (r * r) % K;
    if (N % 2 == 0) return r;
    return (r *(X % K)) % K;
}

int main()
{
    int X,N,K;
    cin >> X >> N >> K;
    cout << mss(X,N,K);
}