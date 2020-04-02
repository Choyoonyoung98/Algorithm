//
//  main.cpp
//  RamenFactory
//
//  Created by 조윤영 on 01/04/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//
//https://programmers.co.kr/learn/courses/30/lessons/42629

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    priority_queue<int> flour;
    
    int remain = stock;
    
    for(int i=0; i<dates.size(); i++)  {
        
        if(i !=0) {
            remain -= (dates[i]-dates[i-1]);
        }else{
            remain -= dates[i];
        }
        
        
        
        flour.push(supplies[i]);
        
        int nextDate = 0;
        if(i == dates.size()-1)nextDate = k;
        else nextDate = dates[i+1];

        //다음 공급날짜까지 밀가루가 부족할 경우
        while(remain - (nextDate-dates[i]) <0) {
            remain += flour.top();
            flour.pop();
                    
            answer++;
        }
    }
    
    return answer;
}

//20
//10, 15-5>0

int main(int argc, const char * argv[]) {
    
    int stock = 2;
    
    vector<int> dates = {1};
    vector<int> supplies = {10};
    int k = 10;
    
    //현재 공장에 남아있는 밀가루 수량:4
    
    //공장으ㅢ 고장으로 인해 앞으로 30일 이후에야 밀ㄹ가루를 공급받을 수 있기 때문에
    
    //총 24개를 공급받아야함
    //해외 공장에서 밀가루를 수입해야함
    //해외 공장에서 밀가루를 공ㄱ브할 수 있는 날짜: 4,10,14일
    //공급할 수 있는 수량은 각각 20,5,10
    
    cout<<solution(stock, dates, supplies, k);
    
    return 0;
}
