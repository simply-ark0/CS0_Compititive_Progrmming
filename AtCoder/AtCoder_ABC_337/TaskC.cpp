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

class node{
	public:
		int val;
		node *next;
		node(int val){
			this->val = val;
			this->next = NULL;
		}

};

int main(int argc, char const *argv[]){
	clock_t begin = clock();
	file_i_o();

	// write your code here...
	int n;
	cin>>n;
	unordered_map<int, node*> mp;

	for(int back=1; back<=n; back++){
		int front;
		cin>>front;

		if(mp.count(front) && mp.count(back)){
			mp[front]->next = mp[back];
		}
		else if(mp.count(front)){
			mp[back] = new node(back);
			mp[front]->next = mp[back];
		}
		else if(mp.count(back)){
			mp[front] = new node(front);
			mp[front]->next = mp[back];
		}
		else{
			mp[front] = new node(front);
			mp[back] = new node(back);
			mp[front]->next = mp[back];
		}

	}

	auto start = mp[-1]->next;

	while(start){
		// cout<<"Hamba"<<" ";
		cout<<start->val<<" ";
		start = mp[start->val]->next;
	}

	#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout<<"\n\n Executed in: "<<double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
	#endif

	return EXIT_SUCCESS;
} 