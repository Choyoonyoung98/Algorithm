//
//  main.cpp
//  SortingCards
//
//  Created by 조윤영 on 2020/08/25.
//  Copyright © 2020 조윤영. All rights reserved.
//
//https://www.acmicpc.net/problem/1715 (*)
//

#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int N = 0;
int answer = 0;
priority_queue<int, vector<int>, greater<int>> pq;
void input() {
    cin>> N;
    for(int i=0; i< N; i++) {
        int card;
        cin>> card;
        pq.push(card);
    }
}

int solution()  {
    int answer = 0;
    while(pq.size() != 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        answer +=  a + b;
        pq.push(a + b);
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    cout<<solution()<<"\n";
    return 0;
}
