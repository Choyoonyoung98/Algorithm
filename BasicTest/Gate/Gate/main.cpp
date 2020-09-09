//
//  main.cpp
//  Gate
//
//  Created by 조윤영 on 2020/09/03.
//  Copyright © 2020 조윤영. All rights reserved.
//
//Union-Find
//순서대로!

#include <iostream>
#define MAX_SIZE 100001
using namespace std;

int G,P = 0;
int parent[MAX_SIZE];

int findParent(int x) {
    if(x == parent[x]) return x;
    parent[x] = findParent(parent[x]);
    return parent[x];
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if(a != b) parent[b] = a;
    else parent[a] = b;
}

int solution() {
    int answer = 0;
    cin>>G;
    cin>>P;
    
    for(int i=1; i<=G; i++) parent[i] = i;
    
    for(int i=0; i<P; i++) {
        int x = 0;
        cin>>x;
        
        int root = findParent(x);
        if(root == 0) break;
        unionParent(root, root-1);
        answer += 1;
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    cout<<solution()<<"\n";
    return 0;
}
