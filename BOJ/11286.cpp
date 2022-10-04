#include<iostream>
#include<queue>
using namespace std;

int n,x;
priority_queue<int, vector<int>, greater<int>> pos;
priority_queue<int, vector<int>, greater<int>> neg;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    while(n--){
        cin>>x;
        if(x==0){
            if(neg.empty() && pos.empty()) {
                cout<<"0\n";
                continue;
            }
            else if(neg.empty() && !pos.empty()) {
                cout<<pos.top()<<"\n";
                pos.pop();
                continue;
            }
            else if(pos.empty() && !neg.empty()){
                cout<<"-"<<neg.top()<<"\n";
                neg.pop();
                continue;
            }
            else {
                if(neg.top() < pos.top()) {
                    cout<<"-"<<neg.top()<<"\n";
                    neg.pop();
                }
                else if(neg.top() > pos.top()) {
                    cout<<pos.top()<<"\n";
                    pos.pop();
                }
                else {
                    cout<<"-"<<neg.top()<<"\n";
                    neg.pop();
                }
            }
        }
        else if(x<0) neg.push(x*-1);
        else pos.push(x);
    }
}