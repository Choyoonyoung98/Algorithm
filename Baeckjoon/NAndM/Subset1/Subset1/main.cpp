//
//  main.cpp
//  Subset1
//
//  Created by 조윤영 on 2020/11/19.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M = 0;
vector<bool> visited;
vector<int> answer_list;
void input() {
    cin>> N >> M;
}

void dfs(int cnt) {
    
    if(cnt == M) {
        for(int a: answer_list) cout<<a<<" ";
        cout<<"\n";
    }
    for(int i=1; i<=N; i++) {
        if(!visited[i]) {
            visited[i] = true;
            answer_list.push_back(i);
            dfs(cnt+1);
            visited[i] = false;
            answer_list.pop_back();
        }
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    visited.assign(N+1, false);
    dfs(0);

    return 0;
}
