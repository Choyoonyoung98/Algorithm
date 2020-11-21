//
//  main.cpp
//  SubSet4
//
//  Created by 조윤영 on 2020/11/20.
//
#include <iostream>
#include <vector>
using namespace std;

int N, M = 0;
vector<vector<int>> answer_list;
void input() {
    cin>> N >> M;
}

void dfs(int idx, int cnt, vector<int> answer) {
    if(cnt == M) {
        answer_list.push_back(answer);
        return;
    }
    
    for(int i=idx; i<= N; i++) {
        answer.push_back(i);
        dfs(i, cnt+1, answer);
        answer.pop_back();
    }
    
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    vector<int> temp;
    dfs(1, 0, temp);
    
    for(vector<int> answer: answer_list) {
        for(int a: answer) cout<<a<<" ";
        
        cout<<"\n";
    }
    return 0;
}
