//
//  main.cpp
//  Tower
//
//  Created by 조윤영 on 24/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//https://programmers.co.kr/learn/courses/30/lessons/42588
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

//stack 활용2 (2020/04/26)

using namespace std;

struct Info {
    int index;
    int height;
    
    Info(int _index, int _height) {
        index = _index;
        height = _height;
    };
};

vector<int> solution3(vector<int> heights) {
    vector<int> answer(heights.size(), 0);
    stack<Info> towers;
    
    
    for(int i= heights.size()-1; i>=0; i--) {
        
        if(!towers.empty()) {
            int prevTowerHeight = towers.top().height;
            int prevTowerIndex = towers.top().index;
                   
            if(prevTowerHeight < heights[i]) {
                while(prevTowerHeight < heights[i]) {
                    answer[prevTowerIndex] = i+1;
                    towers.pop();
                    
                    if(towers.empty())break;
                    prevTowerHeight = towers.top().height;
                    prevTowerIndex = towers.top().index;
                }
                
            }
        }
       
        towers.push(Info(i, heights[i]));
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> heights{6,9,5,7,4};
    
    solution(heights);
    solution2(heights);
    solution3(heights);
    
    return 0;
}
