//
//  main.cpp
//  FindPeople
//
//  Created by 조윤영 on 18/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
/*
 String형 배열 seoul의 element중 Kim의 위치 x를 찾아, 김서방은 x에 있다는 String을 반환하는 함수, solution을 완성하세요. seoul에 Kim은 오직 한 번만 나타나며 잘못된 값이 입력되는 경우는 없습니다.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";

    vector<string> temp = seoul;
    auto result = find(temp.begin(), temp.end(), "Kim");
    int n = distance(temp.begin(), result);
    
    answer ="김서방은"+to_string(n)+"에 있다";
    return answer;
}

int main(int argc, const char * argv[]) {

    vector<string> name{"Jane", "Kim"};
    cout<<solution(name)<<endl;
    return 0;
}
