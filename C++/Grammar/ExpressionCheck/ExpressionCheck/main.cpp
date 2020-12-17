//
//  main.cpp
//  ExpressionCheck
//
//  Created by 조윤영 on 2020/09/25.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>

using namespace std;
int main(int argc, const char * argv[]) {
    //정규식 확인
    //1. 알파벳인지 확인
    string test1 = "a1";
    cout<<isalpha(test1[0])<<endl;
    cout<<isalpha(test1[1])<<endl;
    
    //OR
    char c = test1[0];
    if((65<= c && c<= 90) || (97 <= c && c <= 122)) cout<<"알파벳입니다.";
    else if(48 <= c && c<= 57) cout<<"숫자입니다";
    else cout<<"특수문자열입니다";
    
    //2. 대문자인지 소문자인지 확인
    cout<<isupper(c)<<endl;
    cout<<islower(c)<<endl;
    
    //3. 대문자->소문자 OR 소문자->대문자
    cout<<toupper(c)<<endl;
    cout<<tolower(c)<<endl;
    
    return 0;
}
