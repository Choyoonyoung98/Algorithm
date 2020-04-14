//
//  main.cpp
//  tttt
//
//  Created by 조윤영 on 11/04/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n, vector<vector<int>> delivery) {
    string answer = "";
    
    vector<int> items(n+1, 0); //0에 계속 남아있으면 재고여부 모르는 상황
    vector<int> visited(n+1, false);
    vector<vector<int>> related;
    related.assign(n+1, {});
    
    
    for(int i=0; i<delivery.size(); i++) {
        
        int item1 = delivery[i][0];
        int item2 = delivery[i][1];
        int isdelivered = delivery[i][2];
        
        if(isdelivered == 1) {
            
            //각 물품의 재고 줄이고
            items[item1]++;
            items[item2]++;
            
            //해당 물품의 재고 여부에 따라 이전의 물품 재고를 판단할 수 있다면,
            if(related[item1].size() !=0){
                for(int i=0; i<related[item1].size(); i++) {
                    int related_item = related[item1][i];
                    
                    items[related_item] = -1;
                }
                
                related[item1].clear();
            }
            
            if(related[item2].size() !=0) {
                for(int i=0; i<related[item2].size(); i++) {
                    int related_item = related[item2][i];
                    
                    items[related_item] = -1;
                }
                
                related[item2].clear();
            }
            
        }else{//배송하지 않았을 경우
            if(items[item1]>0) { //item1의 재고가 있는 경우
                items[item2] = -1;//item2의 재고가 없음으로 판단
            }
            else if(items[item2]>0) {//item2의 재고가 있는 경우
                items[item1] = -1;//item1의 재고가 없음으로 판단
            }else{
                //둘의 재고를 알 수 없는 상황일 때
                related[item1].push_back(item2);
                related[item2].push_back(item1);
            }
        }
    }
    
    for(int i=1; i<items.size(); i++) {
        
        string result;
        if(items[i]>0)result="O";
        else if(items[i] == 0)result="?";
        else if(items[i] == -1)result="X";
        
        answer+=result;
    
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> delivery = {{5,6,0},{1,3,1},{1,5,0},{7,6,0},{3,7,1},{2,5,0}};
    solution(7, delivery);
    return 0;
}
