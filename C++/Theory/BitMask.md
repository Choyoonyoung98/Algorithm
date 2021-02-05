## BitMask

### isstream
```
string key[4], temp; // 4가지 항목
int score; // 점수
vector<string> info = {"java backend junior pizza 150","python frontend senior chicken 210"};
for(auto& inf: info) { //(*) auto&
  istringstream iss(inf);
  iss >> key[0] >> key[1] >> key[2] >> key[3] >> score;
  //key[0] = java, key[1] = backend, key[2] = junior, key[3] = pizza, score = 150
  for(int i=0; i<16; i++) insert(key, i, score);
}
```

```
void insert(string* key, int mask, int point) { //*
    string s = "";
    for(int i=0; i<4; i++) {
    //(mask & (1 << i)): i번째 요소를 검사한다 -> 존재하면 양수, 존재하지 않으면 음수
    /*
    0000 & 0, 1, 2, 3 << 0 -> java+backend+junior+pizza
    0001 & 0, 1, 2, 3 -> - + backend + junoir + pizza
    0010 & 0, 1, 2, 3 -> java + - + junior + pizza
    0011 & -> - + - + junior + pizza
    4
    */
        s += (mask & (1 << i)) ? ALL : key[i];
        m[s].push_back(point);
    }
}
```

1. data의 i번째 요소를 추가  
```data | (1 << i) ```
2. data의 i번째 요소를 검사 ( 존재하지 않으면 음수)  
```data & (1 << i)```
3. data의 i번째 요소를 제거  
```data & ~(1 << i)```
4. data의 i번째 요소를 변경  
```data ^ (1 << i)
