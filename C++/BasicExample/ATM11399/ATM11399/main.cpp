//
//  main.cpp
//  ATM11399
//
//  Created by 조윤영 on 2020/12/26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> times;
void input() {
    cin>> N;
    times.assign(N, 0);
    for(int i=0; i<N; i++) cin>> times[i];
}

int solution() {
    int answer = 0;
    int result = 0;
    sort(times.begin(), times.end());
    for(int t: times) {
        result += t;
        answer += result;
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
