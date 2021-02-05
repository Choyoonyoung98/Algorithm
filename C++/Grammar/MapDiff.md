## unordered_map VS map

가장 큰 차이는 **map은 균형 이진트리(Red-black tree)로 구현되고, unordered_map은 hash방식으로 구현된다는 점입니다.**  
즉, map에 들어가는 element들은 **key** 에 따라 정렬되어 저장됙고, unordered_map은 key의 **hash값** 에 따라서 저장됩니다.  

이러한 특성 때문에 **element들의 개수가 작은 경우** 보통 **unordered_map** 이 조금 더 빠른 속도를 보이지만, 개수가 많은 경우 hash bucket의 충돌이 자주 발생하여 성능이 점차 떨어집니다.  

### Map `O(logN)`
Map은 기본적으로 red-black tree 기반으로 되어 있습니다. 따라서 모든 데이터는 key 값을 기준으로 정렬되어 저장됩니다.  
map의 경우 입력되는 key값의 분포가 고르지 못할 경우 balancing에 대한 비용이 계속 들어가기 때문에 성능이 저하됩니다.  

### Unordered_map `O(1)`
unordered_map은 hash_table 기반의 hash_container입니다.  
node들을 정렬할 필요가 없기 때문에 탐색에서 꾸준한 성능 O(1)을 보장합니다.  


**결론) 정렬이 된 상태로 데이터가 삽입이 되고, iteration 하지 않는 경우에는 unordered map이 더 효율적이라고 볼 수 있습니다!** 
