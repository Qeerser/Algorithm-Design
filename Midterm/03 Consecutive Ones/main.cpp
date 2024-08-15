#include<iostream>
#include <vector>
using namespace std;

void combi(int n,vector<int> &sol,int len,int t, int k,bool y){
    y = y || (t >= k);
    if (len < n) {
        
        sol[len] = 0;
        combi(n,sol,len+1,0,k,y);

        sol[len] = 1;
        combi(n,sol,len+1,t+1,k,y);
    }
    else if(y){
        for (int i = 0 ; i < n ; i++){
          cout << sol[i]  <<"";
        }
        cout <<  endl;
    }
}
int main()
{
    int n , k;
    cin >> n >> k;
    vector<int> sol(n);
    combi(n , sol ,0,0,k,false);
}