//
//  main.cpp
//  ContinueWordGame
//
//  Created by 조윤영 on 24/03/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<char, string> m;
    
    char prevEndChar = '0';
    
    for(int i=0; i<words.size(); i++) {

        char startWord = words[i][0];
        int wordSize = words[i].size();
        
        if(i != 0) {
            if(startWord != prevEndChar){
                answer.push_back(i%n + 1);
                answer.push_back(i/n +1);
                return answer;
            }
            if(m[startWord] == words[i]) {
                
                //중복되는 단어라면
                answer.push_back(i%n + 1);
                answer.push_back(i/n +1);
                return answer;
            }
        }
        
        
        m[startWord] = words[i]; //새로운 단어 넣기
        prevEndChar = words[i][wordSize-1];
    }
    
    //탈락자가 생기지 않는다면,
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}


int main(int argc, const char * argv[]) {
    
    vector<string> words = {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"};
    solution(3,words);
    return 0;
}
