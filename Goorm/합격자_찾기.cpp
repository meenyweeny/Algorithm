#include <iostream>
using namespace std;

int t,n,count;
double sum;
int arr[1001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin>>t;
	while(t--) {
		cin>>n;
		sum=0;
		count=0;
		for(int i=0; i<n; i++) {
			cin>>arr[i];
			sum+=arr[i];
		}
		sum /= n;
		for(int i=0; i<n; i++) {
			if(arr[i]>=sum) {
				++count;
			}
		}
		cout<<count<<"/"<<n<<"\n";
	}
}
