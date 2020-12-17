//
//  main.cpp
//  2016
//
//  Created by 조윤영 on 06/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
/*
 2016년 1월 1일은 금요일입니다. 2016년 a월 b일은 무슨 요일일까요? 두 수 a ,b를 입력받아 2016년 a월 b일이 무슨 요일인지 리턴하는 함수, solution을 완성하세요. 요일의 이름은 일요일부터 토요일까지 각각 SUN,MON,TUE,WED,THU,FRI,SAT
 
 입니다. 예를 들어 a=5, b=24라면 5월 24일은 화요일이므로 문자열 TUE를 반환하세요.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    
    string answer = "";
    vector<int>month{31,29,31,30,31,30,31,31,30,31,30,31};

    int sumDay = 0;
    
    for(int i=0; i<a-1; i++) {
        
        sumDay+=month[i];
    }
    sumDay+=(b-1);
    
    //이거도 배열에 넣으면 더 깔끔하긴 함.
    switch(sumDay%7) {
        case 0: answer = "FRI";break;
        case 1: answer="SAT"; break;
        case 2: answer ="SUN"; break;
        case 3: answer="MON"; break;
        case 4: answer ="TUE"; break;
        case 5: answer = "WED"; break;
        case 6: answer = "THU"; break;
    }
    
    
    return answer;
}

int main(int argc, const char * argv[]) {
    cout<<solution(5,24);
    return 0;
}
