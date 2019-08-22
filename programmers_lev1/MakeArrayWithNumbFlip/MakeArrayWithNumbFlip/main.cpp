//
//  main.cpp
//  MakeArrayWithNumbFlip
//
//  Created by 조윤영 on 22/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
/*
 자연수 n을 뒤집어 각 자리 숫자를 원소로 가지는 배열 형태로 리턴해주세요. 예를들어 n이 12345이면 [5,4,3,2,1]을 리턴합니다.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    
    while(n!=0) {
        answer.push_back(n%10);
        n /= 10;
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    solution(12345);
    return 0;
}
