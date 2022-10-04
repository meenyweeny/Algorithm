#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(vector<int> a, vector<int> b) {
    return a.size() <= b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    
    vector<vector<int>> v;
    vector<int> tmp;
    string tmpstring = "";
    
    for(int i=1; i<s.length()-1; i++) {
        if(s[i] == '{') continue;
        else if(s[i] == '}') {
            tmp.push_back(stoi(tmpstring));
            tmpstring = "";
            v.push_back(tmp);
            tmp.clear();
            ++i;
        }
        else if(s[i] == ',') {
            tmp.push_back(stoi(tmpstring));
            tmpstring = "";
        }
        else {
            tmpstring += s[i];
        }
    }
    
    sort(v.begin(), v.end(), comp);
    
    for(auto sub:v) {
        for(int i=0; i<sub.size(); i++) {
            if(find(answer.begin(), answer.end(), sub[i]) == answer.end()) {
                answer.push_back(sub[i]);
                break;
            }
        }
    }
    
    return answer;
}
