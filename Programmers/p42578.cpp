#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string,int> type;
int types = 0;
int arr[31];
int answer = 0;

void make_pick(int goal,int count,int start,bool pick[31]) {
    if(count==goal) {
        int sum = 1;
        for(int i=1; i<=types; i++) {
            if(!pick[i]) {
                continue;
            }
            sum *= arr[i];
        }
        answer += sum;
        return;
    }
    for(int i=start; i<=types; i++) {
        pick[i] = true;
        make_pick(goal,count+1,i+1,pick);
        pick[i] = false;
    }
    return;
}

int solution(vector<vector<string>> clothes) {
    for(auto cl:clothes) {
        string cloth_name = cl.front();
        string cloth_type = cl.back();
        int idx = type[cloth_type];
        if(idx!=0) {
            ++arr[idx];
        } else {
            type[cloth_type] = ++types;
            ++arr[types];
        }
    }
    --answer;
    int sum = arr[1];
    ++sum;
    for(int i=2; i<=types; i++) {
        sum *= (arr[i]+1);
    }
    answer += sum;
    return answer;
}
