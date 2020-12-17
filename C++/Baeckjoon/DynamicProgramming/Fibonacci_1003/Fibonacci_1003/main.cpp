//
//  main.cpp
//  Fibonacci_1003
//
//  Created by 조윤영 on 2020/11/27.
//피보나친데 미완
//

#define MAX_SIZE 40
#include <iostream>
using namespace std;
void solution(int N);
int fibonacci[MAX_SIZE];
int T = 0;

void input() {
    cin>>T;
    int n = 0;
    for(int i=0; i<T; i++) {
        cin>>n;
        solution(n);
    }
}

void solution(int N) {
    int zeroCnt = 1;
    int oneCnt = 1;
    fibonacci[0] = 0; fibonacci[1] = 1;
    if(N == 0) {
        cout<<1<<" "<<0<<"\n";
        return;
    } else if(N == 1) {
        cout<<0<<" "<<1<<"\n";
        return;
    }
    
    for(int i=N; i<=2; i++) {
        if(i-1 == 0 || i-2 == 0) zeroCnt++;
        if(i-1 == 1 || i-2 == 1) oneCnt++;
    }
    
    cout<<zeroCnt<<" "<<oneCnt<<"\n";
    
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();

    return 0;
}
