//
//  main.cpp
//  ExpressionOfNumb
//
//  Created by 조윤영 on 31/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
/*
 (문제)
 Finn은 요즘 수학공부에 빠져 있습니다. 수학 공부를 하던 Finn은 자연수 n을 연속한 자연수들로 표현 하는 방법이 여러개라는 사실을 알게 되었습니다. 예를들어 15는 다음과 같이 4가지로 표현 할 수 있습니다.
 
 1 + 2 + 3 + 4 + 5 = 15
 4 + 5 + 6 = 15
 7 + 8 = 15
 15 = 15
 
첫 번째 숫자를 n이라고 했을 때, n*k + k(k-1)
 

 n
 2n+1
 3n+2
 4n+3
 
 
 자연수 n이 매개변수로 주어질 때, 연속된 자연수들로 n을 표현하는 방법의 수를 return하는 solution를 완성해주세요.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i=1; i<n+1; i++) {
        for(int j=1; (j*i+((j-1)*j/2))<=15; j++) {
            if((j*i+((j-1)*j/2)) == 15){
                cout<<i<<"*"<<j<<"+"<<j-1<<"*"<<j<<"/2"<<endl;
                answer++;
            }
        }
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    cout<<solution(15);
    return 0;
}
