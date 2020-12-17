//
//  main.cpp
//  124WorldNumb
//
//  Created by 조윤영 on 22/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
//https://programmers.co.kr/learn/courses/30/lessons/12899

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    string rule ="412";

    int temp = 0;
    while(n != 0){
        
        temp = n % 3;
        answer = rule[temp] + answer;
        
        n /= 3;
        
        if(temp == 0)n -= 1;
        
        
    }
    
    cout<<answer;
    return answer;
}

int main(int argc, const char * argv[]) {
    cout<<solution(1);
    return 0;
}
