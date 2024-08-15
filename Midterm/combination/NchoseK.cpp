#include<iostream>
#include <vector>
using namespace std;

void combi(int n,vector<int> &sol,int len , int k , int chosen,int &sum){
    if (len < n) {
        if (len - chosen < n - k){
        sol[len] = 0;
        combi(n,sol,len+1,k,chosen,sum);
        }
        if (chosen < k){
            sol[len] = 1;
            combi(n,sol,len+1,k,chosen+1,sum);

        }
    }
    else{
        for (int i = 0 ; i < n ; i++) cout << sol[i] << "";
           
        
        sum++;
        cout << "." << endl;
    }
}
int main()
{
    int n = 3;
    int k = 2;
    int sum = 0;
    // vector<int> sum(k);
    vector<int> sol(n);
    combi(n , sol ,0,k,0,sum);
     cout << sum << endl;
}