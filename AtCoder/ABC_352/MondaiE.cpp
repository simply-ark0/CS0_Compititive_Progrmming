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

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

int main(){
    #ifndef ONLINE_JUDGE
        const auto bg = std::chrono::high_resolution_clock::now();
    #endif
    file_i_o();

    // write your code here...
    int n, m;
    cin>>n>>m;

    priority_queue<tuple<ll, v(ll)>, vector<tuple<ll, v(ll)>>, greater<tuple<ll, v(ll)>>> pq;
    for(int i=0; i<m; i++){
        ll k, c;
        cin>>k>>c;
        v(ll) ed(k);
        for(auto &it:ed)
            cin>>it;
        pq.push({c, ed});
    }
    
    dsu d(n+1);

    ll ans = 0;
    while(!pq.empty()){
        auto [edw, ed] = pq.top();
        pq.pop();
        int n = ed.size();
        for(int i=1; i<n; i++)
            if(!d.same(ed[0], ed[i])){
                d.merge(ed[0], ed[i]);
                ans += edw;
            }
    }

    if(d.size(1)!=n)
        cout<<"-1";
    else
        cout<<ans;


    #ifndef ONLINE_JUDGE
        const auto ed = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = ed-bg;
        cout<<"\n\nTime Taken : "<<diff.count()*1000<<" ms";
    #endif

    return EXIT_SUCCESS;
} 