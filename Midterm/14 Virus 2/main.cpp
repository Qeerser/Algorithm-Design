#include<iostream>
#include<vector>
using namespace std;

int ct( vector<int>&y, int l , int r , bool &t){
    if (l == r) return y[l];
    int m = (l + r) >> 1 ;

    int r1 = ct(y,l , m,t);
    int r2 = ct(y,m + 1 , r,t);

    if(abs(r1-r2) > 1) t = false;
    return r1 + r2;

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n , k ;
    cin >> n >> k;
    k = 1 << k;
    vector<int> y(k);
    while (n--){
        bool t = true;
        for(int i = 0; i < k; i++)cin >> y[i];
            
        ct(y,0,k-1,t);
        cout << (t ? "yes" : "no") << "\n";
    }
    return 0;
}