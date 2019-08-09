//
//  main.cpp
//  MiddleWord
//
//  Created by 조윤영 on 09/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

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
