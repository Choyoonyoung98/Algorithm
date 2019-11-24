#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX_SIZE 10

///
using namespace std;
int answer = MAX_SIZE;
int level = 0;
int visited[MAX_SIZE] = {false};
void dfs(string begin, string target, vector<string> &words, int index) {
    visited[index] = true;
    
    
    if(words[index] == target) {
        answer = min(answer, level);
        return;
    }
    
    for(int i=0; i<words.size(); i++) {
        if(i!=index && visited[i]!=true) {
            
            for(int j=0; j<begin.size(); j++){
                
                if(words[i].find(begin.erase(j,1))!= std::string::npos) {
                    level++;
                    dfs(words[i], target, words, i);
                }
            }
        }
    }
    return;
}
int solution(string begin, string target, vector<string> words) {
    
    for(int i=0; i<words.size(); i++) {
        
        if(words[i]!=begin && visited[i]!=true) {
            for(int j=0; j<begin.size(); j++){
                level = 0;
                if(words[i].find(begin.erase(j,1)) != std::string::npos) {
                    level++;
                    dfs(words[i], target, words,i);
                    
                }
            }
        }
    }
    if(answer == MAX_SIZE) answer = 0;
    
    return answer;
}

int main() {
    vector<string> words {"hot","dot","dog","lot","log","cog"};
    solution("hit","cog",words);
    cout<<answer;
}
