#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

unordered_map<string, string> users;

string enter_alarm(string nickname) {
    return nickname+"님이 들어왔습니다.";
}

string leave_alarm(string nickname) {
    return nickname+"님이 나갔습니다.";
}

vector<string> get_userinformation(string command) {
    istringstream ss(command);
    string buffer;
    vector<string> v;
    while(getline(ss, buffer, ' ')) {
        v.push_back(buffer);
    }
    return v;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> info;
    for(auto i:record) {
        info = get_userinformation(i);
        if(i[0]=='E') {
            if(users.find(info[1])!=users.end()) {
                users.erase(info[1]);
            }
            users.insert({info[1],info[2]});
        }
        else if(i[0]=='C') {
            users.erase(info[1]);
            users.insert({info[1],info[2]});
        }
    }
    
    for(auto i:record) {
        info = get_userinformation(i);
        if(i[0]=='E') {
            answer.push_back(enter_alarm(users[info[1]]));
        }
        else if(i[0]=='L') {
            answer.push_back(leave_alarm(users[info[1]]));
        }
    }
    
    return answer;
}
