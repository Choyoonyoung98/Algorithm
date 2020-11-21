//
//  main.cpp
//  SubSet2
//
//  Created by 조윤영 on 2020/11/20.
//

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, M = 0;
vector<bool> visited;
vector<vector<int>> answer_list;

void input() {
    cin>> N  >> M;
}

void solution(int idx, int cnt, vector<int> answer) {
    
    if(cnt == M) {
        answer_list.push_back(answer);
        return;
    }
    if(idx > N) return;
    solution(idx+1, cnt, answer); //선택 안함
    
    //선택
    answer.push_back(idx);
    solution(idx+1, cnt+1, answer);
    
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    visited.assign(N+1, false);
    vector<int> answer;
    solution(1, 0, answer);
    
    sort(answer_list.begin(), answer_list.end());
    
    for(int i=0; i<answer_list.size(); i++) {
        for(int a: answer_list[i]) {
            cout<<a<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
