#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> Book(n);
    for (auto &i : Book) i.resize(n);
    for (int i = 0; i < n; i++){
        for (int j = 0 ; j < n; j++) cin >> Book[i][j];
    }
    int High = Book[0][0];

    for (int i = 0; i < n; i++){
        for (int j = 0 ; j < n; j++) {
            int h = Book[i][j];
            for (int k = 1 ; k < n ; k++){
                int p = i + k;
                int q = j + k;
                if (p >= n || q >= n) continue;
                h += Book[p][q];

            }
            High = max(High,h);
        }
    }
    
    cout << High;
}