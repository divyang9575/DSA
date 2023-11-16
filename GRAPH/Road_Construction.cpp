#include<bits/stdc++.h>
using namespace std;


#ifndef ONLINE_JUDGE
#define db(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define db(x)
#endif
void _print(int t) {cerr << t;}
void _print(long long int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(multimap <T, V> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define M 1000000007
#define PI 3.1415926535897932384626433832795
#define cntbits(x) __builtin_popcount(x)
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(a) a.begin(), a.end()
#define precise(i) cout<<fixed<<setprecision(i)
#define take(a,n) for(int j=0;j<n;j++) cin>>a[j]
#define give(a,n) for(int j=0;j<n;j++) cout<<a[j]<<' '; cout << endl;
#define vpi vector<pair<int,int>>
#define pi pair<int,int>
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

void modsum(int &a, int b) { a = (a%M + b%M + M )%M ;}
void modmul(int &a, int b) { a = (a%M * b%M )%M ;}

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 
int n, m;
class DisjointSet{
    private:
        vector<int> size, par;
        
    public:
        DisjointSet(int n){
            size.resize(n+1);
            par.resize(n+1);
            for(int i=0; i<=n; i++){
                par[i] = i;
                size[i] = 1;
            }
        }
        int findUpar(int u){
            if(u == par[u]) return u ;
            return par[u] = findUpar(par[u]);
        }
        int mx = 1, component = n;
        void unionBySize(int u, int v){
            int pu = findUpar(u);
            int pv = findUpar(v);
            if(pu == pv) return;
            if(size[pu] > size[pv]){
                size[pu] += size[pv];
                par[pv] = pu;
                mx = max(mx, size[pu]);
            }
            else{
                size[pv] += size[pu];
                par[pu] = pv;
                mx = max(mx, size[pv]);
            }
            component--;
        }

        int maxi(){
            return mx;
        }
        int comps(){
            return component;
        }
};


void solve()
{
    cin >> n >> m;
    DisjointSet ds(n);
    while(m--){
        int u, v; cin >> u >> v;
        ds.unionBySize(u, v);
        int pu = ds.findUpar(u), pv = ds.findUpar(v);
        cout << ds.comps() << " " << ds.maxi() << endl;
    }

    
}

int32_t main()
{fast
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("error.txt", "w", stderr);
#endif

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}