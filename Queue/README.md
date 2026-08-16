# Queue

## 1. 개념

Queue는 한쪽 끝에서 데이터를 삽입하고 다른 쪽 끝에서 삭제할 수 있는 자료구조이다.

* FIFO (First In First Out)
* 가장 먼저 들어온 데이터가 가장 먼저 나온다.
* 삽입은 뒤쪽(rear/back), 삭제는 앞쪽(front)에서 이루어진다.

---

## 2. 주요 연산

| 연산 | 설명 |
| :--- | :--- |
| enqueue | 데이터 삽입 (rear) |
| dequeue | 데이터 삭제 (front) |
| peek / front | 최선두 데이터 확인 |
| isEmpty | 큐가 비어있는지 확인 |
| isFull | 큐가 가득 찼는지 확인 |

---

## 3. 큐 동작과정

1. **초기 상태**: front와 rear가 같은 위치(또는 -1)를 가리킴
2. **enqueue(A)**: rear 위치에 A 추가 후 rear 1 증가
3. **enqueue(B)**: rear 위치에 B 추가 후 rear 1 증가
4. **dequeue()**: front 위치의 A 삭제(반환) 후 front 1 증가

> **참고 (선형 큐 vs 원형 큐)**
> * **선형 큐**: dequeue 연산 시 앞쪽 메모리 공간이 남게 되어 공간 효율성이 떨어짐
> * **원형 큐**: 배열의 처음과 끝을 연결하여 메모리 공간을 재사용하는 구조