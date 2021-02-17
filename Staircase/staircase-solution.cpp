#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircase(int n) {
    int r = n-1;
    string hash_tag = "#";  
    for (int i=0; i < n; i++) {
        for (int j =0; j<r; j++) {
            printf(" ");
        }
        cout<<hash_tag<<endl;
        hash_tag+="#";
        r--;
    }

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
