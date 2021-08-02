// 문제 3. 위장

// feedback - 1 (PSJ)
// 종류를 기준으로 해싱하여 hash table에 저장
// 각 종류에 대해서 하나를 고르거나 안 고르는 경우의 수 계산
// 모든 아이템을 고르지 않는 경우는 -1

#include <string>
#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;

// YB feedback -> hash 익숙해지면 구현말고 STL에 가져와서 쓰자


// Node 구현 
class Node 
{
    public:
        string name;
        string type;
        Node* next; // 다음 Node의 주소를 저장할 pointer 선언

        // 생성자
        Node()
        {
            next = NULL;
        }
        Node(string name, string type) {
            this -> name = name;
            this -> type = type;
            next = NULL;
        }
};

// LinkedList 구현
class LinkedList
{
    public:
        Node* head; // head, tail pointer 선언
        Node* tail;
    
    LinkedList()
    {
        head = new Node;
        tail = new Node;
        head = tail = NULL;
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
    }
};


// Hash Table을 위한 class Hash
class Hash
{
    public:
        LinkedList* arr;
        int sz;

        // 생성자 - 객체 생성과 동시에 초기화 진행
        Hash(int N)
        {
            arr = new LinkedList[N];
            sz=N;
        }

        // Hash Function
        int hashingType(string type)
        {
            int hash = 0;
            for (char c : type) // 범위기반 for문 - 처음부터 끝까지 순회
            {
                hash += int(c); // int로 형변환
            }
            return hash % sz; // 각 key를 [0, N-1] 범위의 정수로 변환
        }

        // 종류를 hash에 저장하기 위한 함수
        void insert(string name, string type)
        {
            Node* newNode = new Node(name, type);
            arr[hashingType(type)].insert(newNode);
        }

        int find(string type)
        {
            int count = 0;
            int hashIndex = hashingType(type);

            Node* temp = arr[hashIndex].head;

            while (temp != NULL)
            {
                if (type == temp->type)
                    count++;
                temp = temp->next;
            }
            return count;
        }  
};



int solution(vector<vector<string>> clothes) {
    // 종류를 저장할 vector
    vector<string> types;

    // 종류 기준으로 hash table에 저장 -> class Hash가 필요
    Hash hash(clothes.size()); // 생성자 Hash(int N) {}한테 인수 전달
    
    for (int i=0; i<clothes.size(); i++)
    {
        hash.insert(clothes[i][0], clothes[i][1]);
        types.push_back(clothes[i][1]);
    }

    // unique 사용하기 위해 정렬
    sort(types.begin(), types.end());
    // unique로 종류 vector에서 중복 제거
    types.erase(unique(types.begin(), types.end()), types.end());

    int answer = 1;
    for (int i=0; i<types.size(); i++)
    {
        // 종류별로 하나를 택하거나 or 안하거나
        answer *= hash.find(types[i]) +1;
    }
    
    return answer - 1; // 아무것도 안 입는 경우 제외
}


// feedback - 2 (SYS)
// map으로 계산

#include <string>
#include <vector>
#include <map>

#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> cm;
    int size = clothes.size();

    for(int i{0}; i<size; i++)
    {
        cm[clothes[i][1]]++;
    }

    int answer = 1;
    map<string, int>::iterator iter;

    for(iter = cm.begin(); iter != cm.end(); iter++)
    {
        answer *= (iter->second) +1;
    }

    return --answer;
}


// feedback - 3 (KYJ)
// map으로 계산

#include <string>
#include <vector>
#include <map>

#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;

    for (int i=0; i<clothes.size(); i++)
    {
        if (m.find(clothes[i][1]) != m.end())
            m.find(clothes[i][1])->second++;
        else
            m.insert({clothes[i][1], 1});
    }

    for (int i=0; i<clothes.size(); i++)
    {
        int ans = 0;
        if (m.find(clothes[i][1])->second != 0)
        {
            ans = m.find(clothes[i][1])->second+1;
            m.find(clothes[i][1])->second = 0;
            answer *= ans;
        }
    }

    return answer-1;
}


// feedback - 4 (HSJ)
// 2차원 vector 잘 보이도록 map(string 종류, int 해당 종류 갯수)
// vector의 size만큼 for문 돌면서
// key에 의상 종류 없으면 추가, 있으면 value+1
// map 정리 후에 경우의 수 계산해주자

#include <string>
#include <vector>
#include <map>

#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> type;

    // map으로 정리하기
    for (int i=0; i<clothes.size(); i++)
    {
        if (type.count(clothes[i][1]) == 1)
            type[clothes[i][1]]++;
        else
            type[clothes[i][1]] = 1;
    }

    // 경우의 수 계산
    for (auto iter = type.begin(); iter != type.end(); ++iter)
    {
        // 착용하지 않을 때 추가
        answer *= ((iter->second)+1); 
    }

    // 아무것도 착용하지 않을 때 삭제
    answer--;

    return answer;
}