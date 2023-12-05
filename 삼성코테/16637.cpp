#include<iostream>
#include<vector>
using namespace std;

int n;
long long answer = -2e10;
string cal;
vector<char> vv;

long long getvv() {
    long long before = -2e11;
    char oper;
    for(auto v:vv) {
        if(v>='0' && v<='9') {
            if(before<=-2e11) {
                before = v - '0';
            } else {
                if(oper=='*') {
                    before *= (v - '0');
                } else if(oper=='-') {
                    before -= (v - '0');
                } else if(oper=='+') {
                    before += (v - '0');
                }
            }
        } else {
            oper = v;
        }
    }
    return before;
}

long long calc(string str) {
    vector<int> v;
    long long before;
    char oper = 'c';
    for(int i=0; i<str.length(); i++) {
        if(str[i]=='(') {
            ++i;
            vv.clear();
            while(1) {
                if(str[i]==')') {
                    break;
                }
                vv.push_back(str[i]);
                ++i;
            }
            //vv에 있는거랑 before 계산해서 수로 만들기
            if(oper=='*') {
                before *= getvv();
            } else if(oper=='+') {
                before += getvv();
            } else if(oper=='-') {
                before -= getvv();
            } else {
                before = getvv();
            }
        } else if(str[i] >= '0' && str[i] <= '9') {
            if(oper=='*') {
                before *= (str[i] - '0');
            } else if(oper=='+') {
                before += (str[i] - '0');
            } else if(oper=='-') {
                before -= (str[i] - '0');
            } else {
                before = str[i] - '0';
            }
        } else { //oper
            oper = str[i];
        }
    }
    return before;
}

void run(string now, int index, bool opened) {
    if(index == cal.length()) {
        if(opened) {
            now += ')';
        }
        answer = max(answer, calc(now));
        return;
    }
    if(index%2) {
        run(now+cal[index],index+1,opened);
    } else {
        if(opened) {
            run(now+cal[index]+')',index+1,!opened);
        } else {
            run(now+'('+cal[index],index+1,!opened);
            run(now+cal[index],index+1,opened);
        }
    }
}

void solve() {
    cin>>n;
    cin>>cal;
    run("",0,false);
    cout<<answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
