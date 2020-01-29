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
//(바지개수+1)*(상의개수+1)+(모자개수+1) -1
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

//아래 풀이는 작동은 하나 시간초과와 다소의 테스트케이스를 통과하지 못함!
//vector<string>combination;
//map<string, string> mapItem;
//
//void makeCombination(vector<vector<string>>& clothes, int index, string temp){
//    for(int i=index; i<clothes.size(); i++) {
//        temp += to_string(i);
//        combination.push_back(temp);
//        makeCombination(clothes, index+1, temp);
//        temp = temp.substr(0, temp.size()-1);
//    }
//}
//bool compare(string& a, string& b) {
//    if(a.size() != b.size())return a.length()<b.length();
//    else return a < b;
//}
//int solution2(vector<vector<string>> clothes) {
//    int answer = 0;
//    makeCombination(clothes, 0,"");
//    sort(combination.begin(), combination.end(), compare);
//
//    for(int i=0; i<combination.size(); i++) {
//        sort(combination[i].begin(), combination[i].end());
//    }
//    combination.erase(unique(combination.begin(), combination.end()), combination.end());
//
//    for(int i=0; i<combination.size(); i++) {
//        if(combination[i].size() == 1){
//            for(char comb: combination[i]) {
//                int index = comb - '0';
//                string clothName = clothes[index][0];
//            }
//            answer++;
//        }
//        else{
//            bool isDuplicate = false;
//            for(char comb: combination[i]) {
//                int index = comb - '0';
//                string clothType = clothes[index][1];
//                string clothName = clothes[index][0];
//
//
//                if(mapItem.find(clothType) == mapItem.end())mapItem[clothType] = clothName;
//                else {
//                    isDuplicate = true;
//                    break;
//                }
//            }
//            if(isDuplicate == false) {
//                for(char comb: combination[i]) {
//                    int index = comb - '0';
//                    string clothName = clothes[index][0];
//
//                }
//                answer++;
//            }
//
//            mapItem.clear();
//        }
//    }
//    return answer;
//}

int main(int argc, const char * argv[]) {
    vector<vector<string>> clothes = {{"yellow_hat", "headgear"},{"blue_sunglasses","eyewear"},{"green_turban","headgear"}};
    
    cout<<solution(clothes);
    return 0;
}
