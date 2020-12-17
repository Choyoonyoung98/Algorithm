//
//  main.cpp
//  Budget
//
//  Created by 조윤영 on 06/03/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//
//https://programmers.co.kr/learn/courses/30/lessons/43237
//BinarySearch를 이용한 기준값을 넘지 않는 최대값 찾기

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int answer = 0;

int solution(vector<int> budgets, int M) {
    
    int maxBudget = -1;
    int sumBudget = 0;
    for(int i=0; i<budgets.size(); i++) {
        sumBudget += budgets[i];
        maxBudget = max(maxBudget, budgets[i]);
    }
    
    //전체 요구 예산의 합이 최대 예산을 넘지 않을 경우 그대로 지급.
    if(sumBudget <= (long)M) return maxBudget;
    
    int start = 0;
    int end = maxBudget;
    int mid = 0;
    
    int limitedMaxBudget = 0;
    
    while(start <=end) {
        
        mid = (start + end)/2;

        int sum = 0;

        for(int i=0; i<budgets.size(); i++) {
            if(budgets[i] <=mid)sum += budgets[i];
            else sum+=mid;
        }

        if(sum < (long)M) {
            start = mid+1;
            
            limitedMaxBudget = max(limitedMaxBudget, mid);
            
        }else if (sum > (long)M) {
            end = mid-1;
        }else if (sum == (long)M) {
            return mid;
        }
        
    }

    return limitedMaxBudget;
}

int main(int argc, const char * argv[]) {
    vector<int> budgets = {120, 110, 140, 150};
    int M = 485;
    
    cout<<solution(budgets, M);
    return 0;
}
