#include <iostream>
#include <string>
#include <vector>
using namespace std;

char vowel[5] = {'A','E','I','O','U'};
bool flag;
int answer;
string word;
int idx = 1;

void run(string str,int index) {
    if(flag) {
        return;
    }
    if(str==word) {
        flag = true;
        answer = index;
        return;
    }
    if(str.length()==5) {
        return;
    }
    for(int i=0; i<5; i++) {
        string newstr = str + vowel[i];
        run(newstr,idx++);
    }
}

int solution(string wo) {
    word = wo;
    run("",0);
    return answer;
}
