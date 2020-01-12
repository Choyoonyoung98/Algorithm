//
//  main.cpp
//  GaryMandering
//
//  Created by 조윤영 on 08/01/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#define MAX_SIZE 101

using namespace std;

int N = 0;
int room[MAX_SIZE][MAX_SIZE];

void dfs() {
    
}
void solution() {
    
}
int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>room[i][j];
        }
    }
    solution();
    
    return 0;
}
