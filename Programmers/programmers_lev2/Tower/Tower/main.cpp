//
//  main.cpp
//  Tower
//
//  Created by 조윤영 on 24/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
/*
 (문제)
 수평 직선에 탑 N대를 세웠습니다. 모든 탑의 꼭대기에는 신호를 송/수신하는 장치를 설치했습니다. 발사한 신호는 신호를 보낸 탑보다 높은 탑에서만 수신합니다. 또한, 한 번 수신된 신호는 다른 탑으로 송신되지 않습니다.
 */
//

#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

template <typename Iter>
void print(Iter begin, Iter end) {
    while(begin !=end) {
        cout<<"["<<*begin <<"]";
        begin++;
    }
    cout<<endl;
}

//초기 정답
vector<int> solution(vector<int> heights) {
    vector<int> answer(heights.size(),0);
    
    for(int i=heights.size(); i>=0; i--) {
        for(int j=i-1; j>=0; j--) {
            if(heights[i]<heights[j]) {
                answer[i] = j+1;
                break;
            }
        }
    }

    cout<<"1:";
    print(answer.begin(), answer.end());
    return answer;
}
//스택을 이용한 정답(*)
vector<int> solution2(vector<int> heights) {
    vector<int> answer;
    stack<int> s;
    
    for(int i=heights.size()-1; i>0; i--) {
        for(int j=i-1; j>=0; j--) {
            if(heights[j] > heights[i]){
                s.push(j+1);
                break;
            }
            if(j == 0) s.push(0);
        }
    }
   
    //답 넣어주기
    answer.push_back(0); //첫 번째 탑은 왼쪽에 탑들이 존재하지 않으므로 수신받을 탑 또한 없다.
    while(!s.empty()) {
        answer.push_back(s.top());
        s.pop();
    }
    cout<<"2:";
    print(answer.begin(), answer.end());
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> heights{6,9,5,7,4};
    
    solution(heights);
    solution2(heights);
    
    return 0;
}
