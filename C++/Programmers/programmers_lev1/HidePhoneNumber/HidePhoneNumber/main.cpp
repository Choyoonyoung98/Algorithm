//
//  main.cpp
//  HidePhoneNumber
//
//  Created by 조윤영 on 12/02/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string phone_number) {
    string answer = phone_number;
    for(int i=0; i<answer.size()-4; i++) {
        answer[i] = '*';
    }
    return answer;
}
int main(int argc, const char * argv[]) {
    string testcase1 = "01033334444";
    string testcase2 = "027778888";
    cout<<solution(testcase1);
    return 0;
}
