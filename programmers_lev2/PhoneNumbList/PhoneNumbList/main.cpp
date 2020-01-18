//
//  main.cpp
//  PhoneNumbList
//
//  Created by 조윤영 on 18/01/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Hash를 활용한 풀이
bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i=0; i<phone_book.size()-1; i++) {
        if(phone_book[i] == phone_book[i+1].substr(0, phone_book[i].size()))return false;
    }
    return answer;
}

//단순반복문을 활용한 풀이
//:효율성은 충족하지만 최적의 정답X
bool solution2(vector<string> phone_book) {
    bool answer = true;
    
    string preFix;
    int preFixSize = 0;
    int includePrefix = 0;
    //효율성 업업
    sort(phone_book.begin(), phone_book.end());
    //시간복잡도 : O(n^2)
    for(int i=0; i<phone_book.size(); i++) {
        preFix = phone_book[i];
        preFixSize = phone_book[i].size();
        
        for(int j=0; j<phone_book.size(); j++) {
            includePrefix = 0;
            
            if(j == i)continue;
            
            if(preFixSize <phone_book[j].size()) {
                if(preFix == phone_book[j].substr(0, preFixSize))return false;
            }
        }
    }

    return true;
}

int main(int argc, const char * argv[]) {
    vector<string> phone_book {"119","97674223","1195524421"};
    cout<<solution(phone_book);
    return 0;
}
