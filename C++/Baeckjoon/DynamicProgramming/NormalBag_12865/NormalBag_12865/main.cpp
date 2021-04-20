//
//  main.cpp
//  NormalBag_12865
//
//  Created by 조윤영 on 2021/04/18.
//
//평범한 배낭
/*
 배낭문제는
 - 물건을 쪼갤 수 있는 배낭문제
 - 물건을 쪼갤 수 없는 배낭문제
 두 가지로 분류됩니다
 
 물건을 쪼갤 수 있는 배낭문제의 경우는 가치가 큰 물건부터 담고 남은 무게만큼 물건을 쪼개는 방식으로
 그리디 알고리즘을 사용합니다.
 
 물건을 쪼갤 수 없는 배낭문제의 경우 동적계획법을 사용합니다.
 
 */
#define MAX_SIZE 100001
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K;
int dp[101][100001]; //물건의 개수, 무게 최대 크기만큼
struct Info {
    int weight;
    int value;
    Info(int _weight, int _value) {
        weight = _weight;
        value = _value;
    };
};
bool operator < (Info a, Info b) {
    return a.value < b.value;
}

vector<Info> object_list;

void input() {
    cin  >> N >> K;
    int w,v;
    object_list.push_back(Info(0, 0));
    for(int i=0; i<N; i++) {
        cin>> w >>v;
        object_list.push_back(Info(w, v));
    }
}

int solution() {
    int answer = 0;
    
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=K; j++) {
            // =>i번째 물건을 통해 j의 가방 무게 만들기
            Info ob = object_list[i];
            if( j >= ob.weight) dp[i][j] = max(dp[i-1][j], dp[i-1][j - ob.weight] + ob.value);
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[N][K];
}

int main(int argc, const char * argv[]) {
    input();
    cout<<solution()<<"\n";
    
    return 0;
}
