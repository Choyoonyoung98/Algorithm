//
//  main.cpp
//  StockPrice
//
//  Created by 조윤영 on 31/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
/*
 (문제)
 초 단위로 기록된 주식가격이 담긴 배열 prices가 매개변수로 주어질 때, 가격이 떨어지지 않은 기간은 몇 초인지를 return 하도록 solution 함수를 완성하세요.
 */

#include <iostream>
#include <string>
#include <vector>
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

//첫 번째 풀이
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int cnt = 0;
    for(int i=0; i<prices.size(); i++) {
        cnt = 0;
        
        for(int j=i+1;j<prices.size(); j++) {
            cnt++;
            if(prices[i]>prices[j])break;
        }
        answer.push_back(cnt);
    }
    return answer;
}

//스택을 이용한 두 번째 풀이(*)
vector<int> solution2(vector<int> prices) {
    vector<int> answer;
    stack<int> s;
    int size = prices.size();
    for(int i=0; i<size; i++) {
        
        while(!s.empty() && prices[s.top()] >prices[i]) {
            answer[s.top()] = i-s.top();
            s.pop();
        }
        s.push(i); //0 push 1 push 3 push
    }
    while(!s.empty()) {
        answer[s.top()] = size - s.top()-1;
        s.pop();
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> prices{1,2,3,2,3};
    solution(prices);
    return 0;
}