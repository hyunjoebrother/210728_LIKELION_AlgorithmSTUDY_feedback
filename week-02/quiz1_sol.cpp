//// 210802 멋사 코테 스터디 2주차 - Stack & Queue
// 문제 1. 폰켓몬

// feedback - 1 (PSJ)
// 종류 번호 담긴 vector에서 unique()로 중복 제거
// 남은 vector의 size = 종류 번호 갯수

#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int N = nums.size();
    // unique를 위한 정렬
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    if (nums.size() > N/2)
        return N/2;
    else
        return nums.size();
}


// feedback - 2 (LJH, SYS)
// 객체 종류 상관없이 최대한 많이 고르는 거라서 중복은 신경 안 써도 됨
// set을 만들고 insert로 중복되는 것들을 하나의 객체로 통합
// 고르는 갯수보다 set 크기가 크면 고르는 갯수가 최댓값
// set 크기가 더 작으면 set의 크기를 최댓값으로 return

//// set STL
// * 시퀀스 container : vector, list, deque - 원소 자체를 보관
// * 연관 container : set, multiset, map, multimap - key-value 구조를 가짐

// - Node 기반 container, 균형 이진트리로 구현, 멤버 변수와 생성자 등이 거의 같음

// : set의 원소 : key -> 삽입되는 key들은 자동으로 오름차순 정렬된다
// : 원소들은 모두 유일하도록 저장됨 중복 x (중복저장은 multiset)
// : set은 key의 존재 유무만 궁금하면 쓰기! map은 memory 큼 ㅇㅇ


#include <vector>
#include <set> // 중복 포켓몬들은 신경 안 써도 될 거 같아서 ㅇㅇ
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> poketmon;

    int pick = nums.size()/2;
    int size = nums.size();

    // set에 insert하면서 중복 개체 제거
    for (int i=0; i<size; i++)
    {
        poketmon.insert(nums[i]);
    }

    // set의 크기 < 고르는 갯수 -> set의 크기 return
    if (poketmon.size() <= pick)
        answer = poketmon.size();
    else
        answer = pick;


    return answer;
}