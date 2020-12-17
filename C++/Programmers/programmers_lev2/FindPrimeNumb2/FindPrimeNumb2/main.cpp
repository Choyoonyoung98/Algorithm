//
//  main.cpp
//  FindPrimeNumb2
//
//  Created by 조윤영 on 26/11/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>

using namespace std;
bool checkNumb(int n, string numbers);

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end(), greater<>());
    vector <bool> visited(stoi(numbers)+1);//71개의 숫자의 방문 여부를 저장

    for(int i=2; i<=stoi(numbers); i++) {

        //아직 걸러지지 않은 숫자이며, 종이조각에 적힌 숫자로 구성된 숫자라면? answer++
        if(visited[i] == false && checkNumb(i, numbers)) answer++;
        
        //종이조각에 적힌 숫자는 아니지만 방문한 적 없는 숫자일 경우,
        if(visited[i] == false) {
            //종이조각에 적힌 숫자가 아니라면 제거
            //이와 관련된 배수들은 소수가 아니므로, 에라토네스의 체로 거르면 조회 횟수를 줄일 수 있다.
            for(int j=i; j<=stoi(numbers); j+=i) visited[j] = true;
        }
    }
    
    return answer;
}

/* 종이조각에 적힌 숫자로 구성된 숫자인지 판단하는 함수*/
bool checkNumb(int n, string numbers) {
    vector<bool> visited(numbers.size());//각 숫자종이 방문 여부를 저장
    bool flag = false;
    
    while(n!= 0) {
        flag = false;
        int checkN = n%10; //각 자리 숫자 확인
        
        for(int i=0; i< numbers.size(); i++) {
            if(visited[i] == false && checkN == numbers[i]-'0') {
                visited[i] =true;
                flag = true;
                break;
            }
        }

        if(flag == false) return false;
        n/=10;
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    cout<<solution("17");
    return 0;
}
