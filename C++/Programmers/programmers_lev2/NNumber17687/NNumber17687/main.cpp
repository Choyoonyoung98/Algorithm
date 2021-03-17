//
//  main.cpp
//  NNumber17687
//
//  Created by 조윤영 on 2021/03/16.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<string> numbers = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

string transformFormat(int target, int n) {
    string result = "";
    while(target > 0) {
        result += numbers[target % n];
        target /= n;
    }
    reverse(result.begin(), result.end());
    return result;
}

string solution(int n, int t, int m, int p) {//진법, 미리 구할 숫자의 갯수, 게임에 참가하는 인원, 튜브의 순서
    string answer = "";
    string temp;
    int mt = m * t; //미리 구할 숫자의 갯수 * 게임에 참가하는 인원
    int turn = 0;
    int targetPos = turn * m + p - 1;
    for(int num = 0; temp.size() <= mt; num++) {
        string gameNum = (num == 0) ? "0" : transformFormat(num, n);
        temp  += gameNum;
        if(temp.size() > targetPos) {
            answer += temp[targetPos];
            turn++;
            targetPos = turn * m + p - 1;
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    cout<<solution(2, 4, 2, 1)<<endl;
    return 0;
}
