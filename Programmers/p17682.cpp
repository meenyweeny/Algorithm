#include <string>
#include <vector>
using namespace std;

bool isNumber(char ch) {
    return (ch-48)>=0 && (ch-48)<10;
}

int solution(string dartResult) {
    int answer = 0;
    vector<int> v;
    char c;
    int score = 0;
    
    for(int i=0; i<dartResult.length(); i++) {
        c = dartResult[i];
        if(isNumber(c)) {
            score = (score * 10) + (c-48);
            continue;
        }
        if(c == 'S') {
            v.push_back(score);
            score = 0;
        }
        else if(c == 'D') {
            v.push_back(score*score);
            score = 0;
        }
        else if(c == 'T') {
            v.push_back(score*score*score);
            score = 0;
        }
        else if(c == '*') {
            if(v.size() == 1) {
                int tmp = v[v.size()-1];
                v.pop_back();
                tmp *= 2;
                v.push_back(tmp);
            }
            else {
                int tmp1 = v[v.size()-1];
                v.pop_back();
                tmp1 *= 2;
                int tmp2 = v[v.size()-1];
                v.pop_back();
                tmp2 *= 2;
                v.push_back(tmp2);
                v.push_back(tmp1);
            }
        }
        else if(c== '#') {
            int tmp = v[v.size()-1];
            v.pop_back();
            tmp *= -1;
            v.push_back(tmp);
        }
    }
    
    for(auto i:v) answer+=i;
    return answer;
}
