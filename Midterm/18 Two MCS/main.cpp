#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n ;
    cin >> n;
    vector<int> S(n + 1);
    for(int i = 1 ; i <= n; i++) {
        cin >> S[i];
        S[i] += S[i - 1];
    }

    int a, b, mx = S[1];
    for(int p = 1 ; p <= n ; p++){
        for(int q = p ; q <= n ; q++){
            a = S[q] - S[p - 1];
            for(int x = q + 1 ; x <= n ; x++){
                 for(int y = x ; y <= n ; y++){
                b = S[y] - S[x - 1];
                mx = max(max(mx,a),max(b,a+b));
                 }
            }
        }

    }
    cout << mx;

}