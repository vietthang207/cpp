#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int main(){
    int T;
    cin>>T;
    for (int t=0; t<T; t++){
        int n;
        cin>>n;
        int a[n];
        for (int i=0; i<n; i++) cin>>a[i];
        if (n==1) {
			cout<<1<<endl;
			continue;
		}
		int res = 2;
        int sum = a[0];
        int curr = a[n];
        for (int i=1; i<n-1; i++){
            if (a[i]+sum<a[i+1]){
                res++;
                sum+=a[i];
            }
        }
        cout<<res<<endl;
    }
}
