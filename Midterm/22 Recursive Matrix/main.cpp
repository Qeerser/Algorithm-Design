#include<iostream>
#include <vector>
using namespace std;

 void recur(vector<vector<int>> &v, int a, int b,int top,int bottom,int left,int right){
    
    if (a == 0 ) {
        v[top].push_back(b);
        return;
    }

    int m_v = (top + bottom) >> 1;
    int m_h = (left + right) >> 1;
    recur(v ,a - 1 ,b ,top ,m_v ,left ,m_h);
    recur(v ,a - 1 ,b - 1 ,top ,m_v ,m_h  ,right);
    recur(v ,a - 1 ,b + 1 ,m_v ,bottom ,left ,m_h);
    recur(v ,a - 1 ,b  ,m_v ,bottom ,m_h ,right);
 }


int main()
{   
    int a , b;
    cin >> a >> b;
    vector<vector<int>> v(1 << a);
    recur(v ,a ,b ,0 ,1 << a ,0 ,1 << a);
    for(auto x : v){
        for (auto y : x) cout << y << " ";
        cout << "\n";
    }
}