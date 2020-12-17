//
//  main.cpp
//  FlipString
//
//  Created by 조윤영 on 2020/08/08.
//  Copyright © 2020 조윤영. All rights reserved.
//
//문자열 뒤집기

#include <iostream>

using namespace std;

string words;

void input() {
    cin>>words;
}

//머리가 나쁘면 손이 고생한다더니!
int solution() {
    int answer = 0;
    
    while(true)  {
        int zeroCnt = 0;
        int  oneCnt = 0;
        char  currentNumb = '2';
        
        for(char c: words) {
            if(c != currentNumb) {
                currentNumb = c;

                if(currentNumb == '0') zeroCnt++;
                else oneCnt++;
            }
        }
        
        if((zeroCnt == 0 && oneCnt == 1) || (zeroCnt == 1 && oneCnt == 0)) return answer;
        
        bool findSequence = false;
        
        if(zeroCnt >= oneCnt) {
            for(int i=0; i<words.size(); i++ ) {
                if(words[i] == '1') {
                    findSequence = true;
                    words[i] = '0';
                } else if(words[i] == '0' && findSequence == true) break;
            }
        } else {
            for(int i=0; i<words.size(); i++ ) {
                if(words[i] == '0') {
                    findSequence = true;
                    words[i] = '1';
                } else if(words[i] == '1' && findSequence == true) break;
            }
        }
        
        answer++;
    }
}

//생각의 전환 위의 2N의 계산을 N으로 줄이려면?
int solution2() {
    int answer = 0;
    int count0 = 0;
    int count1 = 0;
    
    if (words[0] == '1') count0++;
    else count1++;
    
    for (int i=0; i<words.size(); i++) {
        if(words[i] != words[i+1]) {
            if(words[i+1] == '1') count0++;
            else count1++;
        }
    }
    
    answer = min(count0, count1);
    return answer;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    cout<<solution2()<<"\n";
    return 0;
}
