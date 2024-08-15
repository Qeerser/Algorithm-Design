#include <iostream>
#include <vector>

using namespace std;

bool findTripletSum(vector<int>& array, int query) {
    int n = array.size();

    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1, right = n - 1;

        while (left < right) {
            int currentSum = array[i] + array[left] + array[right];

            if (currentSum == query) {
                return true;
            } else if (currentSum < query) {
                left++;
            } else {
                right--;
            }
        }
    }

    return false;
}

int main() {
    // Input
    int N, M;
    cin >> N >> M;

    vector<int> array(N);
    for (int i = 0; i < N; ++i) {
        cin >> array[i];
    }

    vector<int> queries(M);
    for (int i = 0; i < M; ++i) {
        cin >> queries[i];
    }

    // Output
    for (int i = 0; i < M; ++i) {
        bool result = findTripletSum(array, queries[i]);
        if (result) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}