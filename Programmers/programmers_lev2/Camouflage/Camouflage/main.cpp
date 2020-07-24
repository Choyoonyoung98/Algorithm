//
//  main.cpp
//  Camouflage
//
//  Created by 조윤영 on 29/01/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//
//옷의 이름은 상관이 없는 문제임을 빠르게 캐치하는 것이 중요

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
int answer = 0;
map<string,bool> m;

void dfs(int index, vector<vector<string>> clothes) {
    answer++;

    for(int j=index+1; j<clothes.size(); j++) {
        string matchClothes = clothes[j][1];
        if(!m[matchClothes]) {
            m[matchClothes] = true;
            dfs(j, clothes);
            m[matchClothes] = false;
        }
    }
}

//통과하지만, 28개의 TC 중 4개가 시간초과
int solution2(vector<vector<string>> clothes) {
    
    for(int i=0; i<clothes.size(); i++) {
        answer++;
        string currentClothes = clothes[i][1];
        m[currentClothes] = true;
        
        for(int j=i+1; j<clothes.size(); j++) {
            string matchClothes = clothes[j][1];
            if(!m[matchClothes]) {
                m[matchClothes] = true;
                dfs(j, clothes);
                m[matchClothes] = false;
            }
        }
        m[currentClothes] = false;
    }
    
    return answer;
}

//조합을 알아낼 때: ((바지개수+1)*(상의개수+1)*(모자개수+1)) -1
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> mapItem;
    
    //map의 경우 int값이 0으로 초기화되어 있나봐
    for(int i=0; i<clothes.size(); i++) {
        string clothType = clothes[i][1];
        mapItem[clothType]++; //옷 종류의 갯수를 증가
    }
    
    //map을 돌려보려면 iterator를 써야한다!
    for(auto iter = mapItem.begin(); iter !=mapItem.end(); iter++) {
        answer *= (iter->second) +1;
    }
    return (answer-1);
}

int main(int argc, const char * argv[]) {
    vector<vector<string>> clothes = {{"yellow_hat", "headgear"},{"blue_sunglasses","eyewear"},{"green_turban","headgear"}};
    
    cout<<solution2(clothes);
    return 0;
}
