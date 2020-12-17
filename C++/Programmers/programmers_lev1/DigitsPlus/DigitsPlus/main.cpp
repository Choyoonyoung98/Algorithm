//
//  main.cpp
//  DigitsPlus
//
//  Created by 조윤영 on 22/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
/*
 자연수 N이 주어지면, N의 각 자릿수의 합을 구해서 return 하는 solution 함수를 만들어 주세요.
 예를들어 N = 123이면 1 + 2 + 3 = 6을 return 하면 됩니다.
 */
/*************************************************/
//cmath: pow - 제곱을 위한 함수
/*************************************************/

#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

template <typename Iter>
void print(Iter begin, Iter end) {
    while(begin !=end) {
        cout<<"["<<*begin <<"]";
        begin++;
    }
    cout<<endl;
}

//내 풀이
int solution(int n)
{
    int answer = 0;
    vector<int> temp;
    int len = to_string(n).length()-1;
    
    int k=0; int cnt = 0;
    
    for(int i=0; i<len+1; i++) {
        
        if (i==0) {
            temp.push_back(n/pow(10,len));
            k=pow(10,len);
        }else{
            temp.push_back((n%k)/pow(10,len-i));
            k=pow(10,len-i);
        }
    }
    
    for(int elem: temp) {
        cnt+=elem;
    }
    answer = cnt;
    return answer;
}

//내 풀이를 더 짧고 가독성 좋게 하면? 와우
int solution3(int n)
{
    int answer = 0;
    while (n > 0) {
        answer += n % 10;
        n /= 10;
    }
    return answer;
}


//string으로 바꾼 풀이
int solution2(int n) {
    int answer = 0;
    
    string s  = to_string(n); //제발 기억하렴!!! int -> string으로
    for(int i=0; i<s.length(); i++) answer += (s[i]-'0'); //문자열을 정수로 더하는 방법
    return answer;
}


int main(int argc, const char * argv[]) {
    cout<<solution(123);
    cout<<solution2(123);
    cout<<solution3(123);
    return 0;
}
