//
//  main.cpp
//  WordTransfer
//
//  Created by 조윤영 on 29/12/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#define MAX_SIZE 51
using namespace std;

int cnt = 100;

vector<bool> visited(MAX_SIZE, false);
void dfs(string target, vector<string> &words, int index, int depth) {
    int wordSize = words[0].size();
    int matchCnt = 0;
    
    if(words[index] == target) {
        
        cnt = min(cnt, depth);
        return;
    }

    
    for(int i=0; i<words.size(); i++) {
        matchCnt = 0;
        if(visited[i] !=true) {
            for(int j=0; j<wordSize; j++) {
                if (words[index][j] == words[i][j]) matchCnt++;
            }
            if(matchCnt == wordSize-1) {
                cout<<words[i]<<endl;
                visited[index] = true;
                dfs(target, words, i, depth+1);
                visited[i] = false;//중요중요
                
            }
        }
    }
    
    
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int wordSize = words[0].size();
    
    int matchCnt = 0;
    for(int i=0; i<words.size(); i++) {
        matchCnt = 0;
        if(visited[i] != true) {
            for(int j=0; j<wordSize; j++) {
                if (begin[j] == words[i][j]) matchCnt++;
            }
            if ( matchCnt == wordSize - 1) {
                dfs(target, words, i, 1);
                
            }
        }
    }
    
    if(cnt == 100) answer = 0;
    else answer = cnt;
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout<<solution("hit", "cog", words);
    return 0;
}
