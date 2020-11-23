//
//  main.cpp
//  PrinterQueue_1966
//
//  Created by 조윤영 on 2020/11/23.
//
// 프린터 큐
//priority queue를 활용한 우선순위를 통한 풀이
// https://www.acmicpc.net/problem/1966

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution();
vector<int> priority;
int T, N, M, X = 0;

void input() {
    cin>> T;
    for(int t=0; t<T; t++) {
        cin>> N >> M;
        priority.assign(N, 0);
        for(int i=0; i<N; i++) {
            cin>> priority[i];
        }
        cout<<solution()<<"\n";
    }
}

int solution() {
    priority_queue<int> pq;
    vector<bool> visited;
    visited.assign(N, false);
    
    for(int i=0; i<N; i++) {
        pq.push(priority[i]);
    }
    
    int cnt = 0;
    while(!pq.empty()) {
        for(int i=0; i<priority.size(); i++) {
            if(pq.top() == priority[i] && !visited[i]) {
                cnt++;
                visited[i] = true;
                pq.pop();
                
                if(i == M) return cnt;
            }
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    return 0;
}
