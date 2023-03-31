#include<iostream>
using namespace std;

int arr[26];

void solve() {
    string cmd;
    cin>>cmd;

    for(auto k:cmd) {
        ++arr[k-65];
    }

    int tmp = 0;
    for(int i=0; i<26; i++) {
        if(arr[i]%2!=0) {
            ++tmp;
        }
    }
    if(tmp>1) {
        cout<<"I'm Sorry Hansoo";
        return;
    }
    char mid;
    for(int i=0; i<26; i++) {
        if(arr[i]%2!=0) {
            mid = i+65;
            --arr[i];
        }
    }
    string answer = "";
    for(int i=0; i<26; i++) {
        for(int j=0; j<(arr[i]/2); j++) {
            answer += i+65;
        }
    }
    string anstmp = answer;
    reverse(anstmp.begin(), anstmp.end());
    if(tmp!=0) {
        answer += mid;
    }
    answer += anstmp;
    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
