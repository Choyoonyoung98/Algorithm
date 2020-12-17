//
//  main.cpp
//  Priority_Queue
//
//  Created by 조윤영 on 04/04/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    priority_queue<int> q; //less가 기본값! : top에 가장 큰 값이 찍힌다.
    priority_queue<int, vector<int>, less<int>> less_q; //내림차순: top에 가장 큰 값이 찍힌다.
    priority_queue<int, vector<int>, greater<int>> greater_q; //오름차순: top에 가장 작은 값이 찍힌다.
    
    q.push(1);
    q.push(5);
    
    return 0;
}
