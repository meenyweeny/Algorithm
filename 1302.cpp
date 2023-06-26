#include<iostream>
#include<map>
#include<vector>
using namespace std;

int n;
map<string,int> m;
vector<pair<string,int>> book;

bool comp(pair<string,int> a, pair<string,int> b) {
    if(a.second==b.second) {
        return a.first < b.first;
    } else {
        return a.second > b.second;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    string s;
    while(n--) {
        cin>>s;
        if(m.insert({s, 1}).second) {

        } else {
            ++m.find(s)->second;
        }
    }

    for(auto b:m) {
        book.push_back({b.first,b.second});
    }

    sort(book.begin(), book.end(), comp);

    cout<<book[0].first;
}
