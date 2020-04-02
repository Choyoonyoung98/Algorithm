//
//  main.cpp
//  MaxMin
//
//  Created by 조윤영 on 26/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
/*
 문자열 s에는 공백으로 구분된 숫자들이 저장되어 있습니다. str에 나타나는 숫자 중 최소값과 최대값을 찾아 이를 (최소값) (최대값)형태의 문자열을 반환하는 함수, solution을 완성하세요.
 예를들어 s가 1 2 3 4라면 1 4를 리턴하고, -1 -2 -3 -4라면 -4 -1을 리턴하면 됩니다.
 */

#include <iostream>
#include <string>
#include <vector>


using namespace std;

template <typename Iter>
void print(Iter begin, Iter end) {
    while(begin !=end) {
        cout<<"["<<*begin <<"]";
        begin++;
    }
    cout<<endl;
}

string solution(string s) {
    string answer="";
    vector<string> vec;
    string n="";
    int min=0; int max=0;
    
    for(int i=0;i<s.size(); i++) {
        if(s[i] != ' '){
            n+=s[i];
        }else{
            vec.push_back(n);
            n="";
        }
        //마지막 숫자 push
        if((i==s.size()-1) && n!="") {
            vec.push_back(n);
        }
        
    }
//    print(vec.begin(), vec.end());
    string s_min = vec[0];
    min =stoi(vec[0]);
    max = stoi(vec[1]);
    
    for(int i=0; i<vec.size(); i++) {
        if(min> stoi(vec[i])) min = stoi(vec[i]);
        if(max< stoi(vec[i])) max = stoi(vec[i]);
    }
//    cout<<"최소값:"<<min<<endl;
//    cout<<"최대값:"<<max;
    answer=to_string(min)+" "+to_string(max);
    return answer;
}



int main(int argc, const char * argv[]) {
    cout<<solution("-1 -2 -3 -4");
    return 0;
}
