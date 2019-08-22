//
//  main.cpp
//  NoneSameNumb
//
//  Created by 조윤영 on 09/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
/*배열 arr가 주어집니다. 배열 arr의 각 원소는 숫자 0부터 9까지로 이루어져 있습니다. 이때, 배열 arr에서 연속적으로 나타나는 숫자는 하나만 남기고 전부 제거하려고 합니다. 단, 제거된 후 남은 수들을 반환할 때는 배열 arr의 원소들의 순서를 유지해야 합니다. 예를 들면,
 
 arr = [1, 1, 3, 3, 0, 1, 1] 이면 [1, 3, 0, 1] 을 return 합니다.
 arr = [4, 4, 4, 3, 3] 이면 [4, 3] 을 return 합니다.
 배열 arr에서 연속적으로 나타나는 숫자는 제거하고 남은 수들을 return 하는 solution 함수를 완성해 주세요.*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename Iter>
void print(Iter begin, Iter end) {
    while(begin !=end) {
        cout<<"["<<*begin <<"]";
        begin++;
    }

    cout<<endl;
}

//같은 숫자는 배열에 하나씩만 남게 한다고 이해했을 때 만든 알고리즘(문제에 대한 잘못된 이해)
vector<int> solution2(vector<int> arr)
{
    vector<int> answer = arr;
    
    
    
    for(int i=0; i<answer.size(); i++) {//비교할 arr기준 값

        answer.erase(remove(answer.begin()+1+i, answer.end(), answer[i]),answer.end());
    }
    
    return answer;
}

//나의 정답
vector<int> solution(vector<int> arr)
{
    vector<int> answer = arr;
    
    for(int i=0; i<answer.size()-1; i++) {

        
        if(answer[i+1]==answer[i]){
            answer[i]=-1;
        }
    }

    answer.erase(remove(answer.begin(),answer.end(), -1), answer.end());

    return answer;
}
//다른 사람의 정답: unique를 활용
vector<int> solution3(vector<int> arr)
{
    vector<int> answer = arr;
    
    answer.erase(unique(arr.begin(), arr.end()),arr.end());
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> vec{1,0,0,0};
    solution(vec);
    
    return 0;
}
