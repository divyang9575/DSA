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
template<typename F, typename S> ostream& operator <<(ostream& ostream, pair<F, S>& p) { cout << p.first << " " << p.second<<" "; return ostream; }
template<typename T> ostream& operator <<(ostream& ostream, vector<T>& v) { for(auto& element : v) cout << element << " "; return ostream;}
template<typename T> ostream& operator <<(ostream& ostream, vector<vector<T>>& v) {for(auto& row : v){ for(auto& cell : row) cout << cell << " "; cout << "\n";} return ostream;}
template<typename F, typename S> istream& operator >>(istream& istream, pair<F, S>& p) { cin >> p.first >> p.second; return istream;}
template<typename T> istream& operator >>(istream& istream, vector<T>& v) { for(auto& element : v) cin >> element; return istream; }

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    vector<int> ans;
    int i = 0, j = n-1;

    int z = 0, o = 0;
    for(auto i : s){
        if(i == '1') o++;
        else z++;
    }
    if(z != o) {
        cout << "-1\n";
        return;
    }

    int ops = 0;
    while(i < j && ops <= 300) {
            db(ops) db(s)
        if(s[i] == s[j]){
            ops++;
            if(s[i] == '0'){
                ans.push_back(j+1);
                s.insert(j+1, "01");
                i++, j++;
            }
            else if(s[i] == '1') {
                ans.push_back(i-1+1);
                s.insert(i, "01");
                i+=2, j+=2;
                i--, j--;
            }
            db(i) db(j) db(s) 
        }
        else{
            i++, j--;
        }
    }
    if(ops > 300) {
        cout << "-1\n";
        return;
    }
    cout << ans.size() << endl;
    // give(ans, ans.size());
    cout << ans << endl;
    
}

int32_t main()
{fast
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("error.txt", "w", stderr);
#endif

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}