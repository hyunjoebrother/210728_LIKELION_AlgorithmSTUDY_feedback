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


// feedback - 2 (LJH)
// 