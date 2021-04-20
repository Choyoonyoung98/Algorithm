//
//  main.cpp
//  SayMiddle1655
//
//  Created by 조윤영 on 2021/04/19.
//
//가운데를 말해요
//최대 힙과 최소 힙
//값이 들어올 때마다 중간값을 출력해야하기 떄문에 매번 정렬하고 가운데 값을 출력하면 시간초과 발생

//최대 힙의 크기는 최소 힙의 크기와 같거나 하나더 크다
//최대 힙의 최대 원소는 최소 힙의 최소 원소보다 작거나 같다
//이 때 알고리즘에 맞지 않다면 최대 힙, 최소 힙의 가장 위의 값을 swap해준다
//=> 항상 최대 힙 top값이 중간값이 된다.

#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int> maxHeap; //최대힙: 각 노드가 자식노드의 값보다 큰 트리
priority_queue<int, vector<int>, greater<int>> minHeap; //최소힙: 각 노드가 자식노드의 값보다 작은 트리
int solution(int x);

void input() {
    cin>> N;
    for(int i=0; i<N; i++) {
        int x;
        cin>> x;
        cout<<solution(x)<<"\n";
    }
}

int solution(int x) {

    if(maxHeap.empty() || (maxHeap.size() == minHeap.size())) maxHeap.push(x);
    else minHeap.push(x);
    
    //minHeap, maxHeap 모두 empty하지 않으며
    //maxHeap의 가장 큰 노드보다 minHeap의 가장 작은 노드가 더 크다면?
    //SWAP
    if(!maxHeap.empty() && !minHeap.empty() && !(maxHeap.top() <= minHeap.top())) {
        int minH = minHeap.top();
        int maxH = maxHeap.top();
        
        minHeap.pop();
        maxHeap.pop();
        
        maxHeap.push(minH);
        minHeap.push(maxH);
    }
    
    return maxHeap.top();
}

priority_queue<int, vector<int>, greater<int>> pq; //가장 작은 값이 top에 오는
void solution2(int x) {
    cin>> N;
    for(int i=1; i<=N; i++) {
        int x;
        cin>> x;
        if(i%2 == 1 && i != 1) {
            pq.push(x);
            pq.pop();//pq.size()를 2개로 유지하는듯?
        } else pq.push(x);
        
        cout<<pq.top()<<"\n";
    }
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    input();

    return 0;
}
