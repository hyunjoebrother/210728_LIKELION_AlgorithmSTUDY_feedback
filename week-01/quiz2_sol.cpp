// 문제 2. 전화번호 목록

// feedback - 1 (PSJ, SYS)
// hash는 아니고 string형의 phone_book 정렬하여
// 바로 뒤 번호와 비교

#include <string> // substr 함수
#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    // 정렬 -> 바로 뒤에 겹치는 거 있는지만 확인하자
    sort(phone_book.begin(), phone_book.end());

    bool answer = true;

    for (int i=0; i<phone_book.size()-1; i++)
    {
        // 앞 번호 길이가 뒷 번호보다 길거나 같으면 중복 x
        // length 함수 : 인자로 주어진 문자열 길이 return
        if (phone_book[i].length() >= phone_book[i+1].length())
            continue;

        // substr 함수 : 특정 일부 문자열 return
        if (phone_book[i] == phone_book[i+1].substr(0, phone_book[i].length()))
            answer = false; // 접두어
            break;
    }

    return answer;
}


// feedback - 2 (LJH)
// vector의 값을 이중 for문으로 모두 순회하니 시간초과 뜸
// 시간을 줄이기 위해서 해당 index의 문자열 크기만큼만 for문 돌리고
// bool 형식인 map의 value 값을 통해 존재여부 파악

#include <string>
#include <vector>
#include <unordered_map>

#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    string prefix_number = "";
    unordered_map<string, bool> mapForPhoneBook;

    for (int i=0; i<phone_book.size(); i++)
        // make_pair 함수 : vector에 k-v 형태로 data 저장
        mapForPhoneBook.insert(make_pair(phone_book[i], true));

    for (int i=0; i<phone_book.size(); i++)
    {
        for (int j=0; j<phone_book[i].size(); j++)
        {
            // key 크기만큼 반복하여 접두어를 하나씩 찾음
            prefix_number = phone_book[i].substr(0,j);

            // phone_number[i]와 다르면서 map에 존재하면 return
            if (mapForPhoneBook[prefix_number] && prefix_number != phone_book[i])
                return false;
        }
    }

    return answer;
}
