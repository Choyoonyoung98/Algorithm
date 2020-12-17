//
//  main.cpp
//  Line_3
//
//  Created by 조윤영 on 06/04/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> broken_index;
int maxRoad = -1;

void dfs(int index, int cnt, string road, int n) {

    if(cnt == n) {
        int relatedRoadCnt = 0;
        int tempCnt = 0;

        for(int i=0; i<road.size(); i++) {
            if(road[i] == '1') tempCnt++;
            else {
                relatedRoadCnt = max(tempCnt,relatedRoadCnt);
                tempCnt = 0;
            }
        
        }
        relatedRoadCnt = max(tempCnt,relatedRoadCnt);
        
        maxRoad = max(maxRoad, relatedRoadCnt);
        return;
    }
    for(int i=index+1; i<broken_index.size(); i++) {
        road[broken_index[i]] = '1';
        dfs(i, cnt+1, road, n);
        road[broken_index[i]] = '0';
    }
}

int solution(string road, int n) {
    int answer = -1;
    
    for(int i=0; i<road.size(); i++) {
        if(road[i] == '0')broken_index.push_back(i);
    }

    if(broken_index.size()<n){
        int canFix = broken_index.size();
        road[broken_index[0]] = '1';
        dfs(0, 1, road, canFix);
    }else{
        for(int i=0; i<=broken_index.size()-n; i++) {
            cout<<i<<endl;
            road[broken_index[i]] = '1';
            dfs(i, 1, road, n);
            road[broken_index[i]] = '0';
        }
    }

    

    answer = maxRoad;
    return answer;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
