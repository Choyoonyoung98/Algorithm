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
````

4. [30](https://www.acmicpc.net/problem/10610)
- 30이 되려면 숫자의 마지막이 0이면서 + 숫자들의 합이 3의 배수가 되어야 한다.

5. [문자열](https://www.acmicpc.net/problem/1120)
> 더미 문자열을 직접 추가할 필요 없이 더 긴 문자열 기준으로 작은 문자열을 움직여주면서 각 자리의 문자를 비교하면 된다

6. [패션왕 신해빈](https://www.acmicpc.net/problem/9375)
> 하나의 타입에 대한 종류가 1개 이상일 수 있는 조합 경우의 수 구하는 문제
> 하나의 타입에 대해서는 2개 이상의 종류를 동시에 조합으로 묶을 수 없을 때
> (x의 개수+1) * (y의 개수+1) * .... -1

7. [문자열 폭발](https://www.acmicpc.net/problem/9935)
> stack의 원리를 이용해서 푼다고 생각하면 쉽다. 한 글자씩 넣다가 방금 들어온 글자가 폭발 문자열의 마지막 글자와 같으면, 이전 문자열을 확인한다.
> 하나씩 확인했을 때 현재 문자열의 마지막 n글자가 폭발 문자열과 같다면 뒷부분을 삭제한다

8. [방금 그 곡](https://programmers.co.kr/learn/courses/30/lessons/17683)
> C# 또한 하나의 단어(음)으로 판단해야하기 때문에 C#을 소문자 c로 변환해서 풀이하니 더욱 간단해졌다!!! 

9. [가운데를 말해요](https://www.acmicpc.net/problem/1655)
> 최대힙과 최소힙을 이용한 풀이
> ```priority_queue<int> maxHeap```, ```priority_queue<int, vector<int>, greater<int>> minHeap```
> 매번 값이 추가될 때마다 중간값을 출력해야하는 상황에서 시간초과를 피할 수 있는 방법
> 1. 최대힙의 크기는 최소힙의 크기와 같거나 하나 더 크다
> 2. 최대힙의 최대 원소는 최소힙의 최소 원소보다 작거나 같다
> 3. 이 때 알고리즘에 맞지 않다면 최대힙, 최소힙의 가장 위의 값을 swap해준다.  

```
 int solution(int x) {

    if(maxHeap.empty() || (maxHeap.size() == minHeap.size())) maxHeap.push(x);
    else minHeap.push(x);
    
    //minHeap, maxHeap 모두 empty하지 않으며
    //maxHeap의 가장 큰 노드보다 minHeap의 가장 작은 노드가 더 크다면?
    //SWAP
    if(!maxHeap.empty() && !minHeap.empty() && !(maxHeap.top() <= minHeap.top())) {
        int minH = minHeap.top();
        int maxH = maxHeap.top();
        
        minHeap.pop();
        maxHeap.pop();
        
        maxHeap.push(minH);
        minHeap.push(maxH);
    }
    
    return maxHeap.top();
}   
```

10. [백조의 호수](https://www.acmicpc.net/problem/3197)
> 로직 합치기
> 녹을 수 있는 얼음과 백조간의 만남이 가능한지를 한번에 확인하자!
> input으로 board에 대한 정보를 받아올 떄,
 1. water에 대한 위치 정보를 받는다
 2. 현 상태에서 접해있는 녹지 않은 얼음에 대한 위치 정보를 받는다  
 2-1. 이 때 녹은 물을 통해 다른 백조에 다다를 수 있는지도 확인할 수 있다. water를 따라서 BFS를 돌리는 것이므로
 3. 모든 물에 대해 접해있는 얼음이 있다면 녹이기. 단, 현재 물 개수만큼만 for문을 돌린다.
 
> 여기까지를 반복하되, 2의 현상태는 막 녹인 얼음 위치를 의미한다
