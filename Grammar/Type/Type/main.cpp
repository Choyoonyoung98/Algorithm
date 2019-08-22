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
    /*int를 바꿔보자*/
    int ITest = 123;
    string s_iTest = to_string(ITest);
    
    /*string을 바꿔보자*/
    string STest  = "123";
    int i_Stest = stoi(STest);
    long l_Stest = stol(STest);
    long long ll_Stest = stoll(STest);
    
    /*char를 바꿔보자*/
    char CTest [5]= "10";
    int i_CTest = atoi(CTest);
    
    
    return 0;
}
