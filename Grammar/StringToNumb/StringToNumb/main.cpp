//
//  main.cpp
//  StringToNumb
//
//  Created by 조윤영 on 20/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>
#include <sstream>

using namespace std;

int solution(string s) {
    int answer = 0;
    stringstream ss(s);
    ss >> answer;
    
    //OR
//    int b = stoi(s);
    
    return answer;
}

int main(int argc, const char * argv[]) {
    solution("1234");
    return 0;
}
