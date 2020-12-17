//
//  main.cpp
//  SugarDelivery
//
//  Created by 조윤영 on 2020/11/22.
//
//설탕 배달
//Dynamic Programming 로직 - 5kg 봉지 사용을 기준으로, 모든 시도를 해봄으로써 어떤 방법이 가장 최소의 봉지 개수를 사용하는지 알아내는 방식
//https://www.acmicpc.net/problem/2839

#define MAX_SIZE 5001
#include <iostream>
using namespace std;

int N = 0;
int dp[MAX_SIZE];
void input() {
    cin>>N;
}

int solution() {
    
    int cnt = N / 5; //cnt: 5kg 봉지의 사용 최대 수
    int weight = 0;
    
    while(cnt >= 0) {
        weight = N - 5 * cnt; //cnt개수만큼의 5kg 봉지를 사용하고 남은 무게
        if(weight % 3 == 0) return cnt + weight / 3; //5kg 봉지 개수 + 3kg 봉지 개수
    
        cnt--;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    cout<<solution()<<"\n";
    return 0;
}
