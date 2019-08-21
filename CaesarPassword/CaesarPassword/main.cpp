//
//  main.cpp
//  CaesarPassword
//
//  Created by 조윤영 on 20/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//*********************************************
//대문자,소문자 전환 라이브러리
//#include <cctype>
//*********************************************

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*비효율의 끝판왕 윤영코드*/
string solution(string s, int n) {
    string answer = s;
    vector<string> bigVec{"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    vector<string> smallVec{"a","b","c","d","e","f"
        ,"g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

    for(int i=0; i<s.length(); i++) {
        //대문자일 경우,
        
        if(find(bigVec.begin(), bigVec.end(), answer.substr(i,1))!= bigVec.end()) {
            auto result = bigVec.begin();
            result = find(bigVec.begin(), bigVec.end(), answer.substr(i,1));
            
            answer.replace(i,1, bigVec[(distance(bigVec.begin(), result)+n)%26]);
            
        }
        //소문자일 경우,
        else if(find(smallVec.begin(), smallVec.end(), answer.substr(i,1))!= smallVec.end()){
            auto result = smallVec.begin();
            result =  find(smallVec.begin(), smallVec.end(), s.substr(i,1));
            answer.replace(i,1, smallVec[(distance(smallVec.begin(), result)+n)%26]);
            
        }
    }
    return answer;
}

/*아스키코드를 공부한다면,*/
string solution2(string s, int n){
    string answer = "";
    
    for(int i=0; i<s.size(); i++) {
        //빈칸이라면,
        if(s[i] == 32) answer.push_back(s[i]);
        //대문자라면,
        else if ((91 <=s[i]+n) && (s[i]<91)) answer.push_back(s[i]+n-26);
        //소문자라면,
        else if((123 <=s[i]+n) && (96<s[i])) answer.push_back(s[i]+n-26);
        else answer.push_back(s[i]+n);
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    string s = "a H b";
    int n = 4;
    cout<<solution(s, n)<<endl;
    cout<<solution(s,n)<<endl;
    return 0;
}

