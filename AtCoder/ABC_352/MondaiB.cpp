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

int main(){
	#ifndef ONLINE_JUDGE
		const auto bg = std::chrono::high_resolution_clock::now();
	#endif
	file_i_o();

	// write your code here...
	string s, t;
	cin>>s>>t;

	int i=0, j=0, ns=s.size();

	while(i<ns){
		if(s[i]==t[j])	cout<<(j+1)<<" ", ++j, ++i;
		else
			++j;
	}

	#ifndef ONLINE_JUDGE
		const auto ed = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = ed-bg;
    	cout<<"\n\nTime Taken : "<<diff.count()*1000<<" ms";
	#endif

	return EXIT_SUCCESS;
} 