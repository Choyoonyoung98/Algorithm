//
//  main.cpp
//  TargetNumber
//
//  Created by 조윤영 on 19/10/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int answer=0;


void dfs(vector<int> &numbers, int target, int sum, int depth) {
    if(depth >=numbers.size()) {
        if(sum == target) answer++;
        return;
    }
    dfs(numbers, target, sum+numbers[depth], depth+1);
    dfs(numbers, target, sum-numbers[depth], depth+1);
}

int solution(vector<int> numbers, int target) {
    
    dfs(numbers, target, numbers[0]*1, 1);
    dfs(numbers, target, numbers[0]*-1, 1);

    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> numbers(5,1);
    int target = 3;
    solution(numbers, target);
    cout<<answer;
    
   
    return 0;
}
