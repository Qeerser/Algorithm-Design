#include<iostream>
using namespace std;
int main()
{
    int n,f1 = 1,f2 = 0, f;
    cin  >> n;
    for (int i = 2 ; i <= n ; i++){
        f = f1 + f2;
        f2 = f1;
        f1 = f;
    }
    cout << (f1  ? f1 : 0);
}