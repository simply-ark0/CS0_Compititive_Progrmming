#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lli long long int
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vs vector<string>
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define vvll vector<vector<long long>>
#define pb(a) push_back(a)
#define umpi unordered_map<int, int>
#define usi unordered_set<int>
#define cbug(a) cerr<<a<<endl;
#define dbug(a) cout<<a<<endl;

template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }

void file_i_o(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

int main(int argc, char const *argv[]){
	clock_t begin = clock();
	file_i_o();

	// write your code here...
	int t;
	cin>>t;

	while(t--){
		ll n, m;
		cin>>n>>m;

		priority_queue<ll, vector<ll>, greater<ll>> pq1, pq2;
		priority_queue<ll, vector<ll>> pq3;

		for(int i=0; i<n; i++){
			ll t;
			cin>>t;
			if(pq1.size()<4)
				pq1.push(t);
			else{
				if(t>pq1.top()){
					pq3.push(pq1.top());
					pq1.pop();
					pq1.push(t);
				}else
					pq3.push(t);
			}
		}

		for(int i=0; i<m; i++){
			ll t;
			cin>>t;
			if(pq2.size()<4)
				pq2.push(t);
			else{
				if(t>pq2.top()){
					pq3.push(pq2.top());
					pq2.pop();
					pq2.push(t);
				}else
					pq3.push(t);
			}
		}

		if(n<4 || m<4 || n+m<11){
			cout<<(-1)<<endl;
			continue;
		}

		ll ans = 0;

		for(int i=0; i<4; i++){
			ans += pq1.top() + pq2.top();
			pq1.pop();
			pq2.pop();
		}

		int k=3;
		while(k--){
			ans += pq3.top();
			pq3.pop();
		}

		cout<<ans<<endl;
	}

	#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout<<"\n\n Executed in: "<<double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
	#endif

	return EXIT_SUCCESS;
} 