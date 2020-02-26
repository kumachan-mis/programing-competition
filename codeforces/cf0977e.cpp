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

void dfs(
    int node,
    const vector< vector<int> >& edges,
    vector<int>& is_visited_node,
    vector<int>& connected
) {
    is_visited_node[node] = 1;
    connected.push_back(node);
    for (int next : edges[node]) {
        if (is_visited_node[next]) continue;
        dfs(next, edges, is_visited_node, connected);
    }
}

int main() {
    int n, m; cin >> n >> m;
    vector<int> is_visited_node(n, 0);
    vector< vector<int> > edges(n);
    REP(i, m) {
        int a, b; cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }
    int ans = 0;
    REP(i, n) {
        if (is_visited_node[i]) continue;
        vector<int> connected;
        dfs(i, edges, is_visited_node, connected);
        bool is_circle = true;
        for (int node : connected) {
            if (SZ(edges[node]) != 2) {
                is_circle = false;
                break;
            }
        }
        if (is_circle) ans++;
    }
    cout << ans << endl;
    return 0;
}

// 連結成分の抽出は素直に再帰を書いて深さ優先探索をすればいい
// 変に for 文とかを使って技巧的なことをやろうとしない！
