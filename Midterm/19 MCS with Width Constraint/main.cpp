#include<iostream>
using namespace std;

int main()
{   
    int n ,r;
    cin >> n >> r;
    int C[n+1];
    C[0] = 0;
    for (int i = 1; i <= n ; i++){
        cin >> C[i];
        C[i] += C[i-1];
    }
    int m = C[1] ;
      for (int p = 1; p <= n ; p++){
          for (int q = p; q <= min(p+r - 1, n) ; q++){
                m = max(m,C[q] - C[p-1]);
      }
    }
    cout << m;
}