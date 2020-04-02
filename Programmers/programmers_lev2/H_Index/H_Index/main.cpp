//
//  main.cpp
//  H_Index
//
//  Created by 조윤영 on 12/12/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] <= i + 1) {
            return i;
        }
    }
    return 0;
}


int solution2(vector<int> citations) {
    int answer = 0;
    vector<int> temp;
    
    int upperHcnt = 0;
    int h=0;
    int cnt = 1000;
    bool flag = false;
    
    sort(citations.begin(), citations.end(), greater<int>());
   
    for(int i=0; i<citations.size(); i++) {
       
        upperHcnt = 0;
        h = citations[i];

        for(int j=0; j<citations.size(); j++) {
            if(h<=citations[j])upperHcnt++;
        }
        if(upperHcnt >=h){
            flag = true;
            break;
        }
    }
    
    if(flag == false) h = 0;

    while(cnt >=h){
        h+=1;
        cnt=0;
        for(int i=0; i<citations.size(); i++) {
            if(h<=citations[i])cnt++;
        }
    }
    answer = h-1;


    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> citations = {2};
    cout<<solution(citations);
    return 0;
}
