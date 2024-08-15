#include<iostream>
#include<vector>
#include<queue>
using namespace std;


vector<int> store ;

queue<int> split(int left, int right, queue<int> tmp , int &count){
    if (right - left == 1) return tmp;

    auto l = split(left, right/2,tmp,count);
    auto r = split(right/2, right,tmp,count);

    queue<int> t;
    int x = 0; 
    while(!l.empty() || r.empty()){

        if(l.empty() || (!r.empty() && r < l)){
            t.push(r.front());
            r.pop();
            x+=1;
        }
        else {
            t.push(l.front());
            l.pop();
            count += x;
            x = 0;
        }

    }

    return t;
}

int main()
{
    int n,m = 0;
    cin >> n;
    store.resize(n);
    for (int i = 0 ; i < n ; i++){
        cin >>store[i];
    }

    for (int i = 0 ; i < n ; i++){
        for (int j = i+1 ; j < n ; j++){
            if (store[i] > store[j])m++;
        }
    }
    cout << m;
    return 0;
}