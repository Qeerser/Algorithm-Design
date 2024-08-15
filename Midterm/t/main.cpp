#include<iostream>
#include <vector>
using namespace std;

vector<int> lib;
int range(int start , int stop){
    return lib[stop+1] - lib[start];
}

int maxsum(int start,int stop){
    if (start >= stop) return range(start,stop);
    int m = (start + stop) >> 1 ;

    int r1 = maxsum(start,m);
    int r2 = maxsum(m+1,stop);

    int l = -100000;
    int r = -100000;
    for (int i = start ; i <= m ; i++)l = max(l,range(i,m));
    for (int i = m+1 ; i <= stop ; i++)r = max(r,range(m+1,i));
    int r3 = l + r;

    return max(r1,max(r2,r3));
}



int main()
{
    int n,sum = 0, m;
    cin >> n;
    lib.resize(n+1);

    for (int i = 1; i <= n ; i++){
        cin >> lib[i];
        max(m,lib[i]);
        lib[i] += lib[i-1];
    }
    int a = maxsum(0,n-1);
    pair<int,int> l1 = {-100000,0};
    int r1 = -100000;
    for (int i = 0 ; i <= n-1 ; i++) l1 = max(l1,{range(0,i),i});
    for (int i = l1.second + 1  ; i <= n-1 ; i++)r1 = max(r1,range(i,n-1));

    pair<int,int> r2 = {-100000,0};
    int l2 = -100000;

    for (int i = 0  ; i <= n-1 ; i++)r2 = max(r2,{range(i,n-1),i});
    for (int i = 0 ; i <= r2.second-1 ; i++) l2 = max(l2,range(0,i));

    int b = l1.first + r1;
    int c = r2.first + l2;
    cout << max(a,max(b,c));

}
