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
#include <algorithm>

using namespace std;

int N;

template <typename k>
void print(vector<k>& map) {
    for(const auto& m:map){
        cout<<m;
    }
    cout<<endl;
}

bool mysort(string a, string b){//compare 함수
    if(a.at(N)!=b.at(N)){
        return a.at(N) < b.at(N);   //N인덱스의 문자로 정렬
    }else{
    return a < b;   //사전순으로 정렬: 원래 정렬하는 방식
    }
    //return a.at(N)==b.at(N) ? a < b : a.at(N) < b.at(N);
    //return a[i] == b[i] ? a < b : a[i] < b[i];
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    answer = strings;
    N = n;
    sort(answer.begin(),answer.end(),mysort);
    print(answer);
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<string> strings{"sun","bed","car"};
    int n=1;
    solution(strings,n);
    return 0;
}
