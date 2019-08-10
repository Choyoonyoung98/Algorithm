//
//  main.cpp
//  Sum
//
//  Created by 조윤영 on 10/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
/*
 두 정수 a, b가 주어졌을 때 a와 b 사이에 속한 모든 정수의 합을 리턴하는 함수, solution을 완성하세요.
 예를 들어 a = 3, b = 5인 경우, 3 + 4 + 5 = 12이므로 12를 리턴합니다.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//내 풀이
long long solution(int a, int b) {
    long long answer = 0;
    for(int i=min(a,b); i<=max(a,b); i++) {
        answer +=i;
    }
    return answer;
}
//다른 사람 풀이(*)
long long solution2(int a, int b) {
    return (long long)(a + b) * (abs(a - b) + 1) / 2;//abs:절대값 함수
}

int main(int argc, const char * argv[]) {
    int a=-4; int b=-3;
    cout<<solution(a,b);
    return 0;
}
