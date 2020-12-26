//
//  main.cpp
//  ColumnAndBeamInstallation
//
//  Created by 조윤영 on 2020/08/16.
//  Copyright © 2020 조윤영. All rights reserved.
//
//https://programmers.co.kr/learn/courses/30/lessons/60061
//기둥과 보 설치

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
map<pair<int,int>, int[2]> m;

bool checkDeletable();
bool checkCanBuildColumn(int y, int  x);
bool checkCanBuildBeam(int y, int x);
void initializeInstallation(int n);
vector<vector<int>> makeAnswer();

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    //초기화
    initializeInstallation(n);
    
    for(int i=0; i<build_frame.size(); i++) {
        int y = build_frame[i][1];
        int x = build_frame[i][0];
        int type = build_frame[i][2]; //0 = 기둥, 1 = 보
        int action = build_frame[i][3]; //0 = 삭제, 1 = 설치
//        cout<<y<<","<<x<<","<<type<<",action  = "<<action<<endl;
        if(action == 1)  { //설치
            if((type == 0 && checkCanBuildColumn(y, x )) || (type == 1 && checkCanBuildBeam(y, x))) {
                m[make_pair(y, x)][type] = 1;
//                cout<<"설치!"<<endl;
            }
        } else { //삭제
            m[make_pair(y, x)][type] = 0; //삭제
            if(!checkDeletable())  m[make_pair(y, x)][type] = 1;
        }
    }
//    cout<<"================="<<endl;
    answer = makeAnswer();
    return answer;
}

vector<vector<int>> makeAnswer() {
    vector<vector<int>> temp;
    for(auto itr = m.begin(); itr != m.end(); itr++) {
        int y =  itr->first.first;
        int x = itr->first.second;
        int column = itr->second[0];
        int beam = itr->second[1];
        
       cout<<y<<","<<x<<","<<column<<","<<beam<<endl;
        
        if(column == 0 && beam == 0) continue;
        
        if(column == 1) {
            temp.push_back({x,y,0});
        }
        if(beam  == 1) {
            temp.push_back({x,y,1});
        }
    }
    sort(temp.begin(), temp.end());
    
    return temp;
}

bool checkCanBuildColumn(int y, int  x) {
    if( y == 0 || m[make_pair(y-1, x)][0] == 1 || m[make_pair(y, x-1)][1] == 1 || m[make_pair(y, x)][1] == 1) return true;
    return false;
}

bool checkCanBuildBeam(int y, int x) {
    if((m[make_pair(y, x-1)][1] == 1 && m[make_pair(y, x+1)][1] == 1) || m[make_pair(y-1, x)][0] == 1 || m[make_pair(y-1, x+1)][0] == 1) return true;
    return false;
}

void initializeInstallation(int n) {
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<n+1; j++) {
            m[make_pair(i, j)][0] = 0; //첫 번째 인덱스에는 보 유무에 대해 체크하고
            m[make_pair(i, j)][1] = 0; // 두 번째 인덱스에는 기둥 유무에 대해 체크
        }
    }
}

bool checkDeletable() {
    for(auto itr = m.begin(); itr !=  m.end(); itr++)  {
        int y =  itr->first.first;
        int x = itr->first.second;
        int column = itr->second[0];
        int beam = itr->second[1];
        if(column == 0 && beam == 0) continue;;
        if(column && !checkCanBuildColumn(y, x)) return false;
        else if ( beam && !checkCanBuildBeam(y, x)) return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N =  5;
    vector<vector<int>> build_frame = {{1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1}};
    solution(N, build_frame);
    return 0;
}
