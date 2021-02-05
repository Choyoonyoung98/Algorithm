//
//  main.cpp
//  ConvertBetweenDateAndString
//
//  Created by 조윤영 on 2021/02/05.
//

#include <iostream>
using namespace std;
int strToSec(string str) {
    int result = 0;
    int h = stoi(str.substr(0, 2)) * 3600;
    int m = stoi(str.substr(3, 2)) * 60;
    int s = stoi(str.substr(6, 2));
    result = h + m + s;
    return result;
}

string secToStr(int index) {
    string result = "";
    //기본적인 변환방법 외어두기!: s -> m -> h
    string h = to_string(index / 3600);
    string m = to_string((index / 60) % 60);
    string s = to_string(index % 60);

    if(h.size() == 1 ) h = "0" + h;
    if(m.size() == 1 ) m = "0" + m;
    if(s.size() == 1 ) s = "0" + s;
    result = h + ":" + m + ":" + s;
    return result;
}
int main(int argc, const char * argv[]) {
    strToSec("10:30:52");
    secToStr(3600);
    return 0;
}
