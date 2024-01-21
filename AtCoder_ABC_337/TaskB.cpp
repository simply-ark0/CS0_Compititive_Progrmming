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
	string s;
	cin>>s;
	int charPrev = s[0], n=s.size();
	bool flag = true;

	if(s.empty()){
		cout<<"Yes";
		return EXIT_SUCCESS;
	}

	for(int i=1; i<n; i++){
		char ch = s[i];
		if(ch==charPrev || ch==charPrev+1 || ch==charPrev+2)
			charPrev = ch;
		else{
			flag = false;
			break;
		}
	}

	if(flag)
		cout<<"Yes";
	else
		cout<<"No";

	#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout<<"\n\n Executed in: "<<double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
	#endif

	return EXIT_SUCCESS;
} 