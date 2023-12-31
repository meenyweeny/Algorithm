#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> arr;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    arr.resize(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    int mingap = 2e9 + 1;
    pair<int,int> answer = {0,n-1};
    for(int i=0; i<n; i++) {
        int now = arr[i];
        int left = 0;
        int right = n-1;
        pair<int,int> tmp = {i,0};
        int gap = 2e9 + 1;
        while(left<=right) {
            int mid = (left+right)/2;
            int sum = now + arr[mid];
            if(sum < 0) {
                left = mid + 1;
                if(mid==i) {
                    continue;
                }
                if(gap>abs(sum)) {
                    gap = abs(sum);
                    tmp = {i,mid};
                }
            } else if(sum > 0) {
                right = mid - 1;
                if(mid==i) {
                    continue;
                }
                if(gap>abs(sum)) {
                    gap = abs(sum);
                    tmp = {i,mid};
                }
            } else {
                if(mid==i) {
                    continue;
                }
                gap = abs(sum);
                tmp = {i,mid};
                break;
            }
        }
        if(mingap>gap) {
            mingap = gap;
            answer = tmp;
        }
    }
    if(arr[answer.first]>arr[answer.second]) {
        swap(answer.first, answer.second);
    }
    cout<<arr[answer.first]<<' '<<arr[answer.second];
}
