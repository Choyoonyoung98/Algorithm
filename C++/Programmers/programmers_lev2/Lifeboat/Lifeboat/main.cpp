//
//  main.cpp
//  Lifeboat
//
//  Created by 조윤영 on 27/12/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

//다른 사람의 풀이
int solution3(vector<int> people, int limit) {
    int answer = 0;
    int left_point = 0;
    int right_point = people.size() - 1;
    sort(people.begin(), people.end(), greater<int>());//80 50 50 50
    
    while(left_point < right_point + 1) {
        if (people[left_point] + people[right_point] <= limit) right_point--;
        
        left_point++;
        answer++;
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> people = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int limit = 100;
    cout<<solution3(people, limit);
    return 0;
}
