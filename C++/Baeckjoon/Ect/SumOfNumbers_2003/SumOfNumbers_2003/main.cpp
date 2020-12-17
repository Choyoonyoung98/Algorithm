//
//  main.cpp
//  SumOfNumbers_2003
//
//  Created by 조윤영 on 01/04/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//
//투포인터 시간복잡도: O(N) -> 시간제한 0.5초 안에 가능
//https://www.acmicpc.net/problem/2003

//int sum = ++cnt: cnt+=1 한 다음에 sum의 값에 적용
//int sum = cnt++: 기존 cnt의 값을 sum에 적용해주고 cnt+=1하는 것

#include <iostream>
#include <vector>

using namespace std;

int N = 0;
int M = 0;
vector<int> numbs;


void input() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>> N >> M;
    
    int numb = 0;
    
    for(int i=0; i<N; i++) {
        cin>>numb;
        numbs.push_back(numb);
    }
}
void solution() {
    int answer = 0;
    
    int start = 0;
    int end = 0;
    int sum = numbs[0];
    
    while(end<N) {
        
        //end가 뒤로 계속 이동하면서 합이 찾고자하는 M보다 더 커질 경우
        //시작점을 한단계 앞으로 이동하면서 합에서 빼주기
        if(sum >M){
            
            if(start == end){
                sum+=numbs[++end];
            }else{
                sum-=numbs[start++];//해당 숫자를 빼고,
//                start++;//다음 인덱스로 넘어간다.
            }
            
            //low가 end를 역전하면 low에서부터 다시 시작(초기화)
//            if(start>end && start<N){
//                end = start;
//                sum = numbs[start];
//            }
        }
        else if(sum < M)sum += numbs[++end];
        //위의 사항에 해당하지 않았을 때에는 일반적으로 end를 뒤로 이동하면서 해당 값을 sum에 더해준다.
        else if(sum == M){
            answer++;
            sum += numbs[++end];
        }
        
    }
    
    cout<<answer<<"\n";
    
}
int main(int argc, const char * argv[]) {
    input();
    solution();
    return 0;
}
