//
//  main.cpp
//  TwoEssenceSum
//
//  Created by 조윤영 on 31/07/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>

using namespace std;

/*속도 차이는 없지만 가독성 좋고 짜기 쉬운 수의 합 코드*/

long long sum(int begin, int end) {
    unsigned long answer = 0;

    //총 합: ((첫번째 수 + 맨 끝 수)* 총 더할 수의 개수)/2
    answer = ((begin+end)*(end-begin+1))/2;
    return answer;
}

int main(int argc, const char * argv[]) {
    cout<<sum(1,5)<<endl;
    return 0;
}
