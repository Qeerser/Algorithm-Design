#include<iostream>
#include <algorithm>
using namespace std;

int B[100000], k, n , a = 1;

void rmsort(int l, int r){
    if (l == r - 1) return;
    int m = (l + r) >> 1 ;
    swap(B[m],B[m-1]);
    a += 2;
    if (a != k )rmsort(l,m);
    if (a != k )rmsort(m,r);
}

int main()
{   
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++) B[i-1] = i;

    if (k % 2 == 0 || k > n*2) {cout << -1;return 0;}
    else if (k != 1) rmsort(0,n); 

    for(int i = 0 ; i < n ; i++) cout << B[i] << " ";
}