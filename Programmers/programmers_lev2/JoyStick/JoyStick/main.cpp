//
//  main.cpp
//  JoyStick
//
//  Created by 조윤영 on 27/12/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
//개인적으로 문제에 대한 이해가 어려운 문제

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    vector<char> backWord ={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    
    vector<char> frontWord = backWord;
    sort(backWord.begin(), backWord.end(), greater<int>());
    
    string initName;
    
    int findFromFront = -1;
    int findFromBack = -1;
    
    int moveStick = 0;
    
    for(int i=0; i<name.size(); i++) {
        
        findFromFront = -1;
        findFromBack = -1;
        
        moveStick = 0;
        cout<<name[i];
        
        for(int j=0; j<frontWord.size(); j++) {
            cout<<"j:"<<j;
            if(name[i] == frontWord[j]) {
                findFromFront = j;
                cout<<"앞에서부터"<<j;
                break;
            }
            if(name[i] == backWord[j]) {
                findFromBack = j;
                cout<<"뒤에서부터"<<j;
                break;
            }
        }
        if(findFromFront ==findFromBack) moveStick = findFromFront;
        else{
            moveStick = (findFromFront !=-1)?findFromFront : (findFromBack+2);
        }
        
        cout<<"["<<moveStick<<"]"<<endl;
        answer+=moveStick;
        
    }

    return answer;
}

int main(int argc, const char * argv[]) {
    cout<<solution("ABABAAAAAAABA");
    return 0;
}
