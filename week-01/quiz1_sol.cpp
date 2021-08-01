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
// https://min-zero.tistory.com/entry/C-%EA%B8%B0%EB%B3%B8-%EA%B3%B5%EB%B6%80%EC%A0%95%EB%A6%AC-14-4-OOP-%EC%83%9D%EC%84%B1%EC%9E%90constructor

// : class 정의 후에 class 객체를 생성하게 되면 메모리에 할당된다
// 이때 class 멤버의 변수는 초기화되지 않은 상태라 사용 못함
// 객체를 사용하기 전에 무조건 해당 멤버함수를 실행하고 객체를 사용해야함
// -> 객체의 생성과 동시에 멤버 변수를 초기화해주는 멤버함수 : 생성자

// class명과 동일, 외부에서 class를 생성 동시에 동작해야해서 public에 생성하자
// 인수를 통해서 값을 전달받을 수 잇음
// 생성자 3가지 타입 : 기본 생성자, 디폴트 생성자, 복사 생성자

// - 기본 생성자 
// : 매개변수를 통해 객체가 생성될 때 전달받은 인자 값으로 멤버 변수 초기화
// Hash(int N){} 이렇게 생성한 생성자를 통해서 객체를 생성하면서 초기화

// - 디폴트 생성자 
// : 객체를 생성할 때 아무런 인자를 넘겨주지 않을 떼 멤버함수 초기화

// - 복사 생성자

// //// vector
// https://coding-factory.tistory.com/596

// : 원소의 index에 의하여 원소에 접근할 수 있도록 지원해주는 배열 리스트
// 확장 가능한 Extendable Array, Growable 크기가 자동으로 늘어남
// 순차 컨테이너 sequence container -> 자료를 순서대로 저장하는 구조
// Array에 비해 속도는 낮지만 메모리를 효율적으로 관리 가능!



// //// 자료를 저장하는 방법 - Array, LinkedList

// // Array
// : 매우 빠르게 접근 가능, 메모리 사용 비효율적, 배열 내의 데이터 이동 어렵

// // LinkedList
// : 동적으로 메모리 사용 가능, 데이터 재구성 용이, 대용량 데이터 처리 굿
// : 특정 위치 데이터 검색할 때 느림, 메모리를 추가적으로 사용해야함

// // Node
// : LinkedList는 Node라는 객체로 구성
// : data + Next address(다음 주소를 가르킬 공간) 로 구성
// : 정보를 data 영역에 담고, Node가 추가될 때마다 Next address를 이용하여 다음 Node와 연결
// : 연속된 공간이 아닌 메모리의 여러 부분에 분포되어 있음
// : 각 Node에 다음 Node의 주소를 저장함으로써 다음 Node 탐색 가능
// -> Next address를 가리켜야해서 'pointer'로 구현하자 


// // pointer
// : 메모리의 주소값을 저장하는 변수
// 포인터 변수는 해당 변수의 시작 주소를 저장해 저 변수를 가리키고 있음
// pointer도 변수라서 주소 값을 가짐
// int* pa = &a;
// -> 포인터 변수 pa에 변수 a의 주소값 저장하여 a를 가리키고 있음
// &a : 주소 연산자 - 변수가 할당된 메모리의 시작 주소
// *pa : 참조 연산자 - 해당 주소를 참조하여 주소에 저장되어있는 값 반환


// feedback - 1 (PSJ)
// 완주자를 hash table에 저장하고 참가자 vector와 비교
// 동명이인 찾을 시 완주자를 hash에서 지워감

#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 참가자를 vector로 하는데 왜 Node와 LinkedList 까지 구현하는지 check
// -> 굳이 구현 안해도 된다고 하지만 난 공부해야해서 기릿

// Node 구현 
class Node 
{
    public:
        string name;
        Node* next; // 다음 Node의 주소를 저장할 pointer 선언

        // 생성자
        Node()
        {
            name = "";
            next = NULL;
        }
        Node(string name) {
            this -> name = name;
            next = NULL;
        }
};

// LinkedList 구현
class LinkedList
{
    public:
        Node* head; // head, tail pointer 선언
        Node* tail;
        int sz;
    
    LinkedList()
    {
        head = new Node;
        tail = new Node;
        head = tail = NULL;
        sz = 0;
    }

    bool empty()
    {
        return head == NULL && tail == NULL;
    }

    void insert(Node* newNode)
    {
        if (empty())
        {
            head = tail = newNode;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
        sz++;
    }
};


// Hash Table을 위한 class Hash
class Hash
{
    public:
        LinkedList* participant;
        int sz;

        // 생성자 - 객체 생성과 동시에 초기화 진행
        Hash(int N)
        {
            participant = new LinkedList[N];
            sz=N;
        }

        // Hash Function
        int hashingName(string name)
        {
            int hash = 0;
            for (char c : name) // 범위기반 for문 - 처음부터 끝까지 순회
            {
                hash += int(c); // int로 형변환
            }
            return hash % sz; // 각 key를 [0, N-1] 범위의 정수로 변환
        }

        // 완주자를 hash에 저장하기 위한 함수
        void insert(string name)
        {
            Node* newNode = new Node(name);
            participant[hashingName(name)].insert(newNode); // 참가자가 vector라서 insert함수 가져옴
        }

        // 동명이인 찾기 - 한 번 찾은 완주자는 LinkedList에서 삭제
        int find(string name)
        {
            Node* previous, * current;
            int flag = 0;

            previous = current = participant[hashingName(name)].head;

            while (current != NULL)
            {
                if (name == current -> name)
                {
                    flag = 1;
                    break;
                }
                previous = current;
                current = current -> next;
            }

            // 찾은 완주자가 LinkedList의 head인 경우
            if (flag == 1)
            {
                if (current == participant[hashingName(name)].head)
                {
                    if (participant[hashingName(name)].sz == 1)
                    {
                        participant[hashingName(name)].head = participant[hashingName(name)].tail == NULL;
                    }
                    else
                    {
                        participant[hashingName(name)].head = current -> next;
                    }
                }

                // 찾은 완주자가 LinkedList의 head가 아닌 경우
                else
                {
                    previous -> next = current -> next;
                    if (participant[hashingName(name)].tail)
                        participant[hashingName(name)].tail = previous;
                }
                return flag;
            }
            return flag;
        }  
};


string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    // 완주자를 hash table에 저장 -> class Hash가 필요
    Hash hash(participant.size()); // 생성자 Hash(int N) {}한테 인수 전달
    int result;
    for (int i = 0;i<completion.size();i++)
    {
        hash.insert(completion[i]); // insert통해서 완주자를 hash에 저장함
    }

    // 참가자 vector를 순회하면서 hash에 저장된 완주자와 비교
    for (int i=0; i<participant.size(); i++)
    {
        result = hash.find(participant[i]);
        
        // 찾지 못한 경우 (완주 x)
        if (result == 0)
        {
            answer += participant[i];
            break;
        }
    }

    return answer;
}


// feedback - 2 (LJH)
// 동명이인 나오면 해당값 더해주고 처리하면 감소시키는 방식 -> 완주 못하는 사람 찾기
// iterator 사용하여 find 메소드 사용했을시 key가 존재아지 않으면 map.end반환 -> 존재하지 않은 ㅏ람 찾음


// https://blog.naver.com/webserver3315/221678909965 
// key-value 연관 -> 연관 container
// 연관 container STL : Set & Map
// set : key만 보관, map ; value까지 같이 보관 (메모리 크게 차지함)
// 정렬이 필요 없으면 unorderd_map 활용하자

// // 반복자 Iterator
// : 배열의 요소를 가르키는 pointer(메모리의 주소값을 저장하는 변수)
// vector, deque, set, map, list 같은 container에 저장되어 있는 원소를 참조(접근)
// stack, queue는 없음

#include <string>
#include <vector>
#include <unordered_map>

#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    // 선언
    unordered_map<string, int> mapForCompletion;

    // find()메소드가 iterator 반환하기에 반복자 mapIter 선언
    unordered_map<string, int>::iterator mapIter;

    for (int i=0; i<completion.size(); i++)
    {
        mapForCompletion[completion[i]] += 1;
    }

    for (int i=0; i<participant.size(); i++)
    {
        mapIter = mapForCompletion.find(participant[i]);

        // find 메소드가 못 찾을 때 해당 map의 end() 반환
        if (mapIter == mapForCompletion.end())
        {
            return participant[i];
        }
        else
        {
            mapIter -> second -= 1;
            // map의 value 중복횟수 -> 1씩 감소시키다가 0이하면 return 
            if (mapIter -> second < 0)
            {
                return participant[i];
            }
        }
    }

    return answer;
}


// feedback - 3 (SYS)
// key-value 갖는 map 사용
// key : 선수 이름, value : 답을 알기 위해 설정한 정수 (-1, 0, 1)
// 완주자 vector 돌면서 각각의 이름을 key로 했을 때 value에 1을 더함
// (map의 value가 int형이면 기본default 0을 가짐)
// 그리고 참가자 vector을 돌며서 다시 value에서 1을 빼줌
// value가 -1 이 되는 참가자가 정답!!!


#include <string>
#include <vector>
#include <map>

#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    // key : 선수 이름, value : 완주하지 못한 선수를 구별하기 위한 정수
    map<string, int> m;

    for (string c : completion)
    {
        m[c]++; // 완주자 이름을 key로 했을 때 value 1+
    }
    
    for (string p : participant)
    {
        m[p]--; // 참가자 이름을 key로 했을 때 value 1-
        if (m[p] == -1)
        {
            // 완주자 vector에 없고 참가자에만 있을 때 value : -1
            return p;
        }   
    }
}

// 정렬 풀이
#include <algorithm>

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    int num = completion.size();
    for (int i{0}; i<num; i++)
    {
        if (participant[i] != completion[i])
        {
            return participant[i];
        }
    }

}


// feedback - 3 (KYJ)
// map STL 사용
// key값 중복 피하기 위해 map에 처음 key값으로 들어오는 경우 & 기존 경우 나눠서 insert
// 처음은 1, 아닌 경우는 중복의 수 만큼
// completion으로 완주하는 사람들을 제외하기 위해 해당 key 찾을 때마다 value에 1 감소
// 그러므로 map에 있는 value값이 0이 아닌 경우 : 완주 못한 경우

#include <string>
#include <vector>
#include <map>

#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    map<string, int> m;
    
    for (int i=0; i<participant.size(); i++)
    {
        if (m.find(participant[i]) == m.end())
            m.insert({participant[i], 1});
        else
            m.find(participant[i])->second++;
    }

    for (int i=0; i<completion.size(); i++)
    {
        if (m.find(completion[i]) != m.end())
            m.find(completion[i])->second--;
    }

    for (auto iter = m.begin(); iter!= m.end(); iter++)
    // begin 함수에 input에 따라 반환하는 iterator의 객체 자료형이 다르므로 auto 선언
    {
        if (iter->second != 0)
            answer = iter->first;
    }

    return answer;
}


// feedback - 5 (HSJ, SJS)
// 각각 정렬하면 순서가 같아져서 순서대로 비교
// for문으로 비교하다가 다르면 해당 participant return

#include <string>
#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    // 각각 정렬
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int i=0; i<completion.size(); i++)
    {
        if (participant[i] != completion[i])
            return participant[i];
    }

    // 완주자 모두 다 돌았는데 return 없으면 참가자 제일 마지막 값 return
    return participant[participant.size() - 1];
}