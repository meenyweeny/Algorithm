#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    vector<int> v;
    for(auto cmd:commands) {
        int front = cmd[0] - 1;
        int back = cmd[1] - 1;
        int target = cmd[2] - 1;
        for(int i=front; i<=back; i++) {
            v.push_back(array[i]);
        }
        sort(v.begin(),v.end());
        answer.push_back(v[target]);
        v.clear();
    }
    
    return answer;
}
