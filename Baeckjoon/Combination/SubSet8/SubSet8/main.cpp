//
//  main.cpp
//  SubSet8
//
//  Created by 조윤영 on 2020/11/21.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M = 0;
vector<vector<int>> answer_list;
vector<int> numb_list;
void input() {
    cin>> N >>M;
    numb_list.assign(N, 0);
    for(int i=0; i<N; i++) cin>> numb_list[i];
    
    sort(numb_list.begin(), numb_list.end());
}

void dfs(int cnt, int idx, vector<int> answer) {
    if(cnt == M) {
        answer_list.push_back(answer);
        return;
    }
    if(idx > N) return;
    
    for(int i=idx; i<N; i++) {
        answer.push_back(numb_list[i]);
        dfs(cnt+1, i, answer);
        answer.pop_back();
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    vector<int> temp;
    dfs(0, 0, temp);
    
    for(vector<int> answer: answer_list) {
        for(int a: answer) cout<<a<<" ";
        cout<<"\n";
    }
    return 0;
}
