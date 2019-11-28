//
//  main.cpp
//  Carpet
//
//  Created by 조윤영 on 27/11/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int area = brown+ red; //카펫의 넓이
    int width = 0;
    
    int limit = (int)sqrt(area);
    for(int i=3; i<=limit; i++) {
        width = area/i;
        
        if(area%i == 0 && width >= i) { //가로 길이가 정수로 나누어 떨어지는지 & 세로 길이보다 큰지 확인
            if((width-2)*(i-2) == red){
                cout<<width<<","<<i<<endl;
                answer.push_back(width);//가로 길이 집어넣고
                answer.push_back(i);//세로 길이 집어넣고
            }
            
        }
    }
    
    return answer;
}
int main(int argc, const char * argv[]) {
    solution(24,24);
    return 0;
}

//48

/*
 16
 3
 
 12
 4
 
 9
 5
 
 8
 6
 */

