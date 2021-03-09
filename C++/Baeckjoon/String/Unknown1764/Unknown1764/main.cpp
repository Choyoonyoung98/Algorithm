//
//  main.cpp
//  Unknown1764
//
//  Created by 조윤영 on 2021/03/09.
//

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
map<string, int> m;
vector<string> answer;
void input() {
    cin>> N >> M;
    for(int i=0; i<N; i++) {
        string name;
        cin>> name;
        m[name] = 1;
    }
    for(int i=0; i<M; i++) {
        string name;
        cin>> name;
        m[name]++;
        if(m[name] == 2) answer.push_back(name);
    }
}
void solution() {
    cout<<answer.size()<<"\n";
    sort(answer.begin(), answer.end());
    for(string a: answer) { cout<<a<<"\n"; }
}

int main(int argc, const char * argv[]) {
    input();
    solution();
    return 0;
}
