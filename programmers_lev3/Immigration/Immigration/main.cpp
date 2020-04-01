//
//  main.cpp
//  Immigration
//
//  Created by 조윤영 on 01/04/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    
    long long sum = 0;
    
    long long min = 1;
    long long max = (long long)times.back()*n; //가장 느린 심사관이 모든 사람들을 심사 완료할 수 있는 최소 시간을 찾을 때
    long long mid = (min + max)/2;
    long long answer = max;
    
    while(min <= max) {
        sum = 0;
        mid = (min+max)/2;
        
        for(int i=0; i<times.size(); i++) {
            sum += mid/times[i];//평균을 각 심사관이 한 명을 심사하는데 걸리는 시간을 나눈 몫을 더한다.
        }
        
        if(sum < n)min = mid +1;
        else{
            if(mid < answer)answer = mid;
            max = mid -1;
        }

    }
    
    
    return answer;
}

int main(int argc, const char * argv[]) {
    int n = 6;
    vector<int> times = {7,10};
    cout<<solution(n,times);
    return 0;
}
