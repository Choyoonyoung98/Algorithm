//
//  main.cpp
//  Type
//
//  Created by 조윤영 on 22/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    /*int -> string*/
    int ITest = 123;
    string s_iTest = to_string(ITest);
    
    /*string -> int*/
    string STest  = "123";
    int i_Stest = stoi(STest);
    /*string -> long*/
    long l_Stest = stol(STest);
    /*string -> long long*/
    long long ll_Stest = stoll(STest);
    
    /*char -> int*/
    char ch1='1';
    int num = ch1 - '0';
    cout<<num+1<<endl;
    //아스키코드를 보고싶다면?
    int numAscii = (int)ch1;
    cout << numAscii;  //49 ('1'의 아스키 코드 값)
    
    
    
    
    return 0;
}
