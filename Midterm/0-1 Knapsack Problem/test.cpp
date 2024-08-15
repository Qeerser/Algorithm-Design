#include<iostream>
using namespace std;

int split (int l , int r){
    if(l == r) return l;
    int m = (l + r) / 2;
    return max(split(l ,m),split(m + 1, r));
}
int main()
{
    return split(0, 7);
}