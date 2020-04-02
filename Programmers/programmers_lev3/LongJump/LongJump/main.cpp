//
//  main.cpp
//  LongJump
//
//  Created by 조윤영 on 24/02/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//========================================================
//시간 초과
//========================================================
int wayCnt = 0;

void find(int target, int sum) {

    if(sum == target){
        wayCnt++;
        return;
    }
    else if(sum >target)return;
    
    find(target, sum+1);
    find(target, sum+2);
    
    return;
    
}

long long solution2(int n) {
    
    long long answer = 0;
    
    find(n, 1);
    find(n, 2);

    if(wayCnt >=1234567) answer = wayCnt % 1234567;
    else answer = wayCnt;
    return answer;
    
}
//========================================================
//DP 문제!
//DP 의 조건은 무엇일까?
//- 작은 문제가 반복이 일어나는 경우.
//- 같은 문제는 구할 때마다 정답이 같다.
//=> 작은 문제의 결과 값이 항상 같다는 점을 이용해서 큰 문제를 해결하는 방법이니 당연합니다.
//잠만 DP는 피보나치 수열인가? 그런듯

//작은 것에서 큰 것으로 가는 bottom up 방식

//나머지를 먼저 구하고 더해줘도 상관없음의 대표적인 예 ㅠㅠㅠㅠ
//숫자가 너무 커지지 않도록 나머지를 먼저 구한다음에 계산하자!!!!

long long solution(int n) {

    
    long long jump[3];
    jump[0] = 0;
    jump[1] = 1; // 1을 만들려면 (1)
    jump[2] = 2; // 2를 만들려면 (1+1) (2)
    //3을 만들려면 (1+2) (2+1) (1+1+1) ->3
    //즉, T(n) = T(n-1) + T(n-2)
    
    if(n == 1 || n == 2)return n;
    else {
        for(int i=3; i<=n; i++) {
            jump[i%3] = (jump[(i-1)%3]+jump[(i-2)%3])%1234567;
        }
    }

    return jump[n%3];
    
}


int main(int argc, const char * argv[]) {
    int n = 4;
    cout<<solution(n);
    return 0;
}
