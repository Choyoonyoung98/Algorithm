//
//  main.cpp
//  Flip1439_C++
//
//  Created by 조윤영 on 2020/12/24.
//

#include <iostream>
#include <string>
using namespace std;

string word;
void input() {
    cin>> word;
}

int switchNumber(int n) {
    int result = 0;
    bool findN = false;
    for(char c: word) {
        if(c - '0' != n ) {
            if(!findN) {
                findN = true;
                result++;
            }
        } else if(findN) findN = false;
    }
    return result;
}

void solution() {
    cout<< min(switchNumber(0), switchNumber(1))<<"\n";
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solution();
    return 0;
}
