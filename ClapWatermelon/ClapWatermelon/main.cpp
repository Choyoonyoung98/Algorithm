//
//  main.cpp
//  ClapWatermelon
//
//  Created by 조윤영 on 19/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
/*
 길이가 n이고, 수박수박수박수....와 같은 패턴을 유지하는 문자열을 리턴하는 함수, solution을 완성하세요. 예를들어 n이 4이면 수박수박을 리턴하고 3이라면 수박수를 리턴하면 됩니다.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    for(int i=0; i<n; i++) answer = (i==0 || i%2 == 0)? answer+"수":answer + "박";
    return answer;
}

int main(int argc, const char * argv[]) {
    cout<<solution(3);
    return 0;
}
