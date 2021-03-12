//
//  main.cpp
//  FashionKing9375
//
//  Created by 조윤영 on 2021/03/11.
//

#include <iostream>
#include <map>
using namespace std;

int T, N;
map<string, int> m;
int solution();
void input() {
    cin >> T;
    for(int t=0; t<T; t++) {
        cin>> N;
        string name, type;
        for(int i=0; i<N; i++) {
            cin>> name >> type;
            m[type]++;
        }
        if(m.empty() || m.size() == 1) cout<<N<<"\n";
        else cout<<solution()<<"\n";
        m.clear();
    }
}

int solution() {
    int answer = 1;
    for(auto iter = m.begin(); iter != m.end(); iter++) {
        answer*= (iter->second+1);
    }

    return answer-1;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    return 0;
}
