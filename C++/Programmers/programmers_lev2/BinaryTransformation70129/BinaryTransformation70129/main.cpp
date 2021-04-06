//
//  main.cpp
//  BinaryTransformation70129
//
//  Created by 조윤영 on 2021/04/04.
//


#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    string x = s;
    while(x != "1") {
        answer[0]++;
        string temp = "";
        for(char c: x) {
            if(c == '1') temp += "1";
            else answer[1]++;
        }
    
        int xSize = temp.size();
        string result = "";
        while(xSize != 0) {
            int n = xSize % 2;
            result = to_string(n) + result;
            xSize/= 2;
        }
        
        x = result;
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    solution("");
    return 0;
}
