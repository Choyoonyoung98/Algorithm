//
//  main.cpp
//  JoyStick
//
//  Created by 조윤영 on 27/12/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
//https://programmers.co.kr/learn/courses/30/lessons/42860

#include <string>
#include <iostream>

using namespace std;

 int position = 0;
int findCursorDirection(string name, string  temp) {
    int move = 0;
    for(move = 1; move<name.length(); move++) {
        int searchRightIndex = (position+move) % name.length();
        int searchLeftIndex = (position+ name.length() - move) % name.length();
        
        if(name[searchRightIndex] != temp[searchRightIndex]) {
            position = searchRightIndex;
            return move;
        } else if(name[searchLeftIndex] != temp[searchLeftIndex] ) {
            //여기서 들었던 의문점: position - move 해도 되지않나?
            //그것에 대해 찾은 답: 0번째 인덱스의 경우에는 -1이 되기 때문에 이러한 마이너스 인덱스를 찾는 것을 방지하기 위해
            position = searchLeftIndex;
            return move;
        }
    }
    return move;
}

int solution(string name) {
    int answer = 0;
    string temp(name.length(), 'A'); //name.length()만큼 A로 채워서 초기화
    
    while(true) {
        temp[position] = name[position];
        answer += (name[position] - 'A'> 1+'Z'- name[position] )? 'Z'+1-name[position] : name[position] - 'A';
        if(temp == name) break; //모든 자리에 대해 계산 완료했을 경우
        
        //왼쪽으로 갈지 오른쪽으로 갈지 정하기
        answer += findCursorDirection( name, temp);
    }
   
    return answer;
}

int main(int argc, const char * argv[]) {
    cout<<solution("JEROEN");
    return 0;
}
