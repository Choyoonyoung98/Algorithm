import UIKit

var str = "Hello, playground"

//마지막 인자를 포함하는 for문
for i in 0...10 {
    print(i)
}

//마지막 인자를 포함하지 않는 for문
for i in 0..<10 {
    print(i)
}

//역방향으로 진행되는 for문
for i in (0...10).reversed() {
    print(i)
}
