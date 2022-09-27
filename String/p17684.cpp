#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> dict;

void init() {
    char c = 'A';
    char z;
    string str = "";
    for(int i=0; i<26; i++) {
        z=c+i;
        str = "";
        str += z;
        dict.push_back(str);
    }
}

vector<int> solution(string msg) {
    vector<int> answer;
    init();
    
    string target = "";
    vector<string>::iterator it;
    
    for(int i=0; i<msg.length(); i++) {
        target += msg[i];
        
        if(find(dict.begin(), dict.end(), target) == dict.end()) {
            answer.push_back(it-dict.begin() + 1);
            dict.push_back(target);
            target = "";
            --i;
        }
        else {
            it = find(dict.begin(), dict.end(), target);
            if(i==msg.length()-1) {
                answer.push_back(it-dict.begin() + 1);
            }
        }
    }
    
    
    return answer;
}
