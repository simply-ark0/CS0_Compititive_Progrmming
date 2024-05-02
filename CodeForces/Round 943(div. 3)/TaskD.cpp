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
		ll n, k, pb, ps;
		cin>>n>>k>>pb>>ps;

		vll p(n), a(n);

		for(int i=0; i<n; i++)
			cin>>p[i];

		for(int i=0; i<n; i++)
			cin>>a[i];

		// for bodya:
		ll bsc = 0, sc = 0;
		vll tp = p;
		for(int i=0; i<k; i++){
			if(tp[pb-1]==-1)	break;
			bsc = max(bsc, sc + a[pb-1]*(k-i));
			sc += a[pb-1];
			ll t = pb;
			pb = tp[pb-1];
			tp[t-1] = -1;
		}


		ll ssc = 0;
		sc = 0;
		for(int i=0; i<k; i++){
			if(p[ps-1]==-1)	break;
			ssc = max(ssc, sc + a[ps-1]*(k-i));
			sc += a[ps-1];
			ll t = ps;
			ps = p[ps-1];
			p[t-1] = -1;
		}

		// cout<<bsc<<endl<<ssc<<endl;

		if(bsc==ssc)
			cout<<"Draw\n";
		else if(bsc>ssc)
			cout<<"Bodya\n";
		else
			cout<<"Sasha\n";

	}

	#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout<<"\n\n Executed in: "<<double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
	#endif

	return EXIT_SUCCESS;
} 