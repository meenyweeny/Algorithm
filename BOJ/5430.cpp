//
// Created by 이경민 on 2022/08/30.
//
#include<iostream>
#include<deque>
#include<string>
using namespace std;

deque<int> dq;
int t,n,idx;
string p,arr_info,number;
bool err, reversed;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>t;
    while(t--){
        cin>>p;
        cin>>n;
        cin>>arr_info;
        idx = 1;
        while(n--){
            number = "";
            while(1){
                if(arr_info[idx]==','){
                    dq.push_back(stoi(number));
                    ++idx;
                    break;
                }
                else if(arr_info[idx]==']'){
                    dq.push_back(stoi(number));
                    ++idx;
                    break;
                }
                else { number += arr_info[idx]; }
                ++idx;
            }
        }

        for(auto i:p){
            if(i=='R') reversed = !reversed;
            else {
                if(dq.empty()){ err = true; break; }
                if(reversed){
                    dq.pop_back();
                }
                else {
                    dq.pop_front();
                }
            }
        }


        if(err) cout<<"error\n";
        else {
            cout<<"[";
            if(reversed){
                for(int i=dq.size()-1; i>=0; i--){
                    cout<<dq[i];
                    if(i!=0) cout<<",";
                }
            }
            else {
                for(int i=0; i<dq.size(); i++){
                    cout<<dq[i];
                    if(i!=dq.size()-1) cout<<",";
                }
            }
            cout<<"]\n";
        }

        err = reversed = false;
        dq.clear();
    }
}
