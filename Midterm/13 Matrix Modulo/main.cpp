#include<iostream>
#include <vector>
using namespace std;

int K;

vector<int> mod(vector<int> &a){
    for (int &i: a) i%=K;
    return a;
}

vector<int> m(vector<int> a, vector<int> b){
    vector<int> x(4);
    mod(a);mod(b);
    x[0] = a[0]*b[0] +a[1]*b[2]; 
    x[1] = a[0]*b[1] +a[1]*b[3];
    x[2] = a[2]*b[0] +a[3]*b[2];
    x[3] = a[2]*b[1] +a[3]*b[3];
    return mod(x);
}


vector<int> mss(vector<int> x,int N, int K){
    if (N == 1) return mod(x);
    vector<int> r = mss(x,N / 2,K);
    r  = m(r,r);
    if (N % 2 == 0) return r;
    return m(r,mod(x));
}

int main()
{
    int N;
    cin >> N >> K;
    vector<int> x(4);
    for (int i = 0 ; i < 4 ; i++)cin >> x[i];
    x = mss(x,N,K);
    for(int i : x)cout << i<< " ";
}