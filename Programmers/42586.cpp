#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int index = 0;
    int days = 0;
    while(1) {
        if(index==progresses.size()) {
            break;
        }
        for(int i=index; i<progresses.size(); i++) {
            progresses[i] += speeds[i];
        }
        ++days;
        int count = 0;
        int idx = index;
        while(1) {
            if(idx==progresses.size()) {
                break;
            }
            if(progresses[idx]>=100) {
                ++idx;
                ++count;
            } else {
                break;
            }
        }
        index = idx;
        if(count) {
            answer.push_back(count);
        }
    }
    
    return answer;
}
