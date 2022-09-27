#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, double> a, pair<int, double> b) {
    if (a.second >= b.second) {
        if (a.second == b.second) {
            return a.first < b.first;
        } else {
            return true;
        }
    } else {
        return false;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    sort(stages.begin(), stages.end());
    reverse(stages.begin(), stages.end());

    int now_stage = 0;
    int now_size = 0;
    int popped = 0;

    vector<pair<int, double>> num;

    while (!stages.empty()) {
        ++now_stage;

        popped = 0;
        now_size = stages.size();

        if (now_stage == N + 1) {
            break;
        }

        for (int i = now_size - 1; i >= 0; i--) {
            if (now_stage != stages[i]) {
                break;
            }
            ++popped;
            stages.pop_back();
        }

        if (popped == 0) {
            num.push_back({now_stage, 0});
        } else {
            num.push_back({now_stage, (double) ((double) popped / (double) (now_size))});
        }
    }

    if (stages.empty() && num.size() != N) {
        while (num.size() != N) {
            ++now_stage;
            num.push_back({now_stage, 0});
        }
    }

    sort(num.begin(), num.end(), comp);

    for (auto i: num) {
        answer.push_back(i.first);
    }

    return answer;
}
