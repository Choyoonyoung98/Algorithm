//
//  main.cpp
//  Deliver
//
//  Created by 조윤영 on 06/03/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int node;
    int length;
    
    Node(int _node, int _length){
        node = _node;
        length = _length;
    }
};
int answer = 0;
vector<vector<Node>> graph_relations;
vector<bool> visited;
vector<bool> check;



//27, 29, 32 시간초과.
void dfs(int index, int cnt, int maxLength) {
    

    visited[index] = true;
    
    if(cnt > maxLength)return;
    else {
        if(!check[index])answer++;
        check[index] = true;
    }
    
    for(int i=0; i<graph_relations[index].size();i++) {
        
        int nextNode = graph_relations[index][i].node;
        int nextLength = graph_relations[index][i].length;
        
        if(!visited[nextNode]){
            dfs(nextNode, cnt+nextLength, maxLength);
            visited[nextNode] = false;
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    

    graph_relations.assign((N+1),{});
    visited.assign(N+1, false);
    check.assign(N+1, false);
    
    for(int i=0; i<road.size(); i++) {
        int node1 = road[i][0];
        int node2 = road[i][1];
        int time = road[i][2];
        
        graph_relations[node1].push_back(Node(node2, time));
        graph_relations[node2].push_back(Node(node1, time));
    }
    

    //1번 마을에 대한 초기화
    visited[1] = true;
    check[1] = true;
    answer+=1;
    
    for(int i=0; i<graph_relations[1].size(); i++) {
    
        int nextNode = graph_relations[1][i].node;
        int nextLength = graph_relations[1][i].length;
        dfs(nextNode, nextLength, K);
        
        visited[graph_relations[1][i].node] = false;
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    int N = 6;
    int K = 4;
    
    vector<vector<int>> road = {{1,2,1},{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1}};
    
    cout<<solution(N, road, K);
    
    return 0;
}
