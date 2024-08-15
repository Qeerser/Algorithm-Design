#include<iostream>
#include <vector>
using namespace std;
int main()
{
    int n , k;
    cin >> n  >> k;
    vector<int> lib(n);
    for(int i = 0 ; i < n ; i++){
        cin >> lib[i];
    }
    
    int start = 0;
    int stop = n-1;
    while (start != stop){
        int m = (start + stop) >> 1;
        if (lib[m] >= k ) stop = m ;
        else start = m + 1 ;
    }
    if(lib[start] == k) cout << start;
    else cout << -1;
    return 0;
}