//
//  main.cpp
//  EditDistance
//
//  Created by 조윤영 on 2020/09/02.
//  Copyright © 2020 조윤영. All rights reserved.
//
//Minimum Edit Distance 알고리즘
//편집 거리
//

#include <iostream>
#include <vector>
#define MAX_SIZE 5001
using namespace std;

string A;
string B;
void input() {
    cin>> A >> B;
}

//cat cut
int solution() {
    int  n = A.size();
    int m = B.size();
    
    // 다이나믹 프로그래밍을 위한 2차원 DP 테이블 초기화
    vector<vector<int> > dp(n + 1, vector<int>(m + 1));
    for(int i=1; i<= n;  i++) dp[i][0] = i;
    //((0,0,0,0),(1,0,0,0),(2,0,0,0),(3,0,0,0))
    for(int j=1; j<=m; j++) dp[0][j] = j;
    /*(0,1,2,3) //아무것도 없는 상태로부터 해당 문자의 거리(distance)
     (1,0,0,0)
     (2,0,0,0)
     (3,0,0,0)
     */
    
    for(int i=1; i<=n; i++)  {
        for(int j=1; j<=m; j++) {
            //c:c dp[1][1] = dp[0][0] = 0;
            //c:u dp[1][2] = 1+ min(dp[1][1], dp[0][2], dp[0][1])
            //1 + min(0,2,1)
            //문자열이 같다면, [왼쪽 위]에 해당하는 수를 그대로 대입 가능
            if(A[i-1] ==  B[j-1]) dp[i][j] = dp[i-1][j-1];
            //문자가 다르다면, 세 가지 경우 중에서 최소값 찾기
            //1. 삽입(왼쪽), 2. 삭제(위쪽), 3. 교체(왼쪽 위) 중에서 최소 비용을찾아 대입,
            else dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
        }
    }
    return dp[n][m];
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    cout<<solution()<<"\n";
    return 0;
}
