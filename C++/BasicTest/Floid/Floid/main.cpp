//
//  main.cpp
//  Floid
//
//  Created by 조윤영 on 2020/09/02.
//  Copyright © 2020 조윤영. All rights reserved.
//
//https://www.acmicpc.net/problem/11404
//플로이드 - 최단 경로
#include <iostream>
#include <vector>
#define MAX_SIZE 1e9 //10억

using namespace std;
int N = 0;
int M = 0;
vector<vector<int>> city; //필요한 비용
vector<bool> visited;

void  input()  {
    cin>> N;
    cin>> M;
    city.assign(N+1, vector<int>(N+1, MAX_SIZE));
    visited.assign(N+1, false);

    for(int i=0; i<M; i++) {
        int A,B,C;
        cin>> A>> B>> C;
        city[A][B] = min(city[A][B], C);
    }
}

void solution() {
    for(int k=1; k<= N; k++) { //1
        for(int a=1; a<=N; a++) {
            for(int b=1; b<=N; b++) {
                city[a][b] = min(city[a][b], city[a][k] + city[k][b]); //1-2  1-2, 1-1+1-1, 1-2+2=
            }
        }
    }
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(city[i][j] == MAX_SIZE || i == j) cout<<"0 ";
            else cout<<city[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    solution();
    return 0;
}
