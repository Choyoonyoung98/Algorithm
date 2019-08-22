//
//  main.cpp
//  Budget
//
//  Created by 조윤영 on 22/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
/*
 S사에서는 각 부서에 필요한 물품을 지원해 주기 위해 부서별로 물품을 구매하는데 필요한 금액을 조사했습니다. 그러나, 전체 예산이 정해져 있기 때문에 모든 부서의 물품을 구매해 줄 수는 없습니다. 그래서 최대한 많은 부서의 물품을 구매해 줄 수 있도록 하려고 합니다.
 
 물품을 구매해 줄 때는 각 부서가 신청한 금액만큼을 모두 지원해 줘야 합니다. 예를 들어 1,000원을 신청한 부서에는 정확히 1,000원을 지원해야 하며, 1,000원보다 적은 금액을 지원해 줄 수는 없습니다.
 
 부서별로 신청한 금액이 들어있는 배열 d와 예산 budget이 매개변수로 주어질 때, 최대 몇 개의 부서에 물품을 지원할 수 있는지 return 하도록 solution 함수를 완성해주세요.
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename Iter>
void print(Iter begin, Iter end) {
    while(begin !=end) {
        cout<<"["<<*begin <<"]";
        begin++;
    }
    cout<<endl;
}

//나의 더러운 풀이
int solution(vector<int> d, int budget) {
    int answer = 0;
    int sum = 0;
    
    for(int elem: d) {
        sum+=elem;
    }

    cout<<sum<<endl;
    if(sum <=  budget) {
        cout<<"모든 부서의 물품 구매가 가능합니다."<<endl;
        answer = d.size();

    }else{
        cout<<"모든 부서의 물품 구매가 불가능합니다."<<endl;
        sort(d.begin(), d.end());
        print(d.begin(), d.end());
        
        
        for(int i=d.size(); i>-1; i--) {
            sum -=d[i-1];
            d.pop_back();
            cout<<sum;
            print(d.begin(), d.end());
            
            if(sum <= budget) {
                answer = d.size();
                break;
            }
        }
    }
    return answer;
}

//다른 사람의 풀이
int solution2(vector<int> d, int budget) {
    sort(d.begin(), d.end());
    int i;
    for (i = 0; (budget=budget-d[i]) >= 0 && i < d.size(); i++) ;
    return i;
}


int main(int argc, const char * argv[]) {
    vector<int> input{1,3,2,5,4};
    int n = 9;
    cout<<solution(input, n);
    return 0;
}
