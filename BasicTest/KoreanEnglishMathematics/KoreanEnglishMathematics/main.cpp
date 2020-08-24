//
//  main.cpp
//  KoreanEnglishMathematics
//
//  Created by 조윤영 on 2020/08/24.
//  Copyright © 2020 조윤영. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Score {
    string name;
    int koreanScore;
    int englishScore;
    int mathScore;
    
    Score(string _name, int _koreanScore, int _englishScore, int _mathScore) {
        name = _name;
        koreanScore = _koreanScore;
        englishScore = _englishScore;
        mathScore = _mathScore;
    };
};

int  N = 0;
vector<Score> scores;
void input() {
    cin>> N;
    for(int i=0; i<N; i++) {
        string name;
        int koreanScore = 0;
        int englishScore = 0;
        int mathScore = 0;
        cin>>name>>koreanScore>>englishScore>>mathScore;
        scores.push_back(Score(name, koreanScore, englishScore, mathScore));
    }
}

bool compare(Score &a, Score &b) {
    if(a.koreanScore == b.koreanScore && a.englishScore == b.englishScore && a.mathScore == b.mathScore) return a.name < b.name;
    if(a.koreanScore == b.koreanScore && a.englishScore == b.englishScore) return a.mathScore > b.mathScore;
    if(a.koreanScore == b.koreanScore) return a.englishScore < b.englishScore; //오름차순
    return a.koreanScore > b.koreanScore; //내림차순
}

void solution() {
    sort(scores.begin(), scores.end(), compare);
    for(int i=0; i<scores.size(); i++) {
        cout<<scores[i].name<<"\n";
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solution();
    return 0;
}
