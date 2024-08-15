#include<iostream>
using namespace std;

int main()
{
    int n; 
    cin >> n;

    int maxValue = -9999999, currentSequence = 0;

    for (int i = 0 ; i < n; i++){
        int x ;
        cin >> x;
        currentSequence = max(x,currentSequence + x);
        maxValue = max(maxValue, currentSequence);
    }

    cout << maxValue;
    return 0;
}