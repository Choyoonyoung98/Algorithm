//
//  main.cpp
//  HamburgerDiet
//
//  Created by 조윤영 on 2020/07/28.
//  Copyright © 2020 조윤영. All rights reserved.
//
//https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWT-lPB6dHUDFAVT
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int solution();

int T = 0;
int N = 0;
int L = 0;
int S = 0;
int K = 0;

struct HamburgerInfo {
    int score;
    int calories;
    HamburgerInfo(int _score, int _calories) {
        score = _score;
        calories = _calories;
    };
};

vector<HamburgerInfo> burgers;

void input() {
    cin>>T;
    for(int i=0; i<T; i++) {
        cin>>N >> L;
        burgers.assign(N, HamburgerInfo(0, 0));
        
        for(int j=0; j<N; j++) {
            cin>>S>>K;
            burgers[j] = HamburgerInfo(S,K);
        }

        cout<<solution()<<"\n";
    }
}

struct SumInfo {
    int scoreSum;
    int calorySum;
    int prevIndex;
    
    SumInfo(int _scoreSum, int _calorySum, int _prevIndex) {
        scoreSum = _scoreSum;
        calorySum = _calorySum;
        prevIndex = _prevIndex;
    };
};

int solution() {
    int answer = 0;
    queue<SumInfo> q;
    for(int i=0; i<N; i++) {
        
        int score = burgers[i].score;
        int calory = burgers[i].calories;
        q.push(SumInfo(score, calory, i));
        
        while(!q.empty()) {
            int scoreSum = q.front().scoreSum;
            int calorySum = q.front().calorySum;
            int prevIndex = q.front().prevIndex;
            
            q.pop();
            if(calorySum == L ||  (calorySum <L && prevIndex == N-1)) {
                answer = max(answer, scoreSum);
                continue;
            }else if(calorySum > L) {
                if(calorySum - burgers[prevIndex].calories <= L) {
//                    cout<<scoreSum - burgers[prevIndex].score <<","<<calorySum - burgers[prevIndex].calories<<endl;
                    answer = max(answer, scoreSum - burgers[prevIndex].score);
                }
                continue;
            }
            
            if(prevIndex != N-1) {
                for(int j=prevIndex+1; j<burgers.size(); j++) {
                    q.push(SumInfo(scoreSum + burgers[j].score, calorySum + burgers[j].calories, j));
                }
            }
            
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    return 0;
}
