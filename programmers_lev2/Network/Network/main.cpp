//
//  main.cpp
//  Network
//
//  Created by 조윤영 on 19/10/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <string>
#include <vector>
#include <iostream>
#define MAX_SIZE 201

using namespace std;

bool visited[MAX_SIZE] = {false};
void dfs(int n, vector<vector<int>> &computers, int index) {
    visited[index] = true;
    for(int i=0; i<n; i++) {
        if(visited[i]!=true && computers[index][i] == 1) dfs(n, computers, i);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0; i<n; i++) {
        if(visited[i]!=true) {
            answer++;
            dfs(n, computers, i);
        }
    }
    return answer;
}
int main(int argc, const char * argv[]) {

    vector<vector<int>> computers{{1,1,0},{1,1,0},{0,0,1}};
    cout<<solution(3,computers);
    return 0;
}
