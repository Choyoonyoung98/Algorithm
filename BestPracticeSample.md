## 유형별 대표 문제 정리

### 1. 그리디
- [x] [뒤집기](https://www.acmicpc.net/problem/1439) [[C++]](C++/BasicExample/Flip1439_C++/Flip1439_C++/main.cpp) [[Swift]](Swift/BasicExample/FlipWord1439/FlipWord1439/main.swift)  
- [x] [ATM](https://www.acmicpc.net/problem/11399) [[C++]](C++/BasicExample/ATM11399/ATM11399/main.cpp) [[Swift]](Swift/BasicExample/ATM11399/ATM11399/main.swift) 
- [x] [동전](https://www.acmicpc.net/problem/11047) [[C++]](C++/BasicExample/Coin11047/Coin11047/main.cpp) [[Swift]](Swift/BasicExample/Coin11047/Coin11047/main.swift)  
- [x] [무지의 먹방 라이브](https://programmers.co.kr/learn/courses/30/lessons/42891) [[C++]](C++/BasicExample/MujiMukbang42891/MujiMukbang42891/main.cpp) [[Swift]](Swift/BasicExample/MujiMukbang42891/MujiMukbang42891/main.swift)  

### 2. 구현
- [x] [럭키 스트레이트](https://www.acmicpc.net/problem/18406) [[C++]](C++/BasicExample/LuckyStraight18406/LuckyStraight18406/main.cpp) [[Swift]](Swift/BasicExample/LuckyStraight18406/LuckyStraight18406/main.swift)
- [x] [자열 압축](https://programmers.co.kr/learn/courses/30/lessons/60057) [[C++]](C++/BasicExample/WordCompression60057/WordCompression60057/main.cpp) [[Swift]](Swift/BasicExample/WordCompression60057/WordCompression60057/main.swift)
- [ ] [자물쇠와 열쇠](https://programmers.co.kr/learn/courses/30/lessons/60059)
- [x] [뱀](https://www.acmicpc.net/problem/3190) [[C++]](C++/BasicExample/Snake3190/Snake3190/main.cpp) [[Swift]](Swift/BasicExample/Snake3190/Snake3190/main.swift)
- [ ] [기둥과 보 설치](https://programmers.co.kr/learn/courses/30/lessons/60061)
- [x] [⭐️치킨 배달](https://www.acmicpc.net/problem/15686) [[C++]](C++/BasicExample/ChickenDelivery15686/ChickenDelivery15686/main.cpp) [[Swift]](Swift/BasicExample/ChickenDelivery15686/ChickenDelivery15686/main.swift)
- [ ] [외벽 점검](https://programmers.co.kr/learn/courses/30/lessons/60062)

### 3. DFS/BFS
- [x] [⭐️특정 거리의 도시 찾기](https://www.acmicpc.net/problem/18352) [[Swift]](Swift/BasicExample/FindCity_18352/FindCity_18352/main.swift)
- [x] [연구소](https://www.acmicpc.net/problem/14502) [[Swift]](Swift/BasicExample/Labatory14502/Labatory14502/main.swift)
- [x] [경쟁적 전염](https://www.acmicpc.net/problem/18405) [[Swift]](Swift/BasicExample/CompetitiveTransmission18405/CompetitiveTransmission18405/main.swift)
- [x] [괄호변환](https://programmers.co.kr/learn/courses/30/lessons/60058) [[Swift]](Swift/BasicExample/TransferBracket60058/TransferBracket60058/main.swift)  
- [ ] [연산자 끼워 넣기](https://www.acmicpc.net/problem/14888)
- [x] [감시 피하기](https://www.acmicpc.net/problem/18428) [[Swift]](Swift/BasicExample/AvoidSurveillance18428/AvoidSurveillance18428/main.swift)
- [x] [인구 이동](https://www.acmicpc.net/problem/16234) [[Swift]](Swift/BasicExample/PopulationMovement16234/PopulationMovement16234/main.swift)

### 4. 정렬
- [x] [국영수](https://www.acmicpc.net/problem/10825) [[Swift]](Swift/BasicExample/KoreanEnglishMath10825/KoreanEnglishMath10825/main.swift)
- [x] [안테나](https://www.acmicpc.net/problem/18310) [[Swift]](Swift/BasicExample/Antenna18310/Antenna18310/main.swift)
- [x] [실패율](https://programmers.co.kr/learn/courses/30/lessons/42889) [[Swift]](Swift/BasicExample/FailureRate42889/FailureRate42889/main.swift)
- [x] [카드 정렬하기](https://www.acmicpc.net/problem/1715) [[Swift]](Swift/BasicExample/CardSorting1715/CardSorting1715/main.swift)

### 5. 이진 탐색 문제(⭐️)
- [x] [⭐️수찾기](https://www.acmicpc.net/problem/1920) [[Swift]](Swift/BasicExample/FindingNumber1920/FindingNumber1920/main.swift)
- [x] [나무자르기](https://www.acmicpc.net/problem/2805) [[Swift]](Swift/BasicExample/CuttingTree2805/CuttingTree2805/main.swift)
- [x] [⭐️⭐️공유기 설치](https://www.acmicpc.net/problem/2110) [[Swift]](Swift/BasicExample/InstallRouter/InstallRouter/main.swift)
> C개의 공유기를 N개의 집에 적당히 설치해서 가장 인접한 두 공유기 사이의 거리를 최대로 하는 문제  
> minDistance = 0, maxDistance = 집 간의 최대 거리로 두어 midDistance를 기준으로 만든다.  
> 집 간의 거리가 midDistance보다 크게 될 때, 공유기를 설치해본다.   
> 설치된 공유기의 갯수가 C개보다 클 경우 maxDistance = midDistance - 1  
> 설치된 공유기의 갯수가 C개보다 같거나 작을 경우 answer에 max값을 담아준 뒤, minDistance = midDistance + 1    

- [x] [예산](https://programmers.co.kr/learn/courses/30/lessons/12982) [[Swift]](Swift/BasicExample/Budget12982/Budget12982/main.swift)
- [x] [⭐️⭐️입국심사](https://programmers.co.kr/learn/courses/30/lessons/43238) [[Swift]](Swift/BasicExample/Immigration43238/Immigration43238/main.swift)
> 모든 사람이 심사를 받는데 걸리는 시간의 최소값을 return하는 문제  
> low = 0, high = 모든 인원 수 * 가장 긴 심사 시간  
> time에 대한 for문을 돌려 전체 심사시간(mid) 동안 담당할 수 있는 수를 sum에 모두 더한다  
> 이 sum이 n(고객 수)보다 같거나 크면, high = mid - 1 , answer를 업데이트해준다.  
> 이 sum(담당할 수 있는 고객의 총 수)가 n(실제 고객 수)보다 작으면 low = mid + 1로 변경해준다.  

- [x] [⭐️⭐️⭐️징검다리](https://programmers.co.kr/learn/courses/30/lessons/43236) [[Swift]](Swift/BasicExample/SteppingSone43236/SteppingSone43236/main.swift)
- [ ] [⭐️가사 검색](https://programmers.co.kr/learn/courses/30/lessons/60060)

### 6. 다이나믹 프로그래밍 문제
- [x] [1,2,3 더하기](https://www.acmicpc.net/problem/9095) [[Swift]](Swift/BasicExample/123Plus9095/123Plus9095/main.swift)
- [x] [2xn 타일링](https://www.acmicpc.net/problem/11726) [[Swift]](Swift/BasicExample/2NTiling/2NTiling/main.swift)
- [x] [⭐️동전](https://www.acmicpc.net/problem/2293) [[Swift]](Swift/BasicExample/Coin2293/Coin2293/main.swift)
- [x] [⭐️RGB거리](https://www.acmicpc.net/problem/1149) [[Swift]](Swift/BasicExample/RGBDistance1149/RGBDistance1149/main.swift)
- [x] [정수 삼각형](https://www.acmicpc.net/problem/1932) [[Swift]](Swift/BasicExample/IntegerTriangle1932/IntegerTriangle1932/main.swift)
- [x] [⭐️퇴사](https://www.acmicpc.net/problem/14501) [[Swift]](Swift/BasicExample/Quit14501/Quit14501/main.swift)
- [x] [⭐️(LIS)병사 배치하기](https://www.acmicpc.net/problem/18353) [[Swift]](Swift/BasicExample/SoldierPlacement18353/SoldierPlacement18353/main.swift)
- [x] ⭐️못생긴 수 [[Swift]](Swift/BasicExample/UglyNumber35/UglyNumber35/main.swift)
> 못생긴 수란 오직 2,3,5만을 소인수로 가지는 수를 의미합니다. 다시 말해 오직 2,3,5를 약수로 가지는 합성수를 의미합니다. 1은 못생긴 수라고 가정합니다. 따라서 못생긴 수들은 {1,2,3,4,5,6,8,9,10,12,15, ...} 순으로 이어지게 됩니다. 이때 n번째 못생긴 수를 찾는 프로그램을 작성하세요, 예를 들어 11번째 못생긴 수는 15입니다.  
- [ ] [⭐️(LCS)편집 거리](https://www.acmicpc.net/problem/7620)

### 7. 최단 경로
- [x] [플로이드](https://www.acmicpc.net/problem/11404) [[Swift]](Swift/BasicExample/Floyd11404/Floyd11404/main.swift)
- [x] ⭐️정확한 순위 [[Swift]](Swift/BasicExample/ExactRanking38/ExactRanking38/main.swift)
> 선생님은 시험을 본 학생 N명의 성적을 분실하고, 성적을 비교한 결과의 일부만을 가지고 있습니다. 
첫 번째 줄에 학생들의 수 N(2<= N <= 500)과 두 학생의 성적을 비교한 횟수(2<= M <= 10000)이 주어집니다. 
다음 M개의 줄에는 두 학생의 성적을 비교한 결과를 나타내는 두 양의 정수 A와 B가 주어집니다. 이는 A번 학생의 성적이 B번 학생보다 낮다는 것을 의미합니다. 이러한 문제에 대해 첫째 줄에 성적 순위를 정확하게 알 수 있는 학생이 몇명인지 출력합니다. 

> 하나의 학생에 대해 다른 모든 학생들과의 성적 비교가 가능하면 그 학생의 성적 순위를 정확하게 알 수 있습니다. 특히 A학생으로부터의 B학생과의 비교 또는 B학생으로부터의 A학생과의 비교 중 어느 하나만 알더라도 비교가 가능하다는 사실을 잊지말아야 합니다.  

- [x] 화성 탐사 [[Swift]](Swift/BasicExample/MarsExploration39/MarsExploration39/main.swift)
- [x] 숨바꼭질 [[Swift]](Swift/BasicExample/HideAndSeek40/HideAndSeek40/main.swift)

### 8. 그래프 이론
- [x] 여행 계획 [[Swift]](Swift/BasicExample/TravelPlan41/TravelPlan41/main.swift)
> 첫째 줄에 여행지의 수 N과 여행 계획에 속한 도시의 수 M이 주어집니다. 다음 N개의 줄에 걸쳐 N x N 행렬을 통해 임의의 두 여행지가 서로 연결되어 있는지 여부가 주어집니다.  
그 값이 1이라면 서로 연결되었다는 의미이며, 0이라면 서로 연결되어 있지 않다는 의미입니다. 마지막 줄에 한올이의 여행 계획에 포함된 여행지의 번호들이 주어지며 공백으로 구분합니다.  
첫째 줄에 한울이의 여행 계획이 가능하다면 YES, 불가능하다면 NO를 출력합니다.  
- [x] ⭐️탐승구  [[Swift]](Swift/BasicExample/Gate42/Gate42/main.swift)
- [x] 어두운 길  [[Swift]](Swift/BasicExample/DarkStreet43/DarkStreet43/main.swift)
- [x] [행성 터널](https://www.acmicpc.net/problem/2887)  [[Swift]](Swift/BasicExample/PlanetTunnel2887/PlanetTunnel2887/main.swift)
- [x] [최종 순위](https://www.acmicpc.net/problem/3665)  [[Swift]](Swift/BasicExample/FinalRanking3665/FinalRanking3665/main.swift)

### 9. 투포인터
- [x] [수들의 합2](https://www.acmicpc.net/problem/2003)  [[Swift]](Swift/BasicExample/SumOfNumbers(2)2003/SumOfNumbers(2)2003/main.swift)
- [x] [소수의 연속합](https://www.acmicpc.net/problem/1644)  [[Swift]](Swift/BasicExample/SequenceSumOfPrimeNumbers1644/SequenceSumOfPrimeNumbers1644/main.swift)
- [x] [부분합](https://www.acmicpc.net/problem/1806)  [[Swift]](Swift/BasicExample/SubTotal1806/SubTotal1806/main.swift)
- [x] [수 고르기](https://www.acmicpc.net/problem/2230)  [[Swift]](Swift/BasicExample/PickNumber2230/PickNumber2230/main.swift)
- [x] [다이어트](https://www.acmicpc.net/problem/1484)  [[Swift]](Swift/BasicExample/Diet1484/Diet1484/main.swift)

### 10. 부루트 포스
- [x] [⭐️분해합](https://www.acmicpc.net/problem/2231)  [[Swift]](Swift/BasicExample/Decomposition2231/Decomposition2231/main.swift)
- [ ] [일곱 난쟁이](https://www.acmicpc.net/problem/2309)
- [ ] [블랙잭](https://www.acmicpc.net/problem/2798)

### 11. 슬라이딩 윈도우
- [x] [N번째 큰 수](https://www.acmicpc.net/problem/2075)  [[Swift]](Swift/BasicExample/NthBiggestNumber2075/NthBiggestNumber2075/main.swift)
- [x] [내려가기](https://www.acmicpc.net/problem/2096)  [[Swift]](Swift/BasicExample/GoDown2096/GoDown2096/main.swift)
- [ ] [회전초밥](https://www.acmicpc.net/problem/2531)

> 투 포인터와 슬라이딩 윈도우는 배열의 처음부터 순차적으로 탐색하고 **부분 배열** 을 꺼내본다는 점에서는 같습니다.  
하지만 투 포인터는 부분 배열의 길이가 **가변적(늘었다 줄었다)** 이지만, 슬라이딩 윈도우는 부분 배열의 길이가 **고정적(일정)** 입니다.

#### 12. 문자열
- [x] [괄호](https://www.acmicpc.net/problem/9012) [[Swift]](Swift/BasicExample/Bracket9012/Bracket9012/main.swift)
- [x] [그룹 단어 체커](https://www.acmicpc.net/problem/1316) [[Swift]](Swift/BasicExample/GroupWordChecker/GroupWordChecker/main.swift)
- [x] [제로](https://www.acmicpc.net/problem/10773) [[Swift]](Swift/BasicExample/Zero10773/Zero10773/main.swift)
- [ ] [LCS](https://www.acmicpc.net/problem/9251)

#### 13. [순열/조합](https://www.acmicpc.net/workbook/view/2052)
- [x] [N과 M(1)](https://www.acmicpc.net/problem/15649) [[Swift]](Swift/BasicExample/NandM/NandM_1/NandM_1/main.swift)
- [x] [N과 M(2)](https://www.acmicpc.net/problem/15650) [[Swift]](Swift/BasicExample/NandM/NandM_2/NandM_2/main.swift)
- [x] [N과 M(3)](https://www.acmicpc.net/problem/15651) [[Swift]](Swift/BasicExample/NandM/NandM_3/NandM_3/main.swift)  
- [x] [N과 M(4)](https://www.acmicpc.net/problem/15652) [[Swift]](Swift/BasicExample/NandM/NandM_4/NandM_4/main.swift)  
- [x] [N과 M(5)](https://www.acmicpc.net/problem/15654) [[Swift]](Swift/BasicExample/NandM/NandM_5/NandM_5/main.swift)  
- [x] [N과 M(6)](https://www.acmicpc.net/problem/15655) [[Swift]](Swift/BasicExample/NandM/NandM_6/NandM_6/main.swift)  
- [x] [N과 M(7)](https://www.acmicpc.net/problem/15656) [[Swift]](Swift/BasicExample/NandM/NandM_7/NandM_7/main.swift)  
- [x] [N과 M(8)](https://www.acmicpc.net/problem/15657) [[Swift]](Swift/BasicExample/NandM/NandM_8/NandM_8/main.swift)  
- [x] [N과 M(9)](https://www.acmicpc.net/problem/15663) [[Swift]](Swift/BasicExample/NandM/NandM_9/NandM_9/main.swift)  
- [x] [N과 M(10)](https://www.acmicpc.net/problem/15664) [[Swift]](Swift/BasicExample/NandM/NandM_10/NandM_10/main.swift)  
- [x] [N과 M(11)](https://www.acmicpc.net/problem/15665) [[Swift]](Swift/BasicExample/NandM/NandM_11/NandM_11/main.swift)  
- [x] [N과 M(12)](https://www.acmicpc.net/problem/15666) [[Swift]](Swift/BasicExample/NandM/NandM_12/NandM_12/main.swift)  

<hr/>    

#### - [에라토스테네스의 체](https://www.acmicpc.net/problem/2960)   
#### - [삼성 SW 역량 테스트](https://www.acmicpc.net/workbook/view/1152)   
#### - [삼성 A형 기출 문제](https://www.acmicpc.net/workbook/view/2771)   
#### - [틀리기 쉬운 문제](https://www.acmicpc.net/workbook/view/4357)   
#### - 예외 테스트케이스 찾기
1) 0또는 1의 길이 및 0 또는 1이 입력값으로 주어질 때
2) 입력값이 범위를 초과할 때
