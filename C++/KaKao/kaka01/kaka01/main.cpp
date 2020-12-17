//
//  main.cpp
//  kaka01
//
//  Created by 조윤영 on 09/05/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//
//
//

#include <iostream>
#include <cmath>
#include <vector>
#define LEFT_FINGER "L"
#define RIGHT_FINGER "R"

using namespace std;

char room[4][4] = {{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};
struct Dir {
    int y;
    int x;
};

Dir moveDir[4] = {{-1,0},{1,0},{0,-1},{0,1}};
vector<pair<int,int>> positions;



void findNumbPosition(vector<int> numbers) {
    for(int i=0; i<numbers.size(); i++) {
        int n = numbers[i];
        if(n==1){
            positions.push_back({0,0});
        }else if(n==0){
            positions.push_back({3,1});
        }else{
            int y = 0;
            int x = 0;

            //y 찾기
            switch((n-1)/3) {
                case 0:
                    y = 0;
                    break;
                case 1:
                    y = 1;
                    break;
                case 2:
                    y = 2;
                    break;
                default:
                    break;
            }
            
            //x 찾기
            switch (n%3) {
                case 0:
                    x = 2;
                    break;
                case 1:
                    x = 0;
                    break;
                case 2:
                    x = 1;
                    break;
                default:
                    break;
            }
            
            positions.push_back({y,x});
        }
    }
}


bool isLeftHanded(string hand) {
    if(hand == "left")return true;
    return false;
}

bool isLeftHandIsCloser(int leftY, int leftX, int rightY, int rightX, int pY, int pX, string hand) {
    
    int rightDistance = abs(rightY - pY) + abs(rightX - pX);
    int leftDistance = abs(leftY - pY) + abs(leftX - pX);
    
    if(rightDistance<leftDistance)return false;
    else if(rightDistance> leftDistance)return true;
    else if(rightDistance == leftDistance) {
        //둘의 거리가 같을 경우
        if(isLeftHanded(hand))return true;
        else return false;
    }
    
    return true;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int leftHandPositionY = 3;
    int leftHandPositionX = 0;
    int rightHandPositionY = 3;
    int rightHandPositionX = 2;
    
    findNumbPosition(numbers);
    for(int i=0; i<positions.size(); i++) {
        int pY = positions[i].first;
        int pX = positions[i].second;
        
        if(pX == 0) {
            //왼쪽
            answer+=LEFT_FINGER;
            leftHandPositionY = pY;
            leftHandPositionX = pX;
        }else if(pX == 2) {
            //오른쪽
            answer+=RIGHT_FINGER;
            rightHandPositionY = pY;
            rightHandPositionX = pX;
        }else if(pX == 1){
            //pX == 1
            //가운데일 경우
            if(isLeftHandIsCloser(leftHandPositionY, leftHandPositionX, rightHandPositionY, rightHandPositionX, pY, pX, hand)) {
                //왼손잡이일 경우
                answer += LEFT_FINGER;
                leftHandPositionY = pY;
                leftHandPositionX = pX;
                
            }else{
                //오른손잡이일 경우
                answer += RIGHT_FINGER;
                rightHandPositionY = pY;
                rightHandPositionX = pX;
            }
            
            
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    string hand = "left";
    cout<<solution(numbers, hand);
    return 0;
}
