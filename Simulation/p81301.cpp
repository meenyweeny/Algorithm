#include <string>
#include <vector>
#include <string>
using namespace std;

bool isNotNumber(char ch) {
    return ch=='z' || ch=='o' || ch=='t' || ch == 'f' || ch == 's' || ch == 'e' || ch == 'n';
}

int solution(string s) {
    string ans = "";
    int answer = 0;
    int len = s.length();
    char ch;
    for(int i=0; i<len; i++) {
        ch = s[i];
        if(isNotNumber(ch)) {
            if(ch=='z') {
                i+=3;
                ans+="0";
            }
            else if(ch == 'n') {
                i+=3;
                ans += "9";
            }
            else if(ch=='o') {
                i+=2;
                ans+="1";
            }
            else if(ch=='t') {
                if(s[i+1]=='w') {
                    i+=2;
                    ans+="2";
                }
                else {
                    i+=4;
                    ans+="3";
                }
            }
            else if(ch == 'f') {
                if(s[i+1]=='o'){
                    ans+="4";
                }
                else ans+="5";
               i+=3;
            }
            else if(ch == 's') {
                if(s[i+1]=='i'){
                    i+=2;
                    ans+="6";
                }
                else {
                    i+=4;
                    ans+="7";
                }
            }
            else if(ch == 'e') {
                ans+="8";
                i+=4;
            }
        }
        else {
            ans += ch;
        }
    }
    answer = stoi(ans);
    return answer;
}
