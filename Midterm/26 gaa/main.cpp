#include<iostream>
using namespace std;

long long len(long long k){
    if ( k == 0 )return 3;
    return 2*len(k-1) + k + 3;
}

char ans(long long y){
    if(y <=3){
        return (y == 1 ? 'g' : 'a');
    }
    long long k = 0;
    long long x = 0;
    while (x < y) x = 2*x + 3 + k++;
    k--;
    long long m = (x - 3 - k)/2 + 1;
    if(y == m) return 'g';
    y -= m + k + 2;
    if (y <= 0) return 'a';

    return ans(y);
}

int main()
{
    int a;
    cin >> a;
    cout <<  ans(a);
}