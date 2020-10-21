#include <bits/stdc++.h>
#define F first
#define S second 
#define PB push_back 
#define MP make_pair
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define inputarr(arr,n) for(int i = 0; i < n; i++) cin>>arr[i];
#define inputmat(arr,a,b) for(int i=0; i < a; i++)for(int j=0; j < b; j++)cin>>arr[i][j];
#define print(arr) for(auto a:arr) cout<<a<<" "; cout<<"\n";
#define endl '\n'

template<typename KeyType, typename ValueType> 
std::pair<KeyType,ValueType> get_max( const std::map<KeyType,ValueType>& x ) {
  using pairtype=std::pair<KeyType,ValueType>; 
  return *std::max_element(x.begin(), x.end(), [] (const pairtype & p1, const pairtype & p2) {
        return p1.second < p2.second;
  }); 
}

constexpr unsigned int shash(const char *s, int off = 0) {                        
    return !s[off] ? 5381 : (shash(s, off+1)*33) ^ s[off];                           
}

using namespace std;
typedef long long ll;
const ll mod = 1e9;
const ll N = 2e5;

vector<int>G[N];
vector<int>rd;
int vis[N], n, m;
long long ans = 0;
void build() {
    int  i, j;
    cin >> n >> m;
    for (i = 0; i<m; ++i) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
}
void dfs(int x) {
    vis[x] = 1;
    rd.push_back(x);
    for (int i = 0; i<G[x].size(); ++i) {
        if (!vis[G[x][i]])dfs(G[x][i]);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(vis, 0, sizeof(vis));
    build();
    rep(i,1,n-1){
        if (!vis[i]) {
            rd.clear();
            dfs(i);
            bool flag = true;
            rep(j,0,rd.size)
                if (G[rd[j]].size() != 2) {
                    flag = false;
                    break;
                }
            if (flag)ans++;
        }
    }
    cout << ans;
	return 0;
}