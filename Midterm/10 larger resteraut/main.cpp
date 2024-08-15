#include<iostream>
using namespace std;
typedef long long ll;
int chef[1000];
int  n , a;

ll st(ll start , ll stop ,ll x){
    if (start == stop) return start;

    ll sum = 0,m = (start + stop) >> 1;
    for(int i = 0 ; i < n ; i++) sum += m /chef[i];

    if(sum >= x) return st(start,m,x);
    else return st(m+1,stop,x);
}
int main()
{
    cin >> n >> a;
    for(int i = 0 ; i < n ; i++) cin >> chef[i];
    for(int i = 0 ; i < a ; i++){
        ll x;
        cin >> x;
        cout << st(0,1e12,x-n) << "\n";
    }
    return 0;
}