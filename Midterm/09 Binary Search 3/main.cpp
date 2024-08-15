#include<iostream>
#include<vector>
using namespace std;
vector<int> L;
int n,m;
int bs(int start,int stop , int x){
    if (start >= stop) return ((x >= L[start] ) ? start:-1);

    int m = (start + stop ) >> 1;
    int r;
    if(L[m] == x && m!= n-1 && L[m+1] != x) return m;
    if (L[m] <= x) r =  bs(m+1,stop ,x);
    else r = bs(start,m,x);
    int z = m+1;
    while (r == -1 && z != 0){
        r = bs(z-1,z-1,x);
        z--;
    }

    return r;
 
  
}

int main()
{
    cin >> n >>m;
    L.resize(n);
    for (int i = 0 ; i < n; i++) cin >> L[i];

    for(int i = 0 ; i < m; i++){
        int x;
        cin >> x;
        cout << bs(0,n-1,x) << "\n";
    }
    return 0;
}