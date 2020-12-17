//
//  main.cpp
//  GroundEating
//
//  Created by 조윤영 on 23/03/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//
//https://programmers.co.kr/learn/courses/30/lessons/12913
//메모이제이션이란..?

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

//일반 for문 + 메모이제이션.. 일반 for문이 가능하다면 재귀함수보다 빠르다!
int solution(vector<vector<int>> land)
{
    int answer = 0;

    //n행
    for(int i=0; i<land.size(); i++) { //주어진 n행만큼 for문을 돌린다.
        if(i == 0) continue;//이전에 누적된 점수가 없으므로
        
        for(int j=0; j<4; j++) {//현재 행 4열
            int maxScore = 0;
            
            for(int h = 0; h<4; h++) {//이전 행 4열
                if(j == h)continue; //같은 열이 아닌 것 중에
                
                maxScore = max(maxScore, land[i-1][h]); //자기 위의 값 중 제일 큰 것
            }
            
            land[i][j] = maxScore + land[i][j]; //최대값을 현재 위치에 저장.
        }
    }
    
    for (int i = 0; i < 4; ++i) {
        answer = max(answer, land[land.size()-1][i]);
    }
    
    return answer;
}


//dfs: 시간초과
int answer = 0;

void dfs(int depth, int index, int sum, int end, vector<vector<int>> land) {
    
    if(depth == end-1) {
        answer = max(answer, sum);
        return;
    }
    
    for(int i=0; i<4; i++) {
        if(i != index) {
            dfs(depth+1, i, sum+land[depth][i], end, land);
        }
    }
}

int solution2(vector<vector<int>> land)
{
    
    for(int i=0; i<4; i++) {
        dfs(0, i, land[0][i], land.size(), land);
    }
    return answer;
}


//bfs : 시간초과
struct Score {
    int nextLine;
    int prevIndex;
    int score;

    Score(int _nextLine, int _prevIndex, int _score) {
        nextLine = _nextLine;
        prevIndex = _prevIndex;
        score = _score;
    }
};

int solution1(vector<vector<int> > land)
{
    int answer = 0;

    queue<Score> q;

    for(int i=0; i<4; i++) {
        q.push(Score(1,i, land[0][i]));
    }

    while(!q.empty()) {
        int currentLine = q.front().nextLine;
        int prevIndex = q.front().prevIndex;
        int score = q.front().score;

        q.pop();

        if( currentLine >= land.size() ) {
            answer = max(answer, score);
            cout<<score<<endl;
            continue;
        }

        for(int i=0; i<4; i++) {
            if(i != prevIndex) {
                q.push(Score(currentLine+1, i, score+land[currentLine][i]));
            }
        }
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> land = {{1,2,3,5},{5,6,7,8},{4,3,2,1}};
    cout<<solution(land);
    
    return 0;
}
