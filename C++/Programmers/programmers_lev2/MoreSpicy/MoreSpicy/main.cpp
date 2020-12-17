//
//  main.cpp
//  MoreSpicy
//
//  Created by 조윤영 on 04/04/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//
//https://programmers.co.kr/learn/courses/30/lessons/42626

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> spicy_level;
    
    for(int i=0; i<scoville.size(); i++) {
        
        spicy_level.push(scoville[i]);
    }
    
    while(!spicy_level.empty()) {
        int firstLessSpicyFood = spicy_level.top();
        
        if(firstLessSpicyFood >= K)return answer;

        spicy_level.pop();
        
        if(!spicy_level.empty()){
            int secondLessSpicyFood = spicy_level.top();
            spicy_level.pop();
            
            int newSpicyFood = firstLessSpicyFood + secondLessSpicyFood*2;
            
            spicy_level.push(newSpicyFood);
            
            answer++;
        }else break;
        
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    vector<int> scoville = {1,2,3,9,10,12};
    int K = 7;
    
    
    
    cout<<solution(scoville, K);
    
    return 0;
}
