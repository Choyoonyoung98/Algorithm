//
//  main.cpp
//  InsertAd72414
//
//  Created by 조윤영 on 2021/02/03.
//
#define MAX_SIZE 360000
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
int ad[MAX_SIZE];
//date형태로 string이 주어진다면, 해당 date의 가장 작은 단위로 값을 구해라!
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

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    for(string log: logs) {
        int start = strToSec(log.substr(0, 8));
        int end = strToSec(log.substr(9, 8));
        for(int i=start; i<end; i++) ad[i] ++;
    }

    int N = strToSec(play_time);
    int len = strToSec(adv_time);

    int index = 0;
    long long sum = 0;

    queue<int> q;
    for(int i=0; i<len; i++) {
        sum += ad[i];
        q.push(ad[i]);
    }
    long long maxSum = sum;

    for(int i=len; i<N; i++) {
        sum += ad[i];
        q.push(ad[i]);
        sum -= q.front();
        q.pop();
        if(sum > maxSum) {
            maxSum = sum;
            index = i -  len + 1;
        }
    }

    answer = secToStr(index);
    return answer;
}

int main(int argc, const char * argv[]) {
    string play_time = "02:03:55";
    string adv_time = "00:14:15";
    vector<string> logs = {"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"};
    cout<<solution(play_time, adv_time, logs);
    return 0;
}
