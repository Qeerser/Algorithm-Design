#include<iostream>
#include<vector>

using namespace std;
int main()
{
    int n ,m;
    cin >> n >> m;
    int B[n];
    for(int i = 0 ; i < n; i ++) cin >> B[i];
    for(int i = 0 ; i < m ; i++){
        int x ,c = 0,j = 0;
        cin >> x;
        while (B[j] != x) if(B[j++] > x) c++;
        cout << c << endl;
    }
}