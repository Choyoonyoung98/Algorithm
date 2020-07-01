//
//  main.cpp
//  kakao5
//
//  Created by 조윤영 on 09/05/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#define ACCESS 200
#define DENIED 400

using namespace std;

vector<int> indegree;
vector<vector<int>> relation_door;
vector<bool> visited;
map<int,int> canAccess;
map<int,int> m;
vector<int> deniedDoor;

void dfs(int index) {
    if(canAccess[index] == DENIED) return;
    
    visited[index] = true;

    if(m[index] != 0) {
        //해당 문이 다른 문의 우선순위라면?
        int nextDoor = m[index];
        canAccess[nextDoor] = ACCESS;
        
        //해당 문의 접근을 허용한다.
    }
    
    for(int i=0; i<relation_door[index].size(); i++) {
        int currentDoor = relation_door[index][i];
        
        if(!visited[currentDoor]) {
            
            if(canAccess[currentDoor] == DENIED) {
                //우선순위인 문을 아직 방문하지 않았고, 허용되지 않는 문이라면
                deniedDoor.push_back(currentDoor);
                continue;
            }
    
            dfs(currentDoor);
        }
    }
    
    
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {

    relation_door.assign(n+1, {});
    visited.assign(n+1, false);
    
    for(int i=0; i<path.size(); i++) {
        int doorA = path[i][0];
        int doorB = path[i][1];

        relation_door[doorA].push_back(doorB);
        relation_door[doorB].push_back(doorA);
    }
    
    for(int i=0; i<order.size(); i++) {
        int doorA = order[i][0];
        int doorB = order[i][1];
        
        m[doorA] = doorB;
        canAccess[doorB] = DENIED;

    }

    //맵의 기본값 0
    
    dfs(0);
    
    
    for(int i=0; i<deniedDoor.size(); i++) {
        
        dfs(deniedDoor[i]);
    }
    
    for(int i=0; i<n; i++) {
        if(!visited[i])return false;
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    int n = 9;
    vector<vector<int>> path = {{8,1},{0,1},{1,2},{0,7},{4,7},{0,3},{7,5},{3,6}};
    vector<vector<int>> order = {{4,1},{8,7},{6,5}};
    solution(n, path, order);

    return 0;
}
