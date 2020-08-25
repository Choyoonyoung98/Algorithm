//
//  main.cpp
//  FailureRate
//
//  Created by 조윤영 on 2020/08/25.
//  Copyright © 2020 조윤영. All rights reserved.
//
//https://programmers.co.kr/learn/courses/30/lessons/42889
//
//실패율 = (스테이지에 도달했으나 아직 클리어하지 못한 플레어의. 수) / (스테이지에 도달한 플레이어의 총 수)

#include <iostream>
#include <vector>
using namespace std;

struct StageInfo {
    int notClearCnt;
    int playerSum;
    StageInfo(int _notClearCnt, int _playerSum) {
        notClearCnt = _notClearCnt;
        playerSum = _playerSum;
    };
};

bool compare(pair<double,int> &a, pair<double,int> &b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<StageInfo> players(N+1, StageInfo(0,0)); // 스테이지에 도달했으나 아직 클리어하지 못한 플레어의. 수, 스테이지에 도달한 플레이어의 총 수, 인덱스
    vector<pair<double,int>> failures;
    for(int i=1; i<N+1; i++) {
        players[i] = StageInfo(0,0);
    }
    
    for(int currentStage: stages) {
        players[currentStage-1].notClearCnt++;
        for(int i=0; i< currentStage; i++) {
            players[i].playerSum++;
        }
    }
    
    for(int  i=0; i<N; i++)   {
        double notClearCnt = players[i].notClearCnt;
        double playerSum  = players[i].playerSum;
        
        if(playerSum == 0) {
            failures.push_back({0, i+1});
            continue;
        }
        double failure = notClearCnt/ playerSum;
        failures.push_back({failure, i+1});
    }
    
    sort(failures.begin(), failures.end(), compare);
    for(int i=0; i<N; i++) answer.push_back(failures[i].second);
    
    return answer;
}

int main(int argc, const char * argv[]) {
    int N = 5;
    vector<int> stages = {2,1,2,6,2,4,3,3};
    solution(N, stages);
    return 0;
}
