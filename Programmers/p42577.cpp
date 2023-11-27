#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string,bool> um;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for(auto pb:phone_book) {
        int length = pb.size();
        for(int i=1; i<=length; i++) {
            string sub = pb.substr(0,i);
            if(um[sub]) {
                return false;
            }
        }
        um[pb] = true;
    }
    return true;
}
