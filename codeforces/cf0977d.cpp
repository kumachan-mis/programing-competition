#include <bits/stdc++.h>
 
using namespace std;
 
// typedef
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
 
// container util
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
// repetition
#define FOR(i,m,n) for (ll (i) = ((ll) m); (i) < ((ll) n); ++(i))
#define RFOR(i,m,n) for (ll (i) = ((ll) (m)-1); (i) >= ((ll) n); --(i))
#define REP(i,n) FOR(i,0,n)
 
// i/o
#define TFOUT(b,t,f) cout << ((b)? (t) : (f)) << endl
 
// clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
 
// debug
#define dump(x)  cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl

template<typename T>
inline void cout_vector(const std::vector<T>& vec) {
    for (size_t i = 0; i < vec.size()-1; ++i) {
       std::cout << vec[i] << ' ';
    }
    std::cout << vec[vec.size()-1] << std::endl;
}

void solve(vector<ll>& temp, const unordered_set<ll>& a, vector<ll>& ans) {
    if (SZ(ans) == SZ(a)) return;
    if (SZ(temp) == SZ(a)) {
        ans = temp;
        return;
    }
    ll l = temp[SZ(temp)-1];
    if (a.count(l*2)) {
        temp.push_back(l*2);
        solve(temp, a, ans);
        temp.pop_back();
    }
    if (l%3 == 0 && a.count(l/3)) {
        temp.push_back(l/3);
        solve(temp, a, ans);
        temp.pop_back();
    }
}

int main() {
    int n; cin >> n;
    unordered_set<ll> a;
    a.reserve(n);
    for (size_t i = 0; i < n; ++i) {
        ll element; std::cin >> element;
        a.insert(element);
    }
    vll ans, temp;
    for (const ll e : a) {
       temp.push_back(e);
       solve(temp, a, ans);
       temp.pop_back();
    }
    cout_vector(ans);
    return 0;
}
