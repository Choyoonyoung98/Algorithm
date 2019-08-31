//
//  main.cpp
//  NextBigNumb
//
//  Created by 조윤영 on 31/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
/*
 (문제)
 자연수 n이 주어졌을 때, n의 다음 큰 숫자는 다음과 같이 정의 합니다.
 
 조건 1. n의 다음 큰 숫자는 n보다 큰 자연수 입니다.
 조건 2. n의 다음 큰 숫자와 n은 2진수로 변환했을 때 1의 갯수가 같습니다.
 조건 3. n의 다음 큰 숫자는 조건 1, 2를 만족하는 수 중 가장 작은 수 입니다.
 예를 들어서 78(1001110)의 다음 큰 숫자는 83(1010011)입니다.
 
 자연수 n이 매개변수로 주어질 때, n의 다음 큰 숫자를 return 하는 solution 함수를 완성해주세요.
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>


using namespace std;

template <typename Iter>
void print(Iter begin, Iter end) {
    while(begin !=end) {
        cout<<"["<<*begin <<"]";
        begin++;
    }
    cout<<endl;
}

//나의 더러운 시도
int solution2(int n) {
    int answer = 0;
    int max = -100;
    int temp = n; int size=0;

    for(int i=0; i<14; i++) {
        if(pow(2,i)<=n && n<pow(2,i+1)) {
            max = pow(2,i);
            size = i+1;
        }
    }
    vector<int> vec(size,0);
    
    for(int i=max; i>=0; i--) {
        if(temp-pow(2,i) >=0){

            temp=temp-pow(2,i);
            vec[i]=1;
        }
    }
    reverse(vec.begin(), vec.end());
    print(vec.begin(), vec.end()); cout<<endl;
    
    bool b1 = false;
    bool b0 = false;
    
    for(int i=0; i<vec.size(); i++) {
    }
    print(vec.begin(), vec.end());
    
    for(int i=0; i<vec.size(); i++) {
        if(vec[i] == 1){
            answer+=pow(2,size-1-i);
        }
    }

    return answer;
}

//다른 사람의 혁신적인 풀이
int getCntNumb(int n) {
    int nCnt = 0;
    for(int i=0; i<14; i++) {
        if(n & 0x01 << i) nCnt++;
        /*각 자리의 비트가 1인지 아닌지 확인,
         1이라면 true를 반환하여 nCnt++
         i=0일 때,1001110과 0000001 둘은 AND 연산하고, 이때 결과값이 0이므로 false
    */
    }
    return nCnt;
}
int solution(int n) {
    int answer = 0;
    int nNum1Cnt = getCntNumb(n); //78을 이진법으로 했을 때 1의 갯수 반환
    
    while(1) {
        n++; //79,80,81 쭉쭉 수를 올리면서 1의 갯수 반환하여 비교
        if(nNum1Cnt == getCntNumb(n)){
            answer = n;
            return answer;
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    cout<<solution(78);
    return 0;
}
