## 부분집합
```
input[] : 숫자 배열
isSelected[ ] : 부분집합에 포함 / 비포함 여부를 저장한 
generateSubSet(cnt)
  if(cnt == N) 부분집합 완성
  else 
    isSelected[cnt] <- true
    generateSubSet(cnt+1) 
    isSelected[cnt] <- false
    generateSubSet(cnt+1)

end generateSubSet()
```

