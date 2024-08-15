#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n , q;
    cin >> n >> q;
    
    vector<pair<int,int>> lib(n);
    for (int i = 0 ; i < n ; i++){
        cin >> lib[i].first >> lib[i].second;
    }
    sort(lib.begin(),lib.end());
    vector<pair<int,int>> book(n+1);
    for (int i = 1 ; i <= n; i++){
        book[i] = {book[i-1].first + lib[i-1].second , lib[i-1].first};
    }
    
    for (int i = 0 ; i < q ; i++){
        int a ;
        cin >> a;
        int ans = lower_bound(book.begin(),book.end(),make_pair(a,0))->second;
        cout << ans << "\n";
    }
}