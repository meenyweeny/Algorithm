//
// Created by 이경민 on 2022/06/16.
//
#include<iostream>
#include<iomanip>
using namespace std;

int c,n,counts;
double sum;
int students[1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>c;
    while(c--){
        cin>>n;
        for(int i=1; i<=n; i++) {
            cin>>students[i];
            sum += students[i];
        }
        (double) (sum /= (double) n);
        for(int i=1; i<=n; i++){
            if(students[i]>sum) ++counts;
        }
        cout<<fixed<<setprecision(3)<<((double)counts/(double)n)*100;
        cout<<"%\n";
        sum = counts = 0;
    }
}
