#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<int, vector<int>> Book;
    int currentSum = 0;
    int maxRange = -999;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        currentSum += x;
        if (Book.count(x) != 0)
        {
            Book[x][2] += currentSum;
            Book[x][1] = max(Book[x][1] + Book[x][2], x);
            Book[x][0] = max(Book[x][0], Book[x][1]);
        }
        else
        {
            Book[x].resize(3);
            Book[x][0] = x;
            Book[x][1] = x;
        }
        Book[x][2] = -currentSum;
        maxRange = max(maxRange, Book[x][0]);
    }
    cout << maxRange;
}
