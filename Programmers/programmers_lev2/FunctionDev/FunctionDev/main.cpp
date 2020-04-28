//
//  main.cpp
//  FunctionDev
//
//  Created by 조윤영 on 22/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
//https://programmers.co.kr/learn/courses/30/lessons/42586
//

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


//2020-04-28 풀이
vector<int> solution4(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> leftTime;
    
    for(int i=0; i<progresses.size(); i++) {
        int leftWork = 100 - progresses[i];
        int t = leftWork/speeds[i];
        if((leftWork % speeds[i]) != 0) {
            t++;
        }
        leftTime.push(t);
    }

    int distributionCnt = 0;
    int standardTask = leftTime.front();
    
    while(!leftTime.empty()) {
        distributionCnt++;
        
        int currentLeftTime = leftTime.front();
        
        if(standardTask < currentLeftTime){
            answer.push_back(distributionCnt-1);
            
            standardTask = currentLeftTime;
            distributionCnt = 1;
        }
            
        leftTime.pop();
        
    }
    
    if(distributionCnt != 0) answer.push_back(distributionCnt);
    
    for(int i=0; i<answer.size(); i++) {
        cout<<answer[i]<<endl;
    }
    return answer;
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

//20191218 큐로 푼 풀이
vector<int> solution3(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    vector<int> temp;
    int left = 0;
    int day = 0;
    int cnt = 0;
    
    //1:각 작업 당 걸리는 시간 계산 후 큐에 넣는다.
    for(int i=0; i<progresses.size(); i++) {
        left = 100-progresses[i];
        if(left%speeds[i] ==0){
            q.push(left/speeds[i]);
            cout<<"{"<<left/speeds[i]<<"}";
        }else{
            q.push((left/speeds[i])+1);
            cout<<"{"<<(left/speeds[i])+1<<"}";
        }
    }
    
    while(!q.empty()) {
        if(day == 0) {
            day+=q.front();
            q.pop();
            cnt++;
            
        }else if(day <q.front()){//시간이 경과된 것에 비해 아직 작업이 끝나지 않았을 경우
            day+=(q.front()-day);
            q.pop();
            answer.push_back(cnt);
            
            cnt = 0;
            cnt++;
            
        }else{//작업이 완료되었을 경우 다음 작업물로 이동.
            q.pop();
            cnt++;
        }
    }
    answer.push_back(cnt);
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> progresses {93,30,55};
    vector<int> speeds{1,30,5};
    
    solution(progresses, speeds);
    solution2(progresses, speeds);
    return 0;
}
