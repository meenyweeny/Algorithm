#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string answer, temp;

void converter(int n, int num, int m, int p) {
    int mod;
    string tmp;
    
    while(num>0) {
        mod = num%n;
        num/=n;
        
        if(mod>=10) {
            mod-=10;
            tmp += (mod+'A');
        }
        else {
            tmp += to_string(mod);
        }
    }
    
    reverse(tmp.begin(),tmp.end());
    
    for(auto i:tmp) {
        temp+=i;
        if(temp.length()==m) {
            answer += temp[p-1];
            temp = "";
        }
    }
}

string solution(int n, int t, int m, int p) {
    
    int number = 1;
    temp = "0";
    
    while(1) {
        
        converter(n,number,m,p);
        if(answer.length()==t) {
            break;
        }
        else {
            ++number;
        }
    }
    
    return answer;
}
