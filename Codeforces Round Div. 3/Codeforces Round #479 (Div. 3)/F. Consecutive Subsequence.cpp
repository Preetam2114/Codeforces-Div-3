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

map<int,int>mp;
const int AX = 2e5+66;
int dp[AX];
int res[AX];
int a[AX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n ;
	int maxn = 0;
	int id ;
	for( int i = 0 ; i < n ; i++ ){
		cin >> a[i];
		mp[a[i]] = mp[a[i]-1] + 1;
		if( mp[a[i]] > maxn ){
			maxn = mp[a[i]];
			id = i;
		}
	}
	cout << maxn << endl;
	int tot = 0;
	res[tot++] = id + 1;
	for( int i = id - 1 ; i >= 0 ; i-- ){
		if( maxn == tot ) break;
		if( a[i] + 1 == a[id] ){
			res[tot++] = i + 1;
			id = i;
		}
	}
	for( int i = tot - 1 ; i > 0 ; i-- ){
		cout << res[i] << ' ';
	}cout << res[0] << endl;
	return 0;
}