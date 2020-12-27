//
//  main.cpp
//  Coin11047
//
//  Created by 조윤영 on 2020/12/27.
//

#include <iostream>
#include <vector>

using namespace std;
int N, K;
vector<int> values;
void input() {
    cin>> N >> K;
    values.assign(N, 0);
    for(int i=0; i<N; i++) cin>> values[i];
}

int solution() {
    int answer = 0;
    int result = 0;
    int i = N-1;
    
    while(K > 0 && i >= 0) {
        if(values[i] > K) i--;
        if(values[i] <= K) {
            K -= values[i];
            answer++;
        }
    }
    
    return answer;
}

int solution2() {
    int answer = 0;
    sort(values.begin(), values.end(), greater<int>());
    int i = 0;
    while(K > 0 && i <= N-1) {
        if(values[i] > K) i++;
        else {
            K -= values[i];
            answer++;
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    cout<<solution()<<"\n";
    return 0;
}
