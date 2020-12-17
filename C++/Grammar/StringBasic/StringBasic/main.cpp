//
//  main.cpp
//  StringBasic
//
//  Created by 조윤영 on 18/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    if(s.length() == 4 || s.length() ==6 ){
        
        for (int i = 0; i < s.length(); i++)
        {
            if (!isdigit(s[i]))
                answer = false;
        }
    }else{
        answer = false;
    }

    return answer;
}

int main(int argc, const char * argv[]) {
    string s1 = "a234";
    cout<<solution(s1)<<endl;
    string s2 = "1234";
    cout<<solution(s2);
    
    return 0;
}
