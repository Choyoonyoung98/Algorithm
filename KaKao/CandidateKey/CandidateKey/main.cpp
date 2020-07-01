//
//  main.cpp
//  CandidateKey
//
//  Created by 조윤영 on 09/05/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

vector<string> combination;
int column = 0;

bool compare(string& a, string& b) {
    if(a.length() != b.length()) return a.length() < b.length();
    return a<b;
}


void Combination(int k, string temp) {
    
    for(int i=k; i<column; i++) {
        temp += to_string(i);
        combination.push_back(temp);
        Combination(i+1, temp);
        temp = temp.substr(0,temp.length()-1);//백트랙이랑 비슷한 개념으로 이해하면 될듯
    }
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    
    column = relation[0].size();//칼럼 갯수 가져오기
    //가능한 조합수 가져오기
    Combination(0,"");
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<vector<string>> relation = {{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}};
    solution(relation);
    return 0;
}
