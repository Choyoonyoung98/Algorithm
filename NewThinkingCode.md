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

2. [점프게임](https://leetcode.com/problems/jump-game/)
```
func solution2(_ nums: [Int] ) -> Bool {
    var reachDistance = 0
    
    //for i in 0..<reachDistance(x)
    for (i, n) in nums.enumerated() {
        if reachDistance < i { return false }
        let jumpCnt = n
        if i+jumpCnt >= nums.count - 1 { return true }
        reachDistance = max(reachDistance, i+jumpCnt)
    }
    return false
}
```
