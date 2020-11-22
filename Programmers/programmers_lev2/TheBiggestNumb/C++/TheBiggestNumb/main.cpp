//
//  main.cpp
//  TheBiggestNumb
//
//  Created by 조윤영 on 11/12/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string &a, const string &b) {
    return a+b>b+a ? true:false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> s_answer;
    for(int i=0; i<numbers.size(); i++) {
        s_answer.push_back(to_string(numbers[i]));
    }
    sort(s_answer.begin(), s_answer.end(), cmp);
    
    for(string str: s_answer) {
        answer+=str;
    }

    if(answer[0] == '0')return "0";
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> numbers = {3,30,34,5,9};
    cout<<solution(numbers);
    return 0;
}
