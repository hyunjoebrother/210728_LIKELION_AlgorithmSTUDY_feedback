// 문제 2. 기능개발

// feedback - 1 (PSJ)
// 먼저 배포 순으로 작업의 배열이 주어짐 -> Queue 사용
// progresses & speeds로부터 값을 읽어와서 일수 계산 후 Queue에 저장
// Queue에 값이 남아있는 동안, front로 맨 앞 기능 pop해서 배포
// 뒤 기능들의 일수가 front보다 작거나 같을 때 같이 배포되록 하여
// answer vector에 함께 배포되는 기능의 갯수를 넣어줌

#include <string>
#include <vector>
#include <queue>

#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    // 각 기능 개발 소요 일수 담는 queue
    queue<int> days;
    int size = progresses.size();

    for (int i=0; i<size; i++)
    {
        int day = (100-progresses[i])/speeds[i];
        if ((100-progresses[i]) % speeds[i] != 0)
            day++;
        days.push(day);
    }

    vector<int> answer;
    while (!days.empty())
    {
        int pop = 1, front = days.front();
        // 맨 앞 기능 배포
        days.pop();

        // 뒷 기능들의 소요 일수가 작거나 같을 때 함께 배포
        while (!days.empty() && front >= days.front())
        {
            days.pop();
            pop++;
        }
        answer.push_back(pop);
    }
    return answer;
}


// feedback - 2 (LJH, SYS, KYJ)
// map으로 key : 배포날짜, value : 배포할 기능 갯수
// 앞선 기능이 시간 더 오래 걸렸따면 같이 배포

#include <string>
#include <vector>
#include <map>

#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    map<int, int> Map;
    // 갓영빈좌 조언 - for문 사용 시 size 미리 선언하면 시간 단축!
    int proSize = progresses.size();
    int pre_day = 0;
    int cur_day;

    for (int i=0; i<proSize; i++)
    {
        cur_day = 0;
        // 해당 기능이 100% 될 때까지 배포날짜를 더해준다
        while (progresses[i]<100)
        {
            progresses[i] += speeds[i];
            cur_day++;
        }

        // 앞선 기능이 현재보다 시갇간 더 오래 걸리면 같이 배포하여 +1
        if (pre_day >= cur_day)
            Map[pre_day]++;
        
        // 현재 기능 개발이 더 오래 걸리면 새로운 key값을 통해 map에 넣음
        else
            Map[cur_day]++;
            pre_day = cur_day;
    }


    for (auto key : Map)
        answer.push_back(key.second);


    return answer;
}