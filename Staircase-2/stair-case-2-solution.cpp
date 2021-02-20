#include <bits/stdc++.h>

using namespace std;

int staircase(int n,unordered_map<int,int> &memoization) {
    if (memoization.find(n) != memoization.end())
        return memoization.at(n);
    if (n==0)
        return 1;
    if (n<0)
        return 0;
    int method_count = staircase(n-1,memoization) + staircase(n-2,memoization) + staircase(n-3,memoization);
    memoization.insert(make_pair(n,method_count));
    return method_count;
}

int main() {

    int t;
    cin >> t;
    unordered_map<int,int> memoization;
    cout << staircase(t,memoization)<<endl;
    return 0;
}

