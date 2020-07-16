## 에라토스테네스의 체(Sieve of Eratosthenes)
소수가 아닌 것들은 모두 체크해버리는 방식.  

- 2를 제외한 모든 2의 배수를 체크
- 3을 제외한 모든 3의 배수를 체크
- 4를 제외한 모든 4의 배수를 체크
...
 이 때 체크가 안된 수들이 소수  
 
 아래와 같이 구현 가능  
 ```
 int arr[MAX_SIZE];
 
 voi solution(int num) {
 
   //초기화 - 입력받은 수만큼 배열에 모두 초기화
   for(int i=2; i<= num; i++) {
     arr[i] = i;
    }
    
    //소수가 아닌 숫자 체크
    for(int i=2; i<=num; i++) {//나누는 값:i
      for(int j=2; j<=num; j++) {
        //자신과 같지 않고 0으로 나누어 떨어지면 소수가 아님으로 판단.
        if(arr[j] != i && arr[j]%i == 0) arr[j] = 0;//소수가 아닌 경우 0을 넣는다.
       }
     }
     
     //출력
     for(int i=2; i<=num; i++) {
       if(arr[i] != 0) cout<<arr[i];
     }
 }
 ```
 
 여기서 더 나아가 최적의 방법을 생각해보자면,  
 체크할 때,  
 1. 모든 수를 다 돌면서 체크할 필요 없이 **체크할 때 배수만큼만 반복문을 돌게하는 것**  
 2. 이미 **0**으로 체크되어버린 수의 배수는 확인하지 않는다.  
  ```
 int arr[MAX_SIZE];
 
 voi solution(int num) {
 
   //초기화 - 입력받은 수만큼 배열에 모두 초기화
   for(int i=2; i<= num; i++) {
     arr[i] = i;
    }
    
    //소수가 아닌 숫자 체크
    for(int i=2; i<=num; i++) {//나누는 값:i
      if(arr[i]!= 0) {
        for(int j=i+i; j<=num; j+=i) arr[j] = 0;
       }
     }
     
     //출력
     for(int i=2; i<=num; i++) {
       if(arr[i] != 0) cout<<arr[i];
     }
 }
 ```
 
 +) 소수는 n의 배수가 아니어야 한다.  
 입력받은 수를 입력받은 수보다 작은 수들로 나누어서 떨어지면 소수가 아니다.  
 그러나 모두 나누어볼 필요없이, 루트 n까지만 나누어서 떨어지면 소수가 아니다.  
 ```
 //소수가 아닌 숫자 체크
 for(int i=2; i<=num; i++) {//나누는 값:i
   if(arr[i]!= 0) {
     for(int j=i+i; j<=num; j+=i) arr[j] = 0;
    }
  }
 ```
 
