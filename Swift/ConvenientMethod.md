### 1. `for case let element as YourClass in array`
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
   
### 2. `enumerated()`
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
    
### 3. `first(where:)`
  - Instead
  ```
  if let element = array.filter { $0.title.contains(searchString)}.first { }
  ```
    
  - Better
  ```
  if let element = array.first(where: {$0.title.contains(searchString)}) { }
  ```
  
