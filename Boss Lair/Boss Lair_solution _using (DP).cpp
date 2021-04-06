#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int minimumCoins(vector<vector<int>> building,vector<vector<int>>& DP_building,int end,int i,int j,int N){
    int miniCoins=0;
    if (DP_building[i][j]!=-1){
        return DP_building[i][j];
    }
    if (building[i][j]==end){
        return end;
    }
    if ( (i+1) % N != 0 && j+1<=N-1 && i+N<=(N*N)-1){ //can go right ,down and up
        miniCoins += min(min(minimumCoins(building,DP_building,end,i+1,j,N),minimumCoins(building,DP_building,end,i,j+1,N)),minimumCoins(building,DP_building,end,i+N,j,N));
    }else if ((i+1) % N == 0 && j+1<=N-1 && i+N<=(N*N)-1){ // can go up and right
        miniCoins += min(minimumCoins(building,DP_building,end,i+N,j,N),minimumCoins(building,DP_building,end,i,j+1,N));
    }else if ((i+1) % N != 0 && j+1>N-1 && i+N<=(N*N)-1){ // can go down and up
        miniCoins += min(minimumCoins(building,DP_building,end,i+1,j,N),minimumCoins(building,DP_building,end,i+N,j,N));
    }else if ((i+1) % N == 0 && j+1>N-1 && i+N<=(N*N)-1){ // can go up only
        miniCoins += minimumCoins(building,DP_building,end,i+N,j,N);
    }else if ((i+1) % N != 0 && j+1<=N-1 && i+N>(N*N)-1) { //can go right and down
        miniCoins += min(minimumCoins(building,DP_building,end,i+1,j,N),minimumCoins(building,DP_building,end,i,j+1,N));
    }else if ((i+1) % N != 0 && j+1>N-1 && i+N>(N*N)-1) { //can go down only
        miniCoins += minimumCoins(building,DP_building,end,i+1,j,N);
    }else if ((i+1) % N == 0 && j+1<=N-1 && i+N>(N*N)-1) { //can go right only
        miniCoins += minimumCoins(building,DP_building,end,i,j+1,N);
    }
    DP_building[i][j] = miniCoins + building[i][j];
    return DP_building[i][j] ;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,miniCoins;
    cin >> N;
    vector<vector<int>> building(N*N),DP_building(N*N,vector<int>(N,-1));
    vector<int>floor(N);
    for (int i = 0; i < N*N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin>>floor[j];
        }
        building[i]=floor;
    }
    miniCoins=minimumCoins(building,DP_building,building[(N*N)-1][N-1],0,0, N);
    cout << miniCoins <<endl;
    return 0;
}