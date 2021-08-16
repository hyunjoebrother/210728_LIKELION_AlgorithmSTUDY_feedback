// 문제 2. 가장 큰 수 - 정렬

// feedback - 1 (KYJ)
// _string의 아스키 코드도 숫자가 더 큰 애들이 해당 코드 숫자가 큼

#include <string>
#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;

bool cmp(string a, string b)
{
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;

    for(int i=0; i<numbers.size(); i++)
    {
        v.push_back(to_string(numbers[i]));
    }
    sort(v.begin(), v.end(), cmp);

    for(int i=0; i<v.size(); i++)
    {
        answer+=v[i];
    }
    
    if(answer[0]=='0')
        return "0";
    
    return answer;
}