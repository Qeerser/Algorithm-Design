#include<iostream>
#include <vector>
using namespace std;

int n, sol[100000] , tmp[100000],num = 0 ;

void merge_sort(int start,int  stop ){
    if (start >= stop) return;
    int m = (start + stop) >> 1;
    merge_sort(start,m);
    merge_sort(m+1,stop);

    int bi = start , ci = m + 1 , k = 0;

    for (int i = start ; i <= stop ; i++){
        if(bi > m) {tmp[i] = sol[ci++]; k++; continue;}
        if(ci > stop) {tmp[i] = sol[bi++];num += k; continue;}
        (sol[bi] <= sol[ci]) ? num += k : k++;
        tmp[i] = (sol[bi] <= sol[ci]) ? sol[bi++] : sol[ci++];
    }
    for (int i = start ; i <= stop ; i++) sol[i] = tmp[i];
}

int main()
{
    cin >> n  ;
    for(int i = 0 ; i < n ; i++)cin >> sol[i];
    merge_sort(0,n-1);
    cout << num;
}