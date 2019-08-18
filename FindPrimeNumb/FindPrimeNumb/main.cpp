//
//  main.cpp
//  FindPrimeNumb
//
//  Created by 조윤영 on 19/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
/*
 1부터 입력받은 숫자 n 사이에 있는 소수의 개수를 반환하는 함수, solution을 만들어 보세요.
 
 소수는 1과 자기 자신으로만 나누어지는 수를 의미합니다.
 (1은 소수가 아닙니다.)
 
 *******************
 에라토스테네스의 체를 이용한 해결방법!
 sqrt함수 중요중요
 *******************
 
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0; int cnt = 0;
    vector<int> vec;
    
    for(int i=0; i<n+1; i++) {
        vec.push_back(i);
    }
    for(int i=2; i<=sqrt(n); i++) {
        
        for(int j=i+i; j<n+1; j+=i) {
            vec[j]=0;
        }
    }
    for(int i=2; i<n+1; i++){
        if(vec[i] !=0) {
            cnt++;
        }
    }
    
    answer = cnt;
    return answer;
}

int main(int argc, const char * argv[]) {
    
    cout<<solution(10);
    return 0;
}
