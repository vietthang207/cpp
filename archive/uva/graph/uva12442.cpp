#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef map<int, int> mii;

const double EP=1e-6;
const ll MAX31 = 2147483647;
const ll MIN31 = -2147483648;

int T, n;
vi al[55000];
int memo[55000];
bool visited[55000];
stack<int> st;
bool onStack[55000];

int dfs(int v){
	// cout<<v<<endl;
	if (visited[v]) return memo[v];
	visited[v] = true;
	int size = al[v].size();
	if (size==0) return memo[v] = 1;
	int next = al[v][0];
	if (!visited[next]) {
		st.push(next);
		onStack[next] = true;
		memo[v] = dfs(al[v][0]);
		st.pop(next);
	}
	return memo[v] = 1 + memo[al[v][0]];
}

int main(){
	cin>>T;
	for (int t=0; t<T; t++){
		for (int i=0; i<55000; i++) al[i].clear();
		memset(memo, -1, sizeof memo);
		memset(visited, false, sizeof visited);
		cin>>n;
		for (int i=0; i<n; i++){
			int v1,v2;
			cin>>v1>>v2;
			v1--; v2--;
			al[v1].push_back(v2);
		}

		int res, maxi=MIN31;
		for (int i=0; i<n; i++){
			if (memo[i]==-1) dfs(i);
			cout<<memo[i]<<endl;
			if (memo[i]>maxi){
				maxi = memo[i];
				res = i;
			}
		}
		printf("Case %d: %d\n", t+1, res+1);

	}
}