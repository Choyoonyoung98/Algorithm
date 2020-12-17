//
//  main.cpp
//  CommonMultiple
//
//  Created by 조윤영 on 2020/11/21.
//

#include <iostream>
using namespace std;
int gratestCommonDivisor(int a, int b);

int leastCommonMultiple(int a, int b) {
    int answer = 0;
    answer = a * b *  gratestCommonDivisor(a, b);
    return answer;
}

int gratestCommonDivisor(int a, int b) {
    int answer = 0;
    
    while(true) {
        int temp = a%b;
        if( temp == 0) {
            answer = b;
            return answer;
        } else {
            a = b;
            b = temp;
        }
    }
    return answer;
}


void solution(int a, int b) {
    //최소공배수는 최대공약수를 먼저 구한 다음에 구할 수 있다!
    cout<< gratestCommonDivisor(a, b);
    cout<< leastCommonMultiple(a, b);
}

int main(int argc, const char * argv[]) {
    solution(3, 10);
    return 0;
}
