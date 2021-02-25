//
//  main.cpp
//  MinimizeSalesDecline72416
//
//  Created by 조윤영 on 2021/02/25.
//
//DP조건
//1. 자신이 포함되어 있을 때
//2. 자신이 포함되지 않았을 때
//직원번호 1은 항상 CEO라고 정해두었음!!!! 제한사항 꼼꼼히 읽기
#define INF 1e9
#define MAX_SIZE 300001
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
vector<int> salesInfo;
vector<vector<int>> graph(MAX_SIZE);
int dp[MAX_SIZE][2];
void makeTree(vector<vector<int>> &links) {
    //문제에서 주어진 links를 통해 트리 구성
    for(int i=0; i<links.size(); i++) {
        int leader = links[i][0];
        int follower = links[i][1];
        graph[leader].push_back(follower);
    }
}

int solve(int index, bool include) {
    int result = 0;
    int cost = dp[index][include];
    if(cost != -1) return cost;
    int sum = 0;
    if(include) { //본인이 워크숍 가는 인원에 포함된다면, 해당 팀원 직원을 포함해도 되고, 안해도 된다
        sum += salesInfo[index-1];
        for(int follower: graph[index]) {
            sum += min(solve(follower, true), solve(follower, false));
        }
        return sum;
    } else { //본인이 워크숍에 가지 않으면, 팀원 직원 중 한 명 이상이 가야한다
        //본인 팀에 부하 직원이 1명 이상이라면 diff = INF, 아무도 없다면 0
        int diff = graph[index].size() > 0 ? INF : 0;
        bool participationExist = false;
        
        for(int follower: graph[index]) {
            int case1 = solve(follower, true);
            int case2 = solve(follower, false);
            
            if(case1 < case2) participationExist = true; //참여
            else diff = min(diff, case1 - case2); //불참여
            
            sum += min(case1, case2);
        }
        
        return participationExist ? sum : sum + diff;
    }
    return result;
}
int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;
    salesInfo = sales;
    makeTree(links);
    memset(dp, -1, sizeof(dp)); //일반 배열에 값 채우기 (1차원 아니더라도 다 가능한듯)
    return answer = min(solve(1, false), solve(1, true));
}

int main(int argc, const char * argv[]) {
    vector<int> sales = {14, 17, 15, 18, 19, 14, 13, 16, 28, 17};
    vector<vector<int>> links = {{10, 8}, {1, 9}, {9, 7}, {5, 4}, {1, 5}, {5, 10}, {10, 6}, {1, 3}, { 10, 2}};
    cout<<solution(sales, links)<<endl;
    return 0;
}
