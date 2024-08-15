#include<iostream>
#include <vector>
using namespace std;

vector<int> lib;
int range(int start , int stop){
    return lib[stop+1] - lib[start];
}
int cal(pair<int,int> x){
    return range(x.first,x.second);
}
pair<int,int> maxsum(int start,int stop){
    if (start >= stop) return {start,stop};
    int m = (start + stop) >> 1 ;

    auto r1 = maxsum(start,m);
    auto r2 = maxsum(m+1,stop);

    pair<int,int>  l = {-100000,-1};
    pair<int,int>  r = {-100000,-1};
    for (int i = start ; i <= m ; i++)l = max(l,{range(i,m),i});
    for (int i = m+1 ; i <= stop ; i++)r = max(r,{range(m+1,i),i});

    pair<int,int>  r3 = {l.second,r.second};

    if (cal(r1) >= cal(r2) &&cal(r1) >= cal(r3))return r1;
    else if(cal(r3) >= cal(r2))return r3;
    return r2;
}



int main()
{
    int n,sum = 0, m;
    cin >> n;
    lib.resize(n+1);
    
    for (int i = 1; i <= n ; i++){
        cin >> lib[i];
        max(m,lib[i]);
        lib[i] += lib[i-1];
    }
    pair<int,int> x = maxsum(0,n-1);
    int add = 0;
    pair<int,int> z;
    if(x.first == 0 && x.second == n-1);
    else if (x.first == 0)add = cal(maxsum(x.second + 1,n-1));
    else if (x.second == n-1)add =  cal(maxsum(0,x.first-1));
    else {
        auto a = maxsum(0,x.first-1);
        auto b = maxsum(x.second + 1,n-1);
        add = max(cal(a),cal(b));
    }
    add = max(add,add + cal(x));
    cout << add;
}