#### 1. `for case let element as YourClass in array`
 - Instead
 ```
 for element in array {
  if let element = element as? YourClass { }
 }
 ```
 
 - Better
 ```
 for case let element as YourClass in array {
 }
 ```  
   
#### 2. `enumerated()`
 - Instead
  ```
  for i in 0..<array.count {
    let element = array[i]
  }
  ```
  
  - Better
  ```
  for (i, element) in array.enumerated() {
  }
  ```  
    
#### 3. `first(where:)`
  - Instead
  ```
  if let element = array.filter { $0.title.contains(searchString)}.first { }
  ```
    
  - Better
  ```
  if let element = array.first(where: {$0.title.contains(searchString)}) { }
  ```
  
#### 4. `contains(where: ):`
  - Instead
  ```
  if array.filter { !$0.isActive }.count > 0 { }
  ```
    
  - Better
  ```
  if array.contains(where: { !0.isActive }) { }
  ```
  
#### 5. `isEmpty`
  - Instead
  ```
  if array.count == 0 { }
  ```
    
  - Better
  ```
  if array.isEmpty { }
  ```
  
#### 5. `forEach`
  - Instead
  ```
  for element in array { }
  ```
    
  - Better
  ```
  array.forEach { doSomething(with: $0) }
  ```
 
#### 6. map, compactMap, filter, etc 등의 고차함수 사용
#### 7. guard
#### 8. defer
#### 9. Calculated properties VS Calculated method
> 어떤 계산을 하고자하는 것을 명시적으로 보여주고자 할 경우에는 함수를 사용하고, 그게 아니라면 변수를 사용하라.

#### 10. 가능하면 self의 사용을 지양하라.
#### 11. unwrapping 시 변수의 이름을 새로 짓지마라.
#### 12. 프로토콜과 Extension을 적극적으로 활용하라.
#### 13. Protocols VS Subclassing
> 상속이 아닌 프로토콜을 사용하도록 노력해라. 프로토콜은 코드를 조금 더 유연하게 만드는데, 클래스는 하나 이상의 프로토콜을 채택하여 사용할 수 있다.  
> 또한 struct와 enum은 상속을 사용할 수 없지만, 프로토콜을 채택할 수 있다.  

#### 14. Struct VS Class
> 클래스보다 struct를 사용하도록 해라. struct는 멀티 스레드 환경에서 더 안정적이고 빠르며, init 함수가 있다.  
> 또한 class는 레퍼런스타입인 반면에, struct는 값타입이다. 이는 클래스가 같은 값에 대한 레퍼런스를 가지고 있는 반면, struct의 인스턴스가 독립적인 복사값을 가지고 있다는 뜻이다.  

