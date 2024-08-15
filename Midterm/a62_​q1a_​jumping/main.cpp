#include<iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> S(n);
    for (int i = 0 ; i < n ; i++ ) cin >> S[i];
    S[n - 2] += max(0,S[n - 1 ]);
    S[n - 3] += max(0,max(S[n - 2],S[n - 1]));
    for (int i = n -4 ; i >= 0 ; i--)S[i] += max(max(S[i +1], S[i+2]), S[i+3]);
    cout << S[0];
          
}
