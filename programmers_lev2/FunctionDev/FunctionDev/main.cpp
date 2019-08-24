//
//  main.cpp
//  FunctionDev
//
//  Created by 조윤영 on 22/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
/*
 프로그래머스 팀에서는 기능 개선 작업을 수행 중입니다. 각 기능은 진도가 100%일 때 서비스에 반영할 수 있습니다.
 
 또, 각 기능의 개발속도는 모두 다르기 때문에 뒤에 있는 기능이 앞에 있는 기능보다 먼저 개발될 수 있고, 이때 뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포됩니다.
 
 먼저 배포되어야 하는 순서대로 작업의 진도가 적힌 정수 배열 progresses와 각 작업의 개발 속도가 적힌 정수 배열 speeds가 주어질 때 각 배포마다 몇 개의 기능이 배포되는지를 return 하도록 solution 함수를 완성하세요.
 ****************************************
 ceil : cmath의 내장함수 - 반올림
 ****************************************
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

template <typename Iter>
void print(Iter begin, Iter end) {
    while(begin !=end) {
        cout<<"["<<*begin <<"]";
        begin++;
    }
    cout<<endl;
}

//MAX값 바꿔주면서 answer에 최종 값 담는 방법
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> temp(progresses.size());
    vector<int> answer;
    float n;
    int max = 0;
    int cnt = 1;
    
    for(int i=0; i< progresses.size(); i++) {
        n = speeds[i];
        n = (100 - progresses[i])/n;//배포까지 몇일이 걸릴지 계산
        n = (int)ceil(n);//나누어 떨어지지 않는다면 반올림
        temp[i] = n;
    }

    max = temp[0];
    for(int i=1; i<temp.size(); i++) {
        if(max >= temp[i]) {
            cnt++;
        }
        else{
            answer.push_back(cnt);
            cnt = 1;
            max = temp[i];
        }
    }
    answer.push_back(cnt);
    return answer;
}

//Queue로 푸는 방법(깔끔)
vector<int> solution2(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    float n;
    
    for(int i = 0; i<progresses.size(); i++) {
        n = (100 - progresses[i])/speeds[i];
        n = ceil(n);
        q.push(n);
    }
    
    while(!q.empty()) {
        int cnt = 1;
        int x = q.front();
        q.pop();
        
        while(x >= q.front() && !q.empty()) {
            
            q.pop();
            cnt++;
        }
        answer.push_back(cnt);
    }
    print(answer.begin(), answer.end());
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> progresses {93,30,55};
    vector<int> speeds{1,30,5};
    
    solution(progresses, speeds);
    solution2(progresses, speeds);
    return 0;
}
