//
//  main.cpp
//  SubSet5
//
//  Created by 조윤영 on 2020/11/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solution();
int N, M = 0;
int x = 0;
vector<int> number_list;
vector<bool> visited;
vector<vector<int>> answer_list;
void input() {
    cin>>N >>M;
    number_list.assign(N, 0);
    visited.assign(N, false);
    for(int i=0; i<N; i++) cin>>number_list[i];
}

void dfs(int cnt, vector<int> answer) {
    
    if(cnt == M) {
        answer_list.push_back(answer);
        return;
    }
    
    for(int i=0; i<number_list.size(); i++) {
        if(!visited[i]) {
            visited[i] = true;
            answer.push_back(number_list[i]);
            dfs(cnt+1, answer);
            
            visited[i] = false;
            answer.pop_back();
        }
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    vector<int> temp;
    dfs(0, temp);
    
    sort(answer_list.begin(), answer_list.end());
    for(vector<int> answer: answer_list) {
        for(int a: answer) cout<<a<<" ";
        cout<<"\n";
    }
    return 0;
}
