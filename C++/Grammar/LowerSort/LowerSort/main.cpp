//
//  main.cpp
//  LowerSort
//
//  Created by 조윤영 on 18/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
/*문자열 s에 나타나는 문자를 큰것부터 작은 순으로 정렬해 새로운 문자열을 리턴하는 함수, solution을 완성해주세요.
 s는 영문 대소문자로만 구성되어 있으며, 대문자는 소문자보다 작은 것으로 간주합니다.*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template <typename k>
void print(vector<k>& map) {
    for(const auto& m:map){
        cout<<m;
    }
    cout<<endl;
}

string solution(string s) {
    string answer = s;
    //이렇게 간단한데..
    sort(answer.begin(), answer.end(), greater<char>());//오름차순
    //sort(answer.begin(), answer.end(), less<char>());이건 내림차순
    return answer;
}

vector<char> justTest(vector<char> v) {
    vector<char> vec = v;
    sort(vec.begin(), vec.end());
    print(vec);
    return vec;
}


int main(int argc, const char * argv[]) {
    string str = "Zbcdefg";
    vector<char>vec {'f','s','a','b'};
    cout<<solution(str)<<endl;
    
    justTest(vec);
    return 0;
}
