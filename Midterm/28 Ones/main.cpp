#include<iostream>
using namespace std;

int cal(int n, int l){
    if (n < 11) return min(13 - n, n);

    int s = 1;
    for (int i = 0; i < l - 1; i++) s = s * 10 +1;
    return 
}

int main()
{
    int n;
    cin >> n;

    int s = 1, l = 1;
    while (s < n) s = s * 10 + 1, l++;
    cout << min(cal(n, l - 1), cal(s - n, l) + l);
}