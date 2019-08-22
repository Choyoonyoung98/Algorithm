//
//  main.cpp
//  MockTest
//
//  Created by 조윤영 on 31/07/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
/*수포자는 수학을 포기한 사람의 준말입니다. 수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다. 수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.
 
 1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
 2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
 3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...
 
 1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때, 가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> a1 {1,2,3,4,5};
    vector<int> a2 {2,1,2,3,2,4,2,5};
    vector<int> a3 {3,3,1,1,2,2,4,4,5,5};
    
    int cnt1 =0;
    int cnt2 = 0;
    int cnt3 = 0;
    
    int size = answers.size();
    for(int i=0; i<size; i++) {
        int i1 = i%5;
        int i2 = i%8;
        int i3 = i%10;
        
        if(answers[i] == a1[i1]) cnt1++;
        if(answers[i] == a2[i2]) cnt2++;
        if(answers[i] == a3[i3]) cnt3++;
        
    }
    int maxCount = max(cnt1, max(cnt2, cnt3));
    
    if(maxCount == cnt1) answer.push_back(1);
    if(maxCount == cnt2) answer.push_back(2);
    if(maxCount == cnt3) answer.push_back(3);
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> answer {1,3,2,4,2};
    for(int i=0; i<solution(answer).size(); i++) {
        cout<<solution(answer)[i];
    }
    return 0;
}
//
//vector<int> solution(vector<int> answers) {
//    vector<int> answer;
//    vector<int> they(3);
//    for(int i=0; i<answers.size(); i++) {
//        if(answers[i] == one[i%a1.size()]) they[0]++;
//        if(answers[i] == two[i%a2.size()]) they[1]++;
//        if(answers[i] == thr[i%a3.size()]) they[2]++;
//    }
//    int they_max = *max_element(they.begin(),they.end());
//    for(int i = 0; i< 3; i++) {
//        if(they[i] == they_max) answer.push_back(i+1);
//    }
//    return answer;
//}
