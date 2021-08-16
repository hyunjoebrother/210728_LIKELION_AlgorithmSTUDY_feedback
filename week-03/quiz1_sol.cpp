//// 210816 멋사 코테 스터디 3주차 - 정렬 & Heap
// 문제 1. K번째수 - 정렬

// feedback - 1 (PSJ)
// 주어진 array vector에서 i~j번째 수를 잘라서 임시 vector에 저장
// 그 vector을 정렬하여 K 번째에 있는 수를 구함

#include <string>
#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    int size = commands.size();

    for (int i=0; i<size; i++)
    {
        // 잘라서 정렬할 임시 vector
        vector<int> sol;
        // i~j번째 숫자 잘라서 넣기
        for(int j=commands[i][0]-1; j<commands[i][1]; j++)
            sol.push_back(array[j]);
        
        sort(sol.begin(), sol.end());

        // K 번째 수
        answer.push_back(sol[commands[i][2]]-1);
    }
    
    return answer;
}