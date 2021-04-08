#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void maxValue(vector<pair<int,int>>bag,int N,int i,int max_value,int max_w,int limitW,int &answer ){
    if (max_w<=limitW && max_value > answer){
        answer=max_value;
    }
    for (int j = i; j <N ; ++j) {
        if (i && bag[i].second == bag[i-1].second && j>i)
            continue;
        maxValue(bag,N,j+1,max_value+bag[j].second,max_w+bag[j].first,limitW,answer);
    }
    return ;

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int limitW,N,weight,value,answer=0,max_value=0,max_w=0;
    cin>>limitW;
    cin>>N;
    vector<pair<int,int>>bag(N);
    for (int i = 0; i < N; ++i) {
        cin >> weight >> value;
        bag[i]=make_pair(weight,value);
    }
    maxValue(bag,N,0,max_value,max_w,limitW,answer);
    cout<<answer<<endl;
    return 0;
}


