#include<iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> z, ans;
 void recur(int a, int b,int top,int bottom,int left,int right){
    if (a == 0 ) {
        ans[top] += b * z[left];
        return;
    }

    int m_v = (top + bottom) >> 1;
    int m_h = (left + right) >> 1;
    recur(a - 1 ,b ,top ,m_v ,left ,m_h);
    recur(a - 1 ,b ,top ,m_v ,m_h  ,right);
    recur(a - 1 ,b ,m_v ,bottom ,left ,m_h);
    recur(a - 1 ,-1 *b  ,m_v ,bottom ,m_h ,right);
 }


int main()
{   
    int n ;
    cin >> n ;
    int a = log(n) /log(2);
    z.resize(n);
    ans.resize(n);
    for (auto &i : z) cin >> i;
    recur(a ,1 ,0 ,1 << a ,0 ,1 << a);
    
    for (auto y : ans) cout << y << " ";
        
    
}