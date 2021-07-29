//// 210729 멋사 코테 스터디 1주차 - HASH
// 문제 1. 완주하지 못한 선수

// 자료구조
// : 대량 정보를 main memory에 효율적, 체계적 방법으로 관리, 구조화
// 여러 종류가 있으며 각자의 연산 및 목적에 맞추어 있음
// 어떠한 자료구조를 사용하느냐에 따라 공간의 효율성과 프로그램의 실행시간이 달라짐

// ADT
// : data type structure을 추상화(단순화) Abstract
// 순수하게 기능이 무엇인지 나열한것
// 특정 자료형과 그 자료형을 바탕으로 하는 기능(함수)들의 집합

// Map
// : 원소를 저장하고 그것을 key를 이용하여 빠르게 찾도록 함
// entry라는 key-value 쌍을 저장함
// map ADT에서 각 key는 유일하여, key-value의 연관은 mapping을 정의함
// 어떠한 객체 type 모두 ㄱㄴ

// key 
// : 응용 프로그램이나 사용자에 의해 연관된 값 객체에 할당된 유일한 식별자
// -> map은 각 key가 연관된 값 value에 대해 유일한 index 주소 역할을 함
// -> key는 value에 대해 일종의 위치, 객체의 주소 역할을 하는 객체 ㅇㅇ

// Hash Table 
// : Map을 구현하는 가장 효율적인 방법 중 하나
// map 연산의 실행 시간 : 최악일 떄 O(n)이지만 이들 연산 평균은 O(1)
// bucket 배열 + Hash Function으로 구성

// Bucket 배열
// : 크기가 N인 배열 A (key-value 값을 저장하는 container)
// 충돌 걱정 ㄴㄴ
// 하지만 O(N)의 공간을 사용 - 공간 낭비일 수도 & key들 배치가 좋아하야하는데 not easy
// -> key를 [0, N-1] 범위 안의 정수로 변환하는 '좋은 매핑'을 한다!!!

// Hash Function
// : h function, 각 key를 [0, N-1] 범위의 정수로 변환함
// -> 이 함수를 통해서 임의의 key에 대하여 bucket 배열 방법을 적용할 수 있음
// -> key 대신에 Hash function 값 h(k)를 bucket 배열 A의 index로 사용함 ㅇㅇ
// -> 즉, entry (k, v)를 bucket A[h(k)]에 저장한다
// * 두 개 이상 key들이 같은 hash값을 가지면 
// 여러 원소들이 A의 같은 bucket에 mapping될 수도 있음 -> "층돌"


//// 생성자 constructor
https://min-zero.tistory.com/entry/C-%EA%B8%B0%EB%B3%B8-%EA%B3%B5%EB%B6%80%EC%A0%95%EB%A6%AC-14-4-OOP-%EC%83%9D%EC%84%B1%EC%9E%90constructor

: class 정의 후에 class 객체를 생성하게 되면 메모리에 할당된다
이때 class 멤버의 변수는 초기화되지 않은 상태라 사용 못함
객체를 사용하기 전에 무조건 해당 멤버함수를 실행하고 객체를 사용해야함
-> 객체의 생성과 동시에 멤버 변수를 초기화해주는 멤버함수 : 생성자

class명과 동일, 외부에서 class를 생성 동시에 동작해야해서 public에 생성하자
인수를 통해서 값을 전달받을 수 잇음
생성자 3가지 타입 : 기본 생성자, 디폴트 생성자, 복사 생성자

- 기본 생성자 
: 매개변수를 통해 객체가 생성될 때 전달받은 인자 값으로 멤버 변수 초기화
Hash(int N){} 이렇게 생성한 생성자를 통해서 객체를 생성하면서 초기화

- 디폴트 생성자 
: 객체를 생성할 때 아무런 인자를 넘겨주지 않을 떼 멤버함수 초기화

- 복사 생성자

//// vector
: 원소의 index에 의하여 원소에 접근할 수 있도록 지원해주는 배열 리스트
확장 가능한 Extendable Array, Growable




// feedback - 1 (PSJ)
// 완주자를 hash table에 저장하고 참가자 vector와 비교
// 동명이인 찾을 시 완주자를 hash에서 지워감

#include <string>
#include <vector>

using namespace std;

// 참가자를 vector로 하는데 왜 Node와 LinkedList 까지 구현하는지 check


// Hash Table을 위한 class Hash
class Hash
{
    public:
        // 생성자 - 객체 생성과 동시에 초기화 진행
        Hash(int N)
        {
            participant = new LinkedList[N];
            sz=N;
        }

        // 완주자를 hash에 저장하기 위한 함수
        void insert(string Name)
        {
            Node* newNode = new Node(name);
            participant[hashingName(name)].insert(newNode); // 참가자가 vector라서 insert함수 가져옴
        }

}

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    // 완주자를 hash table에 저장 -> class Hash가 필요
    Hash hash(participant.size()); // 생성자 Hash(int N) {}한테 인수 전달
    int result;
    for (int i = 0;i<completion.size();i++)
    {
        hash.insert(completion.size(); i++) // insert통해서 완주자를 hash에 저장함
    }


    return answer;
}