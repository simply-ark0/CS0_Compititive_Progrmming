## CP Template:
```c++
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lli long long int
#define all(x) begin(x), end(x)
#define sz(x) ((lli)(x).size())
#define pb(a) push_back(a)
#define nl "\n"
#define pi pair<int, int>

template<typename T1, typename T2>
using mpp = map<T1, T2>;
template<typename T>
using stt = set<T>;

template<typename T>
using v = vector<T>;
template<typename T>
using vv = vector<vector<T>>;

#define Err(x...) {cout<<"["<<#x<<"]:"<<" ["; printIt(x);}
template <typename T1>
void printIt(T1 t1...) {cout<<t1<<"]"<<endl;}
template <typename T1, typename... T2>
void printIt(T1 t1, T2... t2) {cout<<t1<<", "; printIt(t2...);}

template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "}\n"; }

template <class T>
void print_vv(vector<vector<T>> &v) {
	for (auto x : v){
		for(auto it:x)
			printf("%-4c", it);
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

int main(){
	#ifndef ONLINE_JUDGE
		const auto bg = std::chrono::high_resolution_clock::now();
	#endif
	file_i_o();

	// write your code here...
	lli t;
	cin>>t;
	
	while(t--){
		
	}

	#ifndef ONLINE_JUDGE
		const auto ed = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = ed-bg;
    	cout<<"\n\nTime Taken : "<<diff.count()*1000<<" ms";
	#endif

	return EXIT_SUCCESS;
} 
```

