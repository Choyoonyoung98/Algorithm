//
//  main.cpp
//  DeployingSoldiers
//
//  Created by 조윤영 on 2020/09/01.
//  Copyright © 2020 조윤영. All rights reserved.
//
//LIS(최장 증가 부분 수열 문제)
//https://www.acmicpc.net/problem/18353
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
#define MAX_SIZE 2000
using namespace std;

int N, X = 0;
vector<int> soldiers;
int dp[MAX_SIZE];
void input() {
    cin>> N;
    soldiers.assign(N, 0);
    for(int i=0; i<N; i++) {
        cin>>soldiers[i];
    }
}

//O(N^2)
int solution() {
    int answer = 0;
    
    //LIS는 오름차순 배열에 대해 적용되는 알고리즘이므로 순서를 뒤집는다.
    reverse(soldiers.begin(), soldiers.end());
    dp[0] = 1;
    for(int i=1; i<N; i++) {
        dp[i] = 1; //DP 테이블 초기화
        for(int j=0; j<i; j++) {
            if(soldiers[j] < soldiers[i]) dp[i] = max(dp[i], dp[j]+1);
        }
    }
    
    for(int i=0; i<N; i++) answer = max(answer, dp[i]);
    return N- answer;
}

//O(nlogn): 95% 테스트케이스 통과
int solution2() {
    int answer = 0;
    
    reverse(soldiers.begin(), soldiers.end());
    
    dp[0] = soldiers[0];
    int idx = 0;
    for(int i=1; i<N; i++) {
        int pos = 0;

        if(dp[idx] > soldiers[i]) {
            for(int j=idx; j>=0; j--) {
                if(dp[j] < soldiers[i]) {
                    pos = j+1;
                    break;
                }
                else if(dp[j] == soldiers[i]) {
                    pos = j;
                    break;
                }
            }
            
            answer++;
            dp[pos] = soldiers[i];
            
        } else dp[++idx] = soldiers[i];
    }
    return answer;
}

//O(nlogn)
int solution3() {
    vector<int> vec;
    vec.push_back(INF);
    cin>> N;
    int x= 0;
    for(int i=0; i<N; i++) {
        cin>> x;
        x = -x;
        if(vec.back() < x) vec.push_back(x);
        else {
            auto it = lower_bound(vec.begin(), vec.end(), x);
            *it = x;
        }
    }
    
    return N - vec.size();
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<solution3()<<"\n";
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
#define MAX_SIZE 2000
using namespace std;

int N, X = 0;
vector<int> soldiers;
int dp[MAX_SIZE];
void input() {
    cin>> N;
    soldiers.assign(N, 0);
    for(int i=0; i<N; i++) {
        cin>>soldiers[i];
    }
}

//O(N^2)
int solution() {
    int answer = 0;
    
    //LIS는 오름차순 배열에 대해 적용되는 알고리즘이므로 순서를 뒤집는다.
    reverse(soldiers.begin(), soldiers.end());
    dp[0] = 1;
    for(int i=1; i<N; i++) {
        dp[i] = 1; //DP 테이블 초기화
        for(int j=0; j<i; j++) {
            if(soldiers[j] < soldiers[i]) dp[i] = max(dp[i], dp[j]+1);
        }
    }
    
    for(int i=0; i<N; i++) answer = max(answer, dp[i]);
    return N- answer;
}

//O(nlogn): 95% 테스트케이스 통과
int solution2() {
    int answer = 0;
    
    reverse(soldiers.begin(), soldiers.end());
    
    dp[0] = soldiers[0];
    int idx = 0;
    for(int i=1; i<N; i++) {
        int pos = 0;

        if(dp[idx] > soldiers[i]) {
            for(int j=idx; j>=0; j--) {
                if(dp[j] < soldiers[i]) {
                    pos = j+1;
                    break;
                }
                else if(dp[j] == soldiers[i]) {
                    pos = j;
                    break;
                }
            }
            
            answer++;
            dp[pos] = soldiers[i];
            
        } else dp[++idx] = soldiers[i];
    }
    return answer;
}

//O(nlogn)
int solution3() {
    vector<int> vec;
    vec.push_back(INF);
    cin>> N;
    int x= 0;
    for(int i=0; i<N; i++) {
        cin>> x;
        x = -x;
        if(vec.back() < x) vec.push_back(x);
        else {
            auto it = lower_bound(vec.begin(), vec.end(), x);
            *it = x;
        }
    }
    
    return N - vec.size();
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<solution3()<<"\n";
    return 0;
}
