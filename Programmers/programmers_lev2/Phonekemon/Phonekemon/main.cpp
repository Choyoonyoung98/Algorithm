//
//  main.cpp
//  Phonekemon
//
//  Created by 조윤영 on 23/03/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX_SIZE 200000

using namespace std;

int visited[MAX_SIZE] = {false};
int solution(vector<int> nums)
{
    int answer = 0;
    
    int kindSize = nums.size()/2; // n/2
    
    for(int i=0; i<nums.size(); i++) {
        
        if(answer == kindSize)return answer;
        if(!visited[nums[i]]) {//선택한 적이 없던 포켓몬이라면?
            visited[nums[i]] = true;
            answer++;
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    
    vector<int> nums = {3,3,3,2,2,2};
    cout<<solution(nums);
    return 0;
    
}
