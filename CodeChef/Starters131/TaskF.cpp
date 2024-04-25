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
		int n;
		cin>>n;

		if(n%3==0){
			for(int i=n-2; i>=1; i--)
				cout<<i<<" ";
			cout<<n<<" "<<n-1<<endl;
		}else if(n%3==1){
			for(int i=n; i>=1; i--)
				cout<<i<<" ";
			cout<<endl;
		}else{
			for(int i=n-1; i>=1; i--)
				cout<<i<<" ";
			cout<<n<<endl;
		}
	}

	#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout<<"\n\n Executed in: "<<double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
	#endif

	return EXIT_SUCCESS;
} 