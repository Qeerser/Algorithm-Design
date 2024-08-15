#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int y[300];
bool ct(int l , int r ){
    if (l + 1 == r) return !y[l] and  y[r];

    int m = (l + r) >> 1 ;
    if(ct(m + 1, r) == false) return false;
    if(ct(l,m) == true) return true;

    reverse(y + l , y + m + 1);
    bool t = ct(l,m);
    reverse(y + l , y + m + 1);
    return t;

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n , k ;
    cin >> n >> k;
    k = 1 << k;
    while (n--){
        for(int i = 0; i < k; i++)cin >> y[i];
        cout << (ct(0,k-1) ? "yes" : "no") << "\n";
    }
    return 0;
}