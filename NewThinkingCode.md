1. [가장 큰 수](https://programmers.co.kr/learn/courses/30/lessons/42746?language=cpp)
```
bool cmp(const string &a, const string &b) {
    return a+b>b+a ? true:false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> s_answer;
    for(int i=0; i<numbers.size(); i++) s_answer.push_back(to_string(numbers[i]));
    sort(s_answer.begin(), s_answer.end(), cmp);
    
    for(string str: s_answer) {
        answer+=str;
    }

    if(answer[0] == '0')return "0";
    return answer;
}
```
