//
//  main.cpp
//  NightShift
//
//  Created by 조윤영 on 19/02/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

//야근 피로도: 야근 시작한 시점에서 남은 일의 작업량을 제곱하여 더한 값
//1시간 동안 작업량 1만큼 처리
//void work(vector<int> works, int leftTime) {
//
//}

//정확도 통과 O / 효율성 통과 O
long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    int size = works.size();
    int index = 0; // 맨 끝
    
    sort(works.begin(), works.end(), greater<int>());
    
    while( n != 0) {
        n--;
        for(int i=0; i<works.size(); i++) {
            cout<<"["<<works[i]<<"]";
        }
        
        if(works[index] > 0) works[index]--;
        
        if(index == size - 1) index = 0;
        else {
            if(works[index] < works[index +1])index++;
            else index = 0;
        }
    }
    
    for(int i=0; i<size; i++) {
        answer += pow(works[i],2);
    }
        
    return answer;
}

//정확도 통과 O / 효율성 통과 O
long long solution2(int n, vector<int> works) {
    long long answer = 0;
    //works의 작업물을 처음부터 끝까지
    priority_queue<int> q(works.begin(), works.end());
    //우선순위 큐 priority_queue란, 들어간 순서에 상관없이 우선순위가 높은 데이터가 먼저 나온다.
    //순서가 중요하지 않기 때문에 쓸 수 있는 것
    
    for(int i=0; i<n; i++) {
        if(q.top() > 0){
            int temp = q.top();
            q.pop();
            q.push(temp -1);
        }
    }
    
    //마지막으로 남은 작업량으로 피로도를 계산한다.
    while(!q.empty()) {
        answer += pow(q.top(),2);
        q.pop();
    }
    return answer;
}


//정확도 통과 O / 효율성 통과 X
long long solutio3(int n, vector<int> works) {
    if(n == 0)return 0;
    
    long long answer = 0;

    int index = 0;
    sort(works.begin(), works.end(), greater<int>());
    while(n!=0) {
        
        if(works[index] < works[index+1]){
           sort(works.begin(), works.end(), greater<int>());
        }

        if(works[index] !=0) {
    
            works[index]--;
            n--;
        }else{
            break;
        }
        
    }
    
    
    for(int i=0; i<works.size(); i++) {
        answer += pow(works[i],2);
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> works = {4, 3, 3};
    int n = 4;
    
//    cout<<solution(n,works);
    cout<<solution(n,works);
    
    return 0;
}
