#include<iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int x,y,w,h;
    cin>>x>>y>>w>>h;
    int answer = 2e9;
    answer = min(answer,x);
    answer = min(answer,y);
    answer = min(answer, w-x);
    answer = min(answer,h-y);
    cout<<answer;
}
