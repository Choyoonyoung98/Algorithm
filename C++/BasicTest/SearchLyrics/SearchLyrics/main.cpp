//
//  main.cpp
//  SearchLyrics
//
//  Created by 조윤영 on 2020/08/27.
//  Copyright © 2020 조윤영. All rights reserved.
//
//https://programmers.co.kr/learn/courses/30/lessons/60060
//트라이(Trie) 자료구조

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define MAX_SIZE 1000000
#define Alphabet_Cnt 26
using namespace std;

//struct Trie {
//    Trie* next[Alphabet_Cnt];
//    bool finish;
//    int cnt;
//    Trie(): finish(false), cnt(1) {
//        memset(next, 0, sizeof(next));
//    }
//    ~Trie() {
//        for(int i=0; i< Alphabet_Cnt;  i++) {
//            if(next[i]) delete next[i];
//        }
//    }
//    
//    void insert(const char* key) {
//        if(*key == '\0') finish = true;
//        else {
//            int curr = *key - 'a';
//            if(next[curr] == NULL) next[curr] = new Trie();
//            else next[curr]->cnt++;
//            next[curr]-> insert(key + 1);
//        }
//    }
//    
//    int find(const char* key) {
//        int curr = *key - 'a';
//        if(*key == '?') {
//            int tmp = 0;
//            for(int i=0; i<26; i++) {
//                if(next[curr] != NULL) tmp += next[i]->cnt;
//            }
//            return tmp;
//        }
//        if(next[curr] == NULL) return 0;
//        if(*(key+1) == '?') return next[curr]->cnt;
//        return next[curr]->find(key+1);
//    }
//};
//
//Trie *root[MAX_SIZE];
//Trie *reroot[MAX_SIZE];

int count_by_range(int a, int left_value, int right_value) {
    int right_index = bisect_right(a, right_value);
    int left_index = bisect_left(a, right_value);
    return right_index - left_index;
}

vector<vector<string>> array_list;

vector<vector<string>> reverse_array_list;
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    array_list.assign(MAX_SIZE, {});
    
    for(string word : words) {
        int wordSize = word.size();
        array_list[wordSize].push_back(word);
        reverse(word.begin(), word.end());
        reverse_array_list[wordSize].push_back(word);
    }
    
    sort(array_list.begin(), array_list.end());
    sort(reverse_array_list.begin(), reverse_array_list.end());
    
    for(string query: queries) {
        int res = 0;
        if(query[0] != '?') res = count_by_range(array_list[query.size()], query.replace(query.begin(), qu'?', 'a'), query.replace('?', 'z'))
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<string>  words = {"frodo", "front", "frost", "frozen", "frame", "kakao"};
    vector<string> queries = {"fro??", "????o", "fr???", "fro???", "pro?"};
    solution(words, queries);
    return 0;
}
