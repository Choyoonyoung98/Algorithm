//
//  main.cpp
//  SumOfFactor
//
//  Created by 조윤영 on 21/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

/*자연수 n을 입력받아 n의 약수를 모두 더한 값을 리턴하는 함수, solution을 완성해주세요.*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i=1; i<=n; i++) answer += (n%i == 0)?i:0;

    return answer;
}

int main(int argc, const char * argv[]) {
    cout<<solution(12);
    return 0;
}
