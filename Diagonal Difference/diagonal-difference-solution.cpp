#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the 'diagonalDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int diagonalDifference(vector<vector<int>> arr) {
    int n = arr.size(), x = n, d1 = 0, d2 = 0;
    for (int i = 0; i < n; ++i) {
        x--;
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                d1 += arr[i][j];
                d2 += arr[i][x];
            }
        }
    }

    return abs(d1 - d2);
}

int main() {
    int n, x;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> x;
            arr[i][j] = x;
        }
    }
    cout << diagonalDifference(arr);
    return 0;
}
