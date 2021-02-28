//
//  main.cpp
//  Pipe_Line2020_1
//
//  Created by 조윤영 on 2021/02/25.
//

#include <iostream>
#include <vector>
#include <deque>
#include <map>
using namespace std;
vector<int> solution(vector<int> ball, vector<int> order) {
    vector<int> answer;
    deque<int> dq;
    map<int, bool> isWaiting;
    
    for(int b: ball) { dq.push_back(b); }
    for(int o: order) {
        if(o == dq.front()) {
            answer.push_back(dq.front());
            dq.pop_front();
            while(isWaiting[dq.front()]) {
                answer.push_back(dq.front());
                isWaiting[dq.front()] = false;
                dq.pop_front();
            }
        }
        else if(o == dq.back()) {
            answer.push_back(dq.back());
            dq.pop_back();
            while(isWaiting[dq.back()]) {
                answer.push_back(dq.back());
                isWaiting[dq.back()] = false;
                dq.pop_back();
            }
        }
        else { //보류
            isWaiting[o] = true;
        }
    }
    
    for(int a: answer) cout<<a<<endl;
    return answer;
}
int main(int argc, const char * argv[]) {
    vector<int> ball = {11,2,9,13,24};
    vector<int> order = {9,2,13,24,11};
    solution(ball, order);
    return 0;
}
