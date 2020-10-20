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

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<int> s;
    answer.assign(prices.size(), prices.size()-1);
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

vector<int> solution2(vector<int> prices) {
    vector<int> answer;
    priority_queue<pair<int, int>, vector<pair<int,int>>, less<pair<int,int>>> q; //price, index
    
    answer.assign(prices.size(), prices.size()-1);
    
    for(int i=0; i<prices.size(); i++) {
        if(i != 0) {
            while(!q.empty()) {
                int price = q.top().first;
                int index = q.top().second;
                if(price > prices[i]) {
                    answer[index] = i-index;
                    q.pop();
                } else break;
            }
        }
        q.push({prices[i], i});
    }
    
    while(!q.empty()) {
        int index = q.top().second;
        answer[index] = prices.size()-1-index;
        q.pop();
    }
    
    return answer;
}
int main(int argc, const char * argv[]) {
    vector<int> prices{1,2,3,2,3};
    solution(prices);
    return 0;
}
