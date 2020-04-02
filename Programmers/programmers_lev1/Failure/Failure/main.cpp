//
//  main.cpp
//  Failure
//
//  Created by 조윤영 on 12/03/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
//6,7,9,13
map<int, double> m;

bool compare(const int &a, const int &b) {
    if(m[a] > m[b])return true; //내림차순
    else if(m[a] == m[b]) {
        if(a < b)return true; //오름차순
        else return false;
    }else {
        return false;
    }
}

vector<int> solution(int N, vector<int> stages) {
    
    vector<int> answer;

    vector<pair<int, int>> temp;
    
    temp.assign(N+1, {0,0});
    
    //temp first-> 해당 숫자에 걸쳐진 클리어하지 못한 사람들 / second-> 해당 숫자와 같거나 넘은 사람들
    for(int i=0; i<stages.size(); i++) {
        int userStage = stages[i]-1;
        
        temp[userStage].first +=1; //클리어하지 못한 사람에 추가
        
        for(int j=0; j<=userStage; j++) { //현재 스테이지까지 방문했던 곳 증가
            temp[j].second +=1;
        }
    }
    
    vector<int> failure(N, 0);
    
    for(int i=0; i<failure.size(); i++) {
        double result;
        
        //0을 나누는 경우 컴파일 에러가 나는 환경이 있으므로 주의해서 풀 것.
        if((double)temp[i].first!= 0 && (double)temp[i].second !=0) {
            result = (double)temp[i].first/temp[i].second; //(*)
        }else{
            result = 0;
        }
        
        m.insert(make_pair(i, result));
        failure[i] = i;
    }

    sort(failure.begin(), failure.end(), compare);
    
    for(int i=0; i<failure.size(); i++) {
        
        answer.push_back(failure[i]+1);
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    int N = 4;
    vector<int> stages = {4,4,4,4,4};
    solution(N, stages);
    return 0;
}
