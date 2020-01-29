//
//  main.cpp
//  CandidateKey
//
//  Created by 조윤영 on 29/01/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> combination;
int column = 0;

//단일조합부터 앞에 오게 정렬, 조합의 길이가 같을 경우 디폴트로 정렬
bool compare(string& a, string& b) {
    if(a.length() != b.length()) return a.length()<b.length();
    return a<b;
}

//모든 종류의 조합 생성
void Combination(int k, string temp) {
    for(int i=k; i<column; i++) {
        temp += to_string(i);//0
        combination.push_back(temp);
        Combination(i+1, temp);
        temp = temp.substr(0, temp.length()-1);
    }
}

//조합에 따른 후보키 판단 함수
bool subset(vector<vector<string>>& relation, string com) {
    map<string, int>candidateCheck;
    
    for(int i=0; i<relation.size(); i++) {
        string temp = "";
        for(int k=0; k<com.size(); k++) {
            int number = com[k]-'0';
            temp += relation[i][number];
        }
        
        //해당조합이 이미 있는지 확인
        if(candidateCheck[temp])return false;
        candidateCheck[temp]++;
    }
    
    //중복이 없으므로 최소성과 유일성을 만족
    return true;
}
int solution(vector<vector<string>> relation) {
    int answer = 0;
    //칼럼 개수 추가
    column = relation[0].size();
    //가능한 조합수 가져오기
    Combination(0,"");
    //가능한 조합수 정렬하기(낮은 조합부터 하기위해)-> 이걸 안해서 한동안 고생함
    sort(combination.begin(), combination.end(), compare);
    //조합수만큼 반복
    for (int i = 0; i < combination.size(); i++) {
        //후보키라면
        if (subset(relation, combination[i])) {
            //후보키를 임시변수에 넣는다.
            string temp = combination[i];
            //후보키에 와 겹치는 조합은 다 없앤다. 13조합이면 1과 3이들어간것을 모두찾아서 제거
            for (int j = combination.size() - 1; j >= i; j--) {
                bool check = true;
                for (auto t : temp) {
                    if (combination[j].find(t) == string::npos) {
                        check = false;
                        break;
                    }
                }
                //하나도 없었으면 패스를 위한 조건문
                if (check)    combination.erase(combination.begin() + j);
            }
            //제거를 했으므로 i를 감소하고 후보키였으므로 answer증가
            i--;    answer++;
        }
    }

    return answer;
}
int main(int argc, const char * argv[]) {
    vector<vector<int>> vec{{123,1,1},{356,1,0},{327,2,0},{489,0,1}};
    vector<vector<string>> relation{{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}};

    
    solution(relation);
    return 0;
}
