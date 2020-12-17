//
//  main.cpp
//  PioneerOfCatan
//
//  Created by 조윤영 on 02/01/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

#define MAX_SIZE 10000
#define MAX_RESOURCE 6
using namespace std;

int C = 0;
vector<int> useResource(MAX_RESOURCE,0); //numberCnt의 0번째는 편의상 이용하지 않는다.
int resource[MAX_SIZE] = {0};
int biggestTarget = 0;


vector<int> target;
vector<int> answer;
vector<int> resource_candidate;

vector<int> is_related;

int relatedMin = 1;


//2.또한 가능한 숫자가 여러개일 경우 그 후보 중에서 가장 적게 나타난 자원을,
//3.더 나아가 이 조건도 조건을 뽑을 수 없다면 번호가 작은 것을 선택한다.


//나중에 숫자 사용량 담아둔 배열 복사해서 내림차순 한 다음에 자르는게 좋을듯

void solution(int index, int prevResource) {
    
    //공통: 바로 전 위치의 숫자와 인접
    //3개와 인접할 때가 있고 2개와 인접할 때가 있음
    
    //2번째: 1 ()
    //3번째: 1, 2
    //4번째: 1, 3
    //5번째: 1, 4
    //6번째 숫자 2가 인접하는 숫자 위치: 1,5
    
    //*********************************************************//
    //7번째 숫자 3이 인접하는 숫자 위치: 1,2,6 (3)
    //=> [7] 1, 2, 7-1 (7-5 = 2)
    //*********************************************************//
    
    //8번째 숫자 1이 인접하는 숫자 위치: 2,7
    //=> [8] 2, 8-1 (8-5 = 3)
    //9번째 숫자 4가 인접하는 숫자 위치: 2,8
    //=> [9] 2, 9-1 (9-5 = 4)
    
    //*********************************************************//
    //10번째 숫자 5가 인접하는 숫자 위치: 2,3,9 (3)
    //=>[10] 2, 3, 10-1
    //*********************************************************//

    
    //11번재 숫자 1이 인접하는 숫자 위치: 3, 10
    //=> [11] 3, 11-1
    
    //*********************************************************//
    //12번째 숫자 2가 인접하는 숫자 위치: 3,4,11 (3)
    //=> [12] 3, 4, 11-1
    
    //*********************************************************//
    //13번째 숫자 3이 인접하는 숫자 위치: 4,12
    //=> [13] 4, 13-1
    //14번째 숫자 1이 인접하는 숫자 위치: 4,5,13 (3)
    //=> [14] 4,5, 14-1
    
    //5,14
    
    //잘은 모르겠지만 앞의 숫자가 짝수일때는 2번 반복
    //홀수일때는 1번 반복
    
    
    //3개가 인접할 때는 n, n+1, 해당번째K-1
    
    //자원의 수 : 5
    //3: (5+2)7, (5+5 = 5+(2*2+1))10, (5+7 = 5+(2*3+1))12, (5+9 = 5 + (2*4+1))14
    //=>도출 사실: 자원의 수가 5일 때, 인접하는 숫자가 3개인 위치는 (5+(2*n+1)), 이때 n>=1
    
    //그 이외에는 2개와 인접해 있음.
    
    cout<<"index:"<<index;
    
    int n =(2*relatedMin+6);

    if(index <=MAX_RESOURCE-1) {
        int currentResource = prevResource+1;
        resource[index] = currentResource;
        useResource[index]++;
        solution(index+1, currentResource);
    }
    else if(index == 6){
        for(int i=1; i<MAX_RESOURCE; i++) {
            if(i != 1 && i !=5) {
                
                cout<<"i:"<<i<<endl;
                resource[index] = i;
                useResource[index]++;
                break;
            }
        }
        solution(index+1, 0);
    }else{
        int start = index;
        for(int i=start; i<=biggestTarget; i++) {
            if(i == n) {
                //인접해있는 수가 3인 경우
                //인접해있기 때문에 사용할 수 없는 자원 수 스택에 넣어두고
                
                is_related.push_back(relatedMin);
                is_related.push_back(relatedMin+1);
                is_related.push_back(i-1);
                relatedMin++;
                int minCnt = 10000;
                    
                    for(int j=1; j<MAX_RESOURCE; j++) {
                        
                        for(int k=0; k<is_related.size(); k++) {
                            if(j != is_related[k]){
                                resource_candidate.push_back(j);
                                break;
                            }
                        }
                    }
                    for(int k=0; k<resource_candidate.size(); k++) {
                            int r = resource_candidate[k];
                            
                            if(minCnt>useResource[r])minCnt = useResource[r];
                        }
                        resource[i] = minCnt;
                        useResource[i]++;
                        
                        resource_candidate.clear();
                        is_related.clear();
            }else{
                //인접해있는 수가 2인 경우
                is_related.push_back(relatedMin);
                is_related.push_back(i-1);
                int minCnt = 10000;
                cout<<"target:"<<i<<"->";
                for(int j=1; j<MAX_RESOURCE; j++) {
                    
                    for(int k=0; k<is_related.size(); k++) {
                        if(j != is_related[k]){
                            resource_candidate.push_back(j);
                            cout<<j;
                            break;
                        }
                    }
                }
                cout<<endl;
                for(int k=0; k<resource_candidate.size(); k++) {
                        int r = resource_candidate[k];
                        
                        if(minCnt>useResource[r])minCnt = useResource[r];
                    }
                    resource[i] = minCnt;
                    useResource[i]++;
                    
                    resource_candidate.clear();
                    is_related.clear();
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int t = 0;
    
    cin>>C;
    
    for(int i=0; i<C; i++) {
        cin>> t;
        target.push_back(t);
    }
    
    sort(target.begin(), target.end(), greater<int>());
    
    //C-1

    biggestTarget = target[0]; //구해야하는 가장 큰 타겟을 집어넣는다.(100)
    
    
    resource[1] = 1;
    
    useResource[1]++; //사용 횟수 1 증가
    
    solution(2,1);
    
    sort(target.begin(), target.end());
    
    for(int i=1; i<14; i++) {
        cout<<i<<":"<<resource[i]<<endl;
    }
//    for(int i=0; i<C; i++) {
//
//        cout<<resource[target[i]]<<endl;
//    }
    
    return 0;
}
