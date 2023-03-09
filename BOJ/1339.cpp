#include<iostream>
#include<vector>
using namespace std;

int n;
pair<int,int> arr[26];
vector<string> v;
int weight[26];

void input() {
    cin>>n;
    string s;
    for(int i=0; i<n; i++) {
        cin>>s;
        v.push_back(s);
    }
}

void solution() {
    pair<int,int> tmp = {-1,0};
    fill(arr,arr+26,tmp);
    for(int i=0; i<26; i++) {
        arr[i].second = i;
    }
    for(auto s:v) {
        int length = s.length();
        int k = 1;
        for(int i=length-1; i>=0; i--) {
            arr[s[i]-65].first += k;
            k *= 10;
        }
    }
    sort(arr,arr+26);
    reverse(arr,arr+26);
    int num = 9;
    for(int i=0; i<26; i++) {
        if(arr[i].first==-1) {
            break;
        }
        weight[arr[i].second] = num;
        --num;
    }
    int answer = 0;
    for(auto s:v) {
        int length = s.length();
        int k = 1;
        for(int i=length-1; i>=0; i--) {
            answer += (weight[s[i]-65] * k);
            k*=10;
        }
    }
    cout<<answer;
}

void solve() {
    input();
    solution();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
