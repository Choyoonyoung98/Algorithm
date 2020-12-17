//
//  main.cpp
//  SkillTree
//
//  Created by 조윤영 on 24/08/2019.
//  Copyright © 2019 조윤영. All rights reserved.
//
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename Iter>
void print(Iter begin, Iter end) {
    while(begin !=end) {
        cout<<"["<<*begin <<"]";
        begin++;
    }
    cout<<endl;
}

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;
    
    for (auto i : skill_trees)
    {
        vector<int> v;
        
        for (auto j : skill) { //j란 각 skill을 뜻한다.
            v.push_back(find(i.begin(), i.end(), j) - i.begin()); //skill_tree의 한 단어에서 skill 철자를 찾은 위치를 push
        }
        /*EX)
         BACDE
         주어진 CBD 중에서 C 먼저 찾아야지 2번째에 있네 push
         B는 0번째에 있네 push
         D는 3번째에 있네 push
         
         없는 경우에는 끝번째 수+1이 되므로 선행스킬이 수행되지 않은 것을 잡을 수 있음...
         대박이다 ㅋㅋ
         
         */
        print(v.begin(), v.end());

        if (is_sorted(v.begin(), v.end())) ++answer;
    }
    return answer;
}

int solution2(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<int> position;
    map<char, int> m;
    
    for(int i=0; i<skill.size(); i++) {
        m[skill[i]] = i;
    }
    
    for(string currentSkill: skill_trees) {
        position.assign(skill.size(), currentSkill.size());
        for(int i=0; i<currentSkill.size(); i++) {
            if(m.count(currentSkill[i]) > 0) {
                int index = m[currentSkill[i]];
                position[index] = i;
            }
        }

        if(is_sorted(position.begin(), position.end())) answer++;
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    string skill = "CBD";
    vector<string> skill_tree{"BACDE", "CBADF", "AECB", "BDA"};
    cout<<solution(skill,skill_tree );
    
    return 0;
}
