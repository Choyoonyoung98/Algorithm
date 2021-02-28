//
//  main.cpp
//  BoxPackaging_Line2020_1
//
//  Created by 조윤영 on 2021/02/25.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<int>> boxes) {
    int cnt = 0;
    map<int, int> boxCnt;
    for(int i=0; i<boxes.size(); i++) {
        int box1 = boxes[i][0];
        int box2 = boxes[i][1];
        boxCnt[box1]++;
        boxCnt[box2]++;
    }
    
    for(auto iter = boxCnt.begin(); iter != boxCnt.end(); iter++) {
        if(iter->second % 2 != 0) cnt++;
    }
    return cnt/2;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> boxes = {{1,2},{2,3},{3,1}};
    cout<<solution(boxes)<<endl;
    return 0;
}
