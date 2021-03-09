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

3. [잃어버린 괄호](https://www.acmicpc.net/problem/1541)
> 1. 수를 최소로 만드려면 '-'로 최대한 많은 수를 묶어야 한다는 것을 알 수 있다.
> 2. '-'가 나오기 전까지는 '-'로 묶을 수가 없으니 당연히 더하는 방법밖에는 없다. 결국 '-'가 나오기 전까지는 모두 더해준다.
> 3. '-'나온 후에는 모두 빼면 된다는 것을 쉽게 알 수 있다. '-'가 한번이라도 나온 후에는 모두 음수로 만들 수 있다.  
> ex) 1+2-3+4+5+6+7    ->  1+2-(3+4+5+6+7)
> ex) 1+2-3+4+5-6+7     -> 1+2-(3+4+5)-(6+7) 
> 
````
int solution() {
    int answer = 0;
    int sum = 0;
    bool isMinusExist = false;
    for(int i=0; i<=word.size(); i++) {
        char w = '.';
        if(i<word.size()) w = word[i];
        if(w == '-' || w == '+' || i == word.size() ) {
            if(isMinusExist) answer -= sum;
            else answer += sum;
            
            sum = 0;
            if(w == '-') isMinusExist = true;
        } else {
            sum *= 10;
            sum += w - '0';
        }
    }
    
    return answer;
}
```
