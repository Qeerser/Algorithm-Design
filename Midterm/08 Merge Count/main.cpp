#include<iostream>
#include<vector>
using namespace std;

vector<int> lib;
vector<int> tmb;

int k, n; 
void rmsort(int start, int stop , int &a){
    if (start == stop - 1) return;
    int m = (start + stop) >> 1 ;
   
    int bi = start;
    int ci = m;
    int z = (start + stop) % 2;
    for (int i = start ; i < m ; i++) tmb[ci++] = lib[i];
    for (int i = m ; i < stop-z; i++) tmb[bi++] = lib[i];
    for (int i = start ; i < stop - z ; i++)lib[i] = tmb[i];
    a += 2;
    if (a == k )return;
    rmsort(start,m,a);
    if (a == k )return;
    rmsort(m,stop,a);

}

int main()
{   
    cin >> n >> k;
    lib.resize(n);
    tmb.resize(n);
    for (int i = 1 ; i <= n ; i++) lib[i-1] = i;
    int a = 1;
    if (k % 2 == 0 || k > n*2) {cout << -1;return 0;}
    else if (k != 1) rmsort(0,n,a); 

    for(int i : lib) cout << i << " ";
}