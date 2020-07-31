//
//  main.cpp
//  ExpressWithN
//
//  Created by 조윤영 on 2020/07/31.
//  Copyright © 2020 조윤영. All rights reserved.
//
//https://programmers.co.kr/learn/courses/30/lessons/42895
//

#include <string>
#include <vector>
#define MAX_SIZE 32001

using namespace std;

int answer = MAX_SIZE;

void dfs(int N, int number, int cnt, int currentNumber) {
    if(cnt > 8) return;
    if(currentNumber == number) {
        answer = min(answer, cnt);
        return;
    }
    
    int tempNumb = 0;
    for(int i=0; i+cnt<=8; i++) {
        tempNumb = tempNumb*10+N;
        dfs(N, number, cnt+1+i, currentNumber + tempNumb);
        dfs(N, number, cnt+1+i, currentNumber - tempNumb);
        dfs(N, number, cnt+1+i, currentNumber * tempNumb);
        dfs(N, number, cnt+1+i, currentNumber / tempNumb);
    }
}

int solution(int N, int number) {
    dfs(N, number,  0, 0);
    
    if(answer == MAX_SIZE) answer = -1;
    return answer;
}

int main(int argc, const char * argv[]) {
    solution(5, 12);
    return 0;
}


/*
 dp[1] = 2; // [5/5] 2
 dp[2] = 4; // [5/5 + 5/5] 4
 dp[3] = 6; // [5/5 + 5/5 + 5/5] 6
 dp[4] = 8; // [5/5 + 5/5 + 5/5 + 5/5] 8
 
 dp[5] = 1; // [5] 1
 
 dp[6] = 3; //[5 + 5/5] 3 =  1+ dp[1]
 dp[7] = 5; //[5 + 5/5 + 5/5] = 1+ dp[2]
 dp[8] = 7;//[5 + 5/5 + 5/5 + 5/5] 1+dp[3] = 7
 dp[9] = 9;  //[5 + 5/5 + 5/5 + 5/5 + 5/5]
 
 dp[10] = 2; //[5 + 5]
 dp[11] = 3; //[55/5] 1+dp[1]
 dp[12] = 5;//[55/5 +5/5] 1+dp[2]
 dp[13] = 7;//55/5 + 5/5 + 5/5] 2+4*/
