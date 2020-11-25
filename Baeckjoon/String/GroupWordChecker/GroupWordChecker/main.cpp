//
//  main.cpp
//  GroupWordChecker
//
//  Created by 조윤영 on 2020/11/26.
//https://www.acmicpc.net/problem/1316
//테스트케이스에 대해 예측해보는 머리 기르기. 여기서는 잘하고 있다
//그룹 단어 체커

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int N = 0;
vector<string> word_list;
void input() {
    
    cin>> N;
    word_list.assign(N, "");
    for(int i=0; i<N; i++) cin>> word_list[i];
    
}

int solution() {
    int answer = 0;
    for(int i=0; i<N; i++) {
        map<char, bool> m;
        bool isGroupWord = true;
        for(int j=0; j<word_list[i].size(); j++) {
            char c = word_list[i][j];
            if(!m[c]) {
                m[c] = true;
                while(word_list[i][j] == c && j<word_list[i].size()) j++;
                j--;
            } else {
                isGroupWord = false;
                break;
            }
        }
        if(isGroupWord) answer++;
        
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
