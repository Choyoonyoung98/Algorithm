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

//효율성 테스트 통과 못한 내 풀이
int solution(vector<int> people, int limit) {
    int answer = 0;
    int n = people.size();
    
    vector<int> greaterPeople = people;
    sort(people.begin(), people.end());
    sort(greaterPeople.begin(), greaterPeople.end(), greater<int>());
    
    vector<bool> visited(n,false);

    
    for(int i=0; i<greaterPeople.size(); i++) {
        
        if(visited[i] != true) {
            visited[i] = true;
            answer+=1;
            for(int j=0; j<people.size(); j++) {
                if(j !=abs(n-i-1) && visited[n-j-1] != true && greaterPeople[i]+people[j]<= limit ){
                    visited[n-j-1]= true;
                    break;
                }
            }
        }
    }
    return answer;
}

//불필요한 벡터 배열 제거
int solution2(vector<int> people, int limit) {
    int answer = 0;
    int n = people.size();

    sort(people.begin(), people.end(), greater<int>());
    
    vector<bool> visited(n,false);
    
    
    for(int i=0; i<people.size(); i++) {
        if(visited[i] != true) {
            visited[i] = true;
            answer+=1;
            for(int j=(n-1); j>=0; j--) {
                if(j !=i && visited[j] != true && people[i]+people[j]<= limit ){
                     visited[j]= true;
                    break;
                }
            }
        }
    }
    return answer;
}

//다른 사람의 풀이
int solution3(vector<int> people, int limit) {
    int answer = 0;
    int left_point = 0; int right_point = people.size() - 1;
    sort(people.begin(), people.end(), greater<int>());//80 50 50 50
    
    while(left_point < right_point + 1) {
        if (people[left_point] + people[right_point] <= limit)
            right_point--;
        left_point++;
        answer++;
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> people = {70, 50, 80, 50};
    int limit = 100;
    cout<<solution2(people, limit);
    return 0;
}
