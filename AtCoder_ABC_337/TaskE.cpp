#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

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
	int n;
	cin>>n;
	int m = 0;
	while((1LL<<m)<n)
		++m;

	cout<<m<<endl;

	for(int f=0; f<m; f++){
		cout<<n/(1<<f+1)*(1<<f) + max(0, n%(1<<f+1)-(1<<f))<<" ";
		for(int b=1<<f; b<n; b+=1<<f){
			int t = 1<<f;
			while(t-- && b<n)
				cout<<1+b++<<" ";
		}
		cout<<endl;
	}

	// for(int f=0; f<m; f++){
	// 	vi vec;
	// 	for(int b=0; b<n; b++)
	// 		if(b&(1<<f))
	// 			vec.push_back(b);
	// 	cout<<vec.size()<<" ";
	// 	for(auto it:vec)
	// 		cout<<it+1<<" ";
	// 	cout<<endl;
	// }

	string s;
	cin>>s;
	int ans = 0;

	for(int i=0; i<m; i++)
		if(s[i]=='1')
			ans += 1<<i;

	cout<<ans+1<<endl;

	#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout<<"\n\n Executed in: "<<double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
	#endif

	return EXIT_SUCCESS;
} 