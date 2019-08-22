//
//  main.cpp
//  124WorldNumb
//
//  Created by 조윤영 on 22/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
/*
 124 나라가 있습니다. 124 나라에서는 10진법이 아닌 다음과 같은 자신들만의 규칙으로 수를 표현합니다.
 
 1.124 나라에는 자연수만 존재합니다.
 2.124 나라에는 모든 수를 표현할 때 1, 2, 4만 사용합니다.
 예를 들어서 124 나라에서 사용하는 숫자는 다음과 같이 변환됩니다.
 10진법    124 나라    10진법    124 나라
 1          1          6         14
 2          2          7         21
 3          4          8         22
 4          11         9         24
 5          12         10        41
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    int tmp=0;
    while (n > 0)
    {
        tmp = n % 3;
        if (tmp == 0) n = (n / 3) - 1;
        else n /= 3;
        
        answer = "412"[tmp] + answer;
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    cout<<solution(1);
    return 0;
}
