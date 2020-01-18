//
//  main.cpp
//  CreatePrimeNumb
//
//  Created by 조윤영 on 15/01/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

int maxNum = 0;

//나올 수 있는 3개 숫자의 합 알아보기, + 합 중 가장 큰 값 알아보기
vector<int> addNums(vector<int> &nums) {
    
    vector<int> addedNums;
    
    for(int i=0; i< nums.size()-2; i++) {
        for(int j=i+1; j<nums.size()-1; j++) {
            for(int k=j+1; k<nums.size(); k++) {
                int temp = nums[i] + nums[j] + nums[k];
                
                
                maxNum = (temp>maxNum)?temp:maxNum;

                addedNums.push_back(temp);
            }
        }
    }
    
    return addedNums;
}

int solution(vector<int> nums) {
    int answer = 0;
    
    vector<int> addedNums;
    vector<bool> isPrime;
    
    maxNum = 0;
    
    addedNums = addNums(nums);
    isPrime.assign(maxNum+1, true);//assign - maxNum+1만큼 true값 할당
    
    
    //0~ 최대합까지의 숫자 중 소수인 숫자만 true가 되도록
    //에라토스테네스의 체 알고리즘
//    for (int i = 2; i <= maxNum; i++) {
//        if (isPrime[i] == true) {
//            for (int j = 2; i * j <= maxNum; j++) {
//                isPrime[i * j] = false;
//            }
//        }
//    }
    for(int i=2; i<=sqrt(maxNum); i++) {
        if(isPrime[i] == false)continue;
        
        for(int j=i*2; j<=maxNum; j+=i) {
            isPrime[j] = false;
        }
    }

    for(int i=0; i<addedNums.size(); i++) {
        if(isPrime[addedNums[i]]) {
            answer++;
        }
    }

    return answer;
}

//void pickThreeNumb(int index, vector<int>& nums, vector<int>& visited, vector<int>& history, int cnt) {
//    int sum = 0;
//    int isPrime = true;
//    if(cnt == 3) {
//        cout<<"3자리 숫자 채워짐";
//
//        for(int i=0; i<history.size(); i++) {
//            cout<<"["<<history[i]<<"]";
//            sum+=history[i];
//        }
//
//        for(int i=1; i<sum; i++) {
//            if(i==1 || i==2)continue;
//            if(sum%i ==0){
//                isPrime = false;
//                break;
//            }
//        }
//
//        cout<<"*****"<<sum<<"*****";
//        if(isPrime == true){
//            cout<<"소수!";
//            answer++;
//        }
//        cout<<endl;
//        return;
//    }
//
//    for(int i=index; i<nums.size(); i++) {
//        cout<<"i:("<<i<<")";
//        if(visited[i] !=true) {
//            visited[i] = true;
//            history.push_back(nums[i]);
//            cout<<nums[i]<<"-";
//            pickThreeNumb(i+1, nums, visited,history, cnt+1);
//        }
//        visited[i] = false;
//        history.pop_back();
//    }
//}
//int solution(vector<int> nums) {
//
//    vector<int>visited(nums.size(), false);
//    vector<int>history;
//    for(int i=0; i<=nums.size()-3; i++) {
//        pickThreeNumb(i, nums, visited,history, 0);
//    }
//    cout<<"정답은?"<<answer<<endl;
//    return answer;
//}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,7,6,4};
    
    cout<<solution(nums);
    return 0;
}
