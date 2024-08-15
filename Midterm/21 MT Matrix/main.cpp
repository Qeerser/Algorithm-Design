#include<iostream>
using namespace std;

int u, p, w ,v;
int solve(long long n, long long row , long long col){
    if (n == 0)return 0;
    if(row <= 2 && col <= 2) {
        row--;col--;
        if(!row){
            if(!col)return u;
            return p;
        }
        else{
            if(!col)return w;
            return v;
        }
    }
    
    long long m = n >> 1;

    bool hor = row > m;
    bool ver  = col > m;
    if (hor && row > 2) row -= m;
    if (ver && col > 2) col -= m;
    if (!hor and !ver)return solve(m,row,col);
    else if (!hor and ver)return solve(m,col,row);
    else if (hor and !ver)return -solve(m,row,col);
    else  return -solve(m,col,row);

}

int main()
{   
    long long n, m ;
    cin >> n >> m >> u >> p >> w >>v;
    for (int i = 0 ; i < m ; i++){
        long long r,c;
        cin >> r >> c;
        cout << solve(1LL << n,r,c)  <<"\n";
    }

    
}