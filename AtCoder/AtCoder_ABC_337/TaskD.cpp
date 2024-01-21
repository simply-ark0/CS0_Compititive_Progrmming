#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lli long long int
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
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

	int n,m,k;
	cin>>n>>m>>k;
	int ans = k;
	bool possible = false;
	vector<vector<char>> grid(n, vector<char>(m));

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>grid[i][j];

	// x -> black stone, o -> white stone
	// row major:
	if(k<=m){
		for(int r=0; r<n; r++){
			int i=0, j=0, b=0, w=0;
			while(j<m){
				b += grid[r][j]=='x';
				w += grid[r][j]=='o';
				if(j-i+1<k){
					++j;
					continue;
				}
				if(b==0){
					possible = true;
					ans = min(ans, k-w);
				}
				b -= grid[r][i]=='x';
				w -= grid[r][i]=='o';
				++i; ++j;
			}
		}
	}

	if(k<=n){
		for(int c=0; c<m; c++){
			int i=0, j=0, b=0, w=0;
			while(j<n){
				b += grid[j][c]=='x';
				w += grid[j][c]=='o';
				if(j-i+1<k){
					++j;
					continue;
				}
				if(b==0){
					possible = true;
					ans = min(ans, k-w);
				}
				b -= grid[i][c]=='x';
				w -= grid[i][c]=='o';
				++i; ++j;
			}
		}
	}

	if(possible)
		cout<<ans;
	else
		cout<<-1;

	#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout<<"\n\n Executed in: "<<double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
	#endif

	return EXIT_SUCCESS;
} 