//
//  main.cpp
//  PhoneNumberList5052
//
//  Created by 조윤영 on 2021/03/11.
//
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int T, N;
vector<string> numb_list;
string solution();

void input() {
    cin>> T;
    for(int t=0; t<T; t++) {
        cin>> N;
        numb_list.assign(N, "");
        for(int i=0; i<N; i++) {
            cin>> numb_list[i];
        }
        
        if(numb_list.size() == 1) cout<<"YES\n";
        else cout<<solution()<<"\n";
    }
}

string solution() {
    sort(numb_list.begin(), numb_list.end(), less<string>());
    string prevNumber = numb_list[0];
    
    for(int i=1; i<numb_list.size(); i++) {
        if(numb_list[i].substr(0, prevNumber.size()) == prevNumber) return "NO";
        else prevNumber = numb_list[i];
    }
    
    return "YES";
}

int main(int argc, const char * argv[]) {
    input();
    return 0;
}
