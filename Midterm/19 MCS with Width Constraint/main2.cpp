#include<iostream>
#include <vector>
using namespace std;

vector<int> lib;
int w;
int range(int start , int stop){
    return lib[stop+1] - lib[start];
}

int maxsum(int start,int stop){
    if (start >= stop) return range(start,stop);
    int m = (start + stop) >> 1 ;

    int c1 = maxsum(start,m);
    int c2 = maxsum(m+1,stop);

    pair<int,int> l1 = {-100000,0}, r1 = {-100000,0}, l2 = {-100000,0}, r2 = {-100000,0};
    

    int c = 0;
    for (int i = max(start ,m - w + 2) ; i <= m ; i++ ,c++) l1 = max(l1,{range(i,m),m - i});
    for (int i = m + 1 ; i <= min(stop,m + 1 + w - 2 - l1.second) ; i++) r1 = max(r1,{range(m+1,i),i - (m + 1)});

    for (int i = m + 1 ; i <= min(stop,m + 1 + w - 2) ; i++) r2 = max(r2,{range(m+1,i),i - (m + 1)});
    for (int i = max(start ,m - w + 2 + r2.second) ; i <= m ; i++) l2 = max(l2,{range(i,m),i});    
    int c3 = l1.first + r1.first;
    int c4 = l2.first + r2.first;

    c3 = max(c3,c4);
    c2 = max(c2,c3);
    return max(c1,c2);
}


int main()
{
    int n,sum = 0, m;
    cin >> n >> w;
    lib.resize(n+1);
    
    for (int i = 1; i <= n ; i++){
        cin >> lib[i];
        max(m,lib[i]);
        lib[i] += lib[i-1];
    }
    cout << maxsum(0,n-1);
}