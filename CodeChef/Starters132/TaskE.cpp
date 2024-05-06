#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lli long long int
#define all(x) begin(x), end(x)
#define sz(x) ((lli)(x).size())
#define v(type) vector<type>
#define vv(type) vector<vector<type>>
#define pi pair<int, int>
#define nl "\n"
#define pb(a) push_back(a)
#define ump(type1, type2) unordered_map<type1, type2>
#define us(type) unordered_set<type>

#define Err(x...) {cout<<"["<<#x<<"]:"<<" ["; printIt(x);}
template <typename T1>
void printIt(T1 t1...) {cout<<t1<<"]"<<endl;}
template <typename T1, typename... T2>
void printIt(T1 t1, T2... t2) {cout<<t1<<", "; printIt(t2...);}

template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }

template <class T>
void print_vv(vector<vector<T>> &v) {
	for (auto x : v){
		for(auto it:x)
			printf("%-4d", it);
		cout<<nl;
	}
}

void file_i_o(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

#define getBlk(n) ((n*(n+1))>>1)

int main(){
	#ifndef ONLINE_JUDGE
		const auto bg = std::chrono::high_resolution_clock::now();
	#endif
	file_i_o();

	// write your code here...
	lli t;
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;

		v(ll) arr(n);
		for(auto &it:arr)
			cin>>it;

		int cnt = 0;
		v(ll) b;
		for(auto it:arr)
			if(it&1)
				++cnt;
			else{
				if(cnt)	b.pb(cnt);
				cnt=0;
			}

		if(cnt)	b.pb(cnt);
		ll ans = getBlk(n);
		ll mx = 0;
		
		for(auto it:b){
			ans -= getBlk(it);
			mx = max(mx, it);
		}
		// Err(ans);

		// got the maximal blk!
		if(mx&1)
			ans += getBlk(mx) - (getBlk(mx/2))*2;
		else
			ans += getBlk(mx) - (getBlk(mx/2) + getBlk(mx/2-1));

		cout<<ans<<endl;


	}

	#ifndef ONLINE_JUDGE
		const auto ed = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = ed-bg;
    	cout<<"\n\nTime Taken : "<<diff.count()*1000<<" ms";
	#endif

	return EXIT_SUCCESS;
} 