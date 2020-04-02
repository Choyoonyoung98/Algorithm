//
//  main.cpp
//  FineRectangle
//
//  Created by 조윤영 on 14/01/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
using namespace std;

long long solution(int w,int h)
{
    int gcFactor = 0;
    long long answer = (long long)w * (long long )h;
    //long long 자료값에 어떤 값을 넣으려면 그 또한 long long 자료형태여야 한다!
    int start = (w<h)? w: h;
    
    //블럭 뭉치의 총 갯수 계산
    for(int i= start; i>0; i--) {
        if((w%i == 0)&& (h%i == 0)) {
            gcFactor = i;
            break;
        }
    }
    cout<<gcFactor;
    
    //블록 뭉치 안에서 선이 지나가는 사각형 개수: (w/최대공약수) + (h/최대공약수)-1
    //전체 블록 수 - 선이 지나가는 사각형  전체 수
    answer = answer - gcFactor * ((w/gcFactor) + (h/gcFactor)-1);
    
    return answer;
}
int main(int argc, const char * argv[]) {
    solution(8,12);
    return 0;
}
