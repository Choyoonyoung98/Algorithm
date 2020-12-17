//
//  main.cpp
//  DividingNumb
//
//  Created by 조윤영 on 10/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
/*
 문제 설명
 array의 각 element 중 divisor로 나누어 떨어지는 값을 오름차순으로 정렬한 배열을 반환하는 함수, solution을 작성해주세요.
 divisor로 나누어 떨어지는 element가 하나도 없다면 배열에 -1을 담아 반환하세요.
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

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for(int i=0; i<arr.size();i++) {
        if(arr[i]%divisor==0)answer.push_back(arr[i]);
    }
    if(answer.begin() == answer.end())answer.push_back(-1);
    sort(answer.begin(), answer.end());
    print(answer.begin(), answer.end());
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> vec{5,8,7,10};
    int divisor = 5;
    solution(vec, divisor);
    
    return 0;
}
