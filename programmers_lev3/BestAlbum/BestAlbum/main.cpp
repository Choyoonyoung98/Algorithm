//
//  main.cpp
//  BestAlbum
//
//  Created by 조윤영 on 29/01/2020.
//  Copyright © 2020 조윤영. All rights reserved.
//
//코드가 더럽다.. 시간나면 함수 분할할 것!

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> uniqGenres;
    
    for(int i=0; i<genres.size(); i++) {
        uniqGenres[genres[i]]+=plays[i];
    }

    while(!uniqGenres.empty()) {

        //가장 많이 재생된 장르 뽑기
        int BestGenreCnt = 0;
        string BestGenere;
        for(auto iter = uniqGenres.begin(); iter !=uniqGenres.end(); iter++) {

            if(BestGenreCnt<iter->second) {
                BestGenreCnt = iter->second;
                BestGenere = iter->first;
            }
        }
        uniqGenres.erase(BestGenere);
        
        //해당 장르에서 가장 많이 재생된 순으로 answer에 집어넣기
        cout<<"["<<BestGenere<<"]"<<endl;
        vector<int> temp;
        for(int i = 0; i<plays.size(); i++) {
            if(genres[i] == BestGenere) {
                temp.push_back(plays[i]);
            }
        }
        //해당 장르에 대한 플레이 재생횟수만을 모아둔 temp를 내림차순으로 정렬
        sort(temp.begin(), temp.end(), greater<int>());
        for(int i=0; i<temp.size(); i++) {
            cout<<temp[i]<<endl;
        }
        //그 중 상위 두 재생횟수의 고유번호를 answer로 push
        int cnt = 0;
        vector<bool> visited(plays.size(), false);
        for(int i=0; i<temp.size(); i++) {
            if(cnt == 2)break;
            
            for(int j=0;j<plays.size(); j++) {
                if(temp[i] == plays[j] && visited[j] != true){
                    answer.push_back(j);
                    cnt++;
                    visited[j] = true;
                    break;
                }
            }
        }
        temp.clear();
    }
    for(int i =0; i<answer.size(); i++) {
        cout<<answer[i]<<endl;
    }
    return answer;
}
int main(int argc, const char * argv[]) {
    vector<string> genres = {"classic","pop","classic","classic","pop"};
    vector<int> plays = {500,600,150, 800, 2500};
    solution(genres, plays);
    return 0;
}
