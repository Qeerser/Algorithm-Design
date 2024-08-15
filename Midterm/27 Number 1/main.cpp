#include<iostream>
using namespace std;

long long count(int x){
    long long i , k = 0;
    for (i = 1 ; i <= x; i <<= 1 , k++);
    return (2 * 1 << (k - 1)) - 1;

}
int c = 0,n = 1 ,L ,R;
int cal(long long x){
    if (x <= 1) return x;
    return 2*cal(x/2)*2 + x%2;
}

void solve(long long l , long long r ,long long x ){
    if (r < L || R < l)return;
    //if(L <= l && l <= R) {c += cal(x); return;}
    if(l == r ){
        if(L <= l && l <= R) c+= x;
        return ;
    }

    int m = (l+ r + 1)/2 ;
    if(L <= m && m <= R) c+= x%2;
    if(r < m) {solve(l,m-1, x / 2);return;}
    if(l > m) {solve(m+1,r, x / 2); return;}

    solve(l,m - 1,x/2);
    solve(m + 1,r,x/2);
    return;
}

int main(){
    int p;
    cin >> p >> L >> R;
    solve(1,count(p),p);
    cout << c;

}
   