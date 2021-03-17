### 10진법을 N진법으로 변환하는 방법
```
vector<string> numbers = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

string transformFormat(int target, int n) {
    string result = "";
    while(target > 0) {
        result += numbers[target % n];
        target /= n;
    }
    reverse(result.begin(), result.end());
    return result;
}
```
