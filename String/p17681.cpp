#include <string>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string converter(int num,int n) {
    string convert;
    while(num!=0) {
        convert += to_string(num%2);
        num/=2;
    }
    while(convert.length()<n) {
        convert+="0";
    }
    reverse(convert.begin(), convert.end());
    return convert;
}

string makeMap(string str1, string str2, int n) {
    string map;
    for(int i=0; i<n; i++) {
        if(str1[i] == '0' && str2[i] == '0') map+=" ";
        else map+="#";
    }
    return map;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string a,b;
    
    for(int i=0; i<n; i++) {
        a=converter(arr1[i],n);
        b=converter(arr2[i],n);
        answer.push_back(makeMap(a,b,n));
    }
    
    return answer;
}
