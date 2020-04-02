//
//  main.cpp
//  MiddleWord
//
//  Created by 조윤영 on 09/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

/*단어 s의 가운데 글자를 반환하는 함수, solution을 만들어 보세요. 단어의 길이가 짝수라면 가운데 두글자를 반환하면 됩니다.*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(string s) {

    
    return (s.length()/2 ==0) ? s.substr(s.length()/2-1,1) : s.substr(s.length()/2-1,2);

}

int main(int argc, const char * argv[]) {
    cout<<solution("qwer");
    return 0;
}
