//
//  main.cpp
//  SecretMap
//
//  Created by 조윤영 on 13/03/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string map;
    
    
    for(int i=0; i<n; i++) {
        map = "";
        int cipher1 = arr1[i];
        int cipher2 = arr2[i];
        
        int pos1 = pow(2, n-1);
        int pos2 = pow(2, n-1);
        
        for(int j=0; j<n; j++) {
            
            //arr1 해독
            if(cipher1 >= pos1){
                cipher1 -= pos1;
                map+="#";
            }else {
                map+=" ";
            }
            
            //arr2 해독
            if(cipher2 >= pos2) {
                cipher2 -= pos2;
                map[j]= '#';
            }

            pos1/=2;
            pos2/=2;
        }
        
        answer.push_back(map);
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    int n = 5;
    vector<int> arr1 = {9,20,28,18,11};
    vector<int> arr2 = {30,1,21,17,28};
    
    solution(n, arr1, arr2);
    
    
    return 0;
}
