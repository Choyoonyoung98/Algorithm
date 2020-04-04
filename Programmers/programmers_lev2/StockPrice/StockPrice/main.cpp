//
//  main.cpp
//  StockPrice
//
//  Created by 조윤영 on 31/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
//https://programmers.co.kr/learn/courses/30/lessons/42584
//stack

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
//순차적으로 접근하고 순차적으로 답을 구해야하는 경우에는 무조건 stack 의심해보기

//14353
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
