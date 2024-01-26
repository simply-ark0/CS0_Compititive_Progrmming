#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lli long long int
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define pb(a) push_back(a)
#define vll vector<long long>
#define umpii map<int, int>
#define mpii map<int, int>
#define si set<int>

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
	int t,p,l;

	cin>>t;
	while(t--){
		cin>>p>>l;
		float lit = (l*1.0/p)*100;
		if(lit>=75)
			cout<<"yes\n";
		else
			cout<<"no\n";
	}

	#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout<<"\n\n Executed in: "<<double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
	#endif

	return EXIT_SUCCESS;
} 