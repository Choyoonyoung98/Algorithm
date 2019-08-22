//
//  main.cpp
//  NumbDescending
//
//  Created by 조윤영 on 22/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
/*
 함수 solution은 정수 n을 매개변수로 입력받습니다. n의 각 자릿수를 큰것부터 작은 순으로 정렬한 새로운 정수를 리턴해주세요. 예를들어 n이 118372면 873211을 리턴하면 됩니다.
 ***********************************************
 string -> int : stoi
 string -> long : stol
 string -> long long : stoll
 ***********************************************
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;


//내 풀이
long long solution(long long n) {
    long long answer = 0;
    
    vector<int> temp;
    
    while(n !=0) {
        temp.push_back(n%10);
        n /= 10;
    }
    sort(temp.begin(), temp.end());
    
    int k=1;
    for(int elem: temp) {
        answer += elem*k;
        k *=10;
    }
    
    return answer;
}

//string으로 풀이
long long solution2(long long n) {
    long long answer = 0;
    
    string str = to_string(n);
    sort(str.begin(), str.end(), greater<char>());
    answer = stoll(str);
    
    return answer;
}

int main(int argc, const char * argv[]) {
    cout<<solution(118372);
    return 0;
}
