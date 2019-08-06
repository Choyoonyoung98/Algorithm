//
//  main.cpp
//  GymSuit
//
//  Created by 조윤영 on 05/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//

/*
 점심시간에 도둑이 들어, 일부 학생이 체육복을 도난당했습니다. 다행히 여벌 체육복이 있는 학생이 이들에게 체육복을 빌려주려 합니다. 학생들의 번호는 체격 순으로 매겨져 있어, 바로 앞번호의 학생이나 바로 뒷번호의 학생에게만 체육복을 빌려줄 수 있습니다. 예를 들어, 4번 학생은 3번 학생이나 5번 학생에게만 체육복을 빌려줄 수 있습니다. 체육복이 없으면 수업을 들을 수 없기 때문에 체육복을 적절히 빌려 최대한 많은 학생이 체육수업을 들어야 합니다.
 
 전체 학생의 수 n, 체육복을 도난당한 학생들의 번호가 담긴 배열 lost, 여벌의 체육복을 가져온 학생들의 번호가 담긴 배열 reserve가 매개변수로 주어질 때, 체육수업을 들을 수 있는 학생의 최댓값을 return 하도록 solution 함수를 작성해주세요.
*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

////////////////////////////////////////////////
/*solution은 모든 테스트케이스를 통과하지 못함.
solution2는 모든 테스트케이스를 통과함*/
////////////////////////////////////////////////
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> visit(lost.size(),0);
    
    answer = n - lost.size(); //빌려주지 않았을 경우 체육복을 입게 되는 학생 수

    
    for(int i=0; i<reserve.size(); i++) {
        
        //만약 여벌을 가지고 온 학생이 도난을 당했다면 빌려줄 수 없으므로 다른 여벌 가지고 온 학생으로 반복문 이동.
        auto current = lost.begin();
        current = find(current, lost.end(), reserve[i]);
        if(current !=lost.end())continue;
        
        //만약 현재 여유분 있는 학생의 앞 번호가 도난 당한 학생 번호와 일치한다면,
        current = lost.begin();
        current = find(current, lost.end(),reserve[i]-1);
        
        //일치하는 학생이 없다면 뒷 번호 학생과 일치하는지 확인
        if(current == lost.end()) {
            current = lost.begin();
            current = find(current, lost.end(), reserve[i]+1);
        }
        
        //앞번호든 뒷번호든 발견되고 && 잃어버린 학생에 대해서 방문하여 체육복을 준 적이 없다면
        if(current !=lost.end() && visit[distance(lost.begin(), current)] !=1) {
            visit[distance(lost.begin(), current)] = 1;//이 잃어버린 친구는 다른 학생의 여유분 체육복을 이미 전달받았음을 알리고
            answer++;//체육복을 입은 학생의 수를 증가시킨다.
        }
        
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> lost {3,4};
    vector<int> reserve {1,4};
    
    cout<<solution(4,lost, reserve);
    return 0;
}


int solution2(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> students(n,1);//총 학생 수 n만큼 1로 채운 벡터 배열(각 학생이 가지고 있는 체육복 수를 담음)

    for(auto a : reserve){ //여유분 있는 애들은 체육복 수 1씩 증가
        students[a-1]++;
    }
    for(auto a : lost){//도난 당해서 체육복이 없는 학생들의 체육복 수 1씩 감소
        students[a-1]--;
    }
    
    //지금까지의 상황: 여유분 있는 애들: 2 , 도난당한 애들: 0, 도난 안당하고 자기 체육복 있는 애들: 1

    for(int i=0; i<students.size();i++){
        if(i!=0&&students[i]==0){//현재 학생의 체육복이 도난당했고,
            if(students[i-1]==2){//현재 학생의 앞 학생이 여유분이 있을 경우,
                //빌려주자!
                students[i]++;//현재 학생은 체육복이 생기고
                students[i-1]--;//앞의 학생은 체육복을 빌려주므로 체육복이 1 감소한다.
                continue;
            }
        }
        
        //현재 학생이 도난당했고 앞 학생이 여유분이 없을 경우 뒤 학생 또한 알아본다.
        
        if(i!=students.size()-1&&students[i]==0){//위의 방법과 비슷하게, 현재 학생 체육복이 도난당했고, 뒤 학생이 여유분이 있는 경우이다.
            if(students[i+1]==2){
                students[i]++;
                students[i+1]--;
            }
        }

    }

    for(auto a : students){
        a>0 ? answer++:0;//각 학생이 체육복을 0보다 큰 수를 가지고 있다면 answer증가
    }

    return answer;
}
