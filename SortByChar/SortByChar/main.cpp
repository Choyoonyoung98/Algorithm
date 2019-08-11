//
//  main.cpp
//  SortInMyWay
//
//  Created by 조윤영 on 11/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
/*
 문자열로 구성된 리스트 strings와, 정수 n이 주어졌을 때, 각 문자열의 인덱스 n번째 글자를 기준으로 오름차순 정렬하려 합니다. 예를 들어 strings가 [sun, bed, car]이고 n이 1이면 각 단어의 인덱스 1의 문자 u, e, a로 strings를 정렬합니다.
 */

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

template <typename K, typename V>
void map_print(map<K, V>& m) {
    for(auto itr = m.begin(); itr !=m.end(); ++itr) {
        cout<<"["<<itr->first<<" " <<itr->second<<"]";
    }
    cout<<endl;
}
template <typename T>
void print(vector<T>&  vec) {
    for(typename std::vector<T>::iterator itr = vec.begin(); itr !=vec.end(); ++itr) {
        cout<<"["<<*itr<<"]";
    }
    cout<<endl;
}

vector<string> solution(vector<string> strings, int n) {
    
    vector<string> answer;
    map<string, char> priority;
    vector<string>chars=strings;
    
    //우선순위와 묶어주기
    for(int i=0; i<chars.size(); i++) {
        priority.insert(make_pair(chars[i],charitem));
    }
    //    map_print(priority);
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<string> strings{"sun","bed","car"};
    int n=1;
    solution(strings,n);
    return 0;
}
