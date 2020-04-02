//
//  main.cpp
//  makeBigNumb
//
//  Created by 조윤영 on 27/12/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
//int와 char를 바로 비교해도 되는 모양

#include <string>
#include <vector>


using namespace std;


string solution(string number, int k) {
    string answer = "";
    int numbMax = 0;
    int numbCount = 0;
    int checkBoundary = number.size() - k;
    
    for(int i=checkBoundary; i>0; i--) {
        numbMax = 0;
        numbCount = 0;
        for(int j=0; j<number.size()-i+1; j++) {
            if(numbMax < number[j]){
                numbMax = number[j];
                numbCount = j;
            }
        }
        
        number.replace(0, numbCount+1, " ");
        answer+=numbMax;
    }
    
    return answer;
}int main(int argc, const char * argv[]) {
    solution("1924",2);
    return 0;
}
