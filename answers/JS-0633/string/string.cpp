#include<bits/stdc++.h>
#define mkp make_pair
#define ms(a,x) memset(a,x,sizeof (a))
#define io_speed_up ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define debug cout<<"bug"<<"\n"
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define rrep(i,a,b) for(ll i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;

const ll P=20171321;

const ll maxn=(1<<20)+5;

ull p[maxn],val[maxn];
void init(string &s){
	ms(val,0);
	for(ll i=1;i<=s.size();i++){
		val[i]=val[i-1]*P+(s[i-1]-'a');
	}
}
ull hsh(ll l,ll r){
	return val[r]-val[l-1]*p[r-l+1];
}

ll T;
string s;
ll n;
ll cnt[30],tot;
ll L[maxn],R[maxn];  //�� ��/�� ���ж��ٸ������ַ� 
vector<ll> pos[maxn];  //��¼���ж��ٸ������ɸ��Ƶ�λ�� 

void main_init(){
	n=s.size();
	init(s);
	for(ll i=1;i<=s.size();i++) pos[i].clear();
	ms(cnt,0);
	L[0]=0;
	for(ll i=1;i<=s.size();i++){
		L[i]=L[i-1];
		cnt[s[i-1]-'a']++;
		if(cnt[s[i-1]-'a']&1){
			L[i]++;
		}
		else{
			L[i]--;
		}
	}
	
	ms(cnt,0);
	R[s.size()+1]=0;
	for(ll i=s.size();i>=1;i--){
		R[i]=R[i+1];
		cnt[s[i-1]-'a']++;
		if(cnt[s[i-1]-'a']&1){
			R[i]++;
		}
		else{
			R[i]--;
		}
	}
	
	rep(i,1,s.size()){
		ull hsh_val=hsh(1,i);
		for(ll j=i;j<=s.size();j+=i){
			ull tmp=hsh(j-i+1,j);
			if(hsh_val==tmp){
				pos[j].push_back(i);
			}
			else{
				break;
			}
		}
	}
	
//	rep(i,1,s.size()){
//		for(ll j=0;j<pos[i].size();j++){
//			cout<<pos[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	
}

ll sum[maxn];
ll ans=0;
vector<pii> Que;
#define lx x<<1
#define rx x<<1|1
#define lch l,mid,x<<1
#define rch mid+1,r,x<<1|1
ll tr[maxn*4];
void pushup(ll x){
	tr[x]=tr[lx]+tr[rx];
}
void add(ll pos,ll v,ll l=0,ll r=n,ll x=1){
	if(l==r){
		tr[x]+=v;
		return;
	}
	ll mid=l+r>>1;
	if(pos<=mid) add(pos,v,lch);
	if(pos>mid)  add(pos,v,rch);
	pushup(x);
}
ll query(ll qr,ll l=0,ll r=n,ll x=1){
	ll ql=0;
	if(ql<=l && r<=qr) return tr[x];
	ll mid=l+r>>1,aans=0;
	if(ql<=mid) aans+=query(qr,lch);
	if(qr>mid)  aans+=query(qr,rch);
	return aans;
}
void count(){
	sort(Que.begin(),Que.end());
//	for(ll i=0;i<Que.size();i++){
//		cout<<"{"<<Que[i].first<<","<<Que[i].second<<"}\n";
//	}
	ll ind=0;
	rep(i,0,n){
//		cout<<"i = "<<i<<"\n";
		if(i!=0) add(L[i],1);
		while(ind<Que.size() && Que[ind].first==i){
			ans+=query(Que[ind].second);
//			debug;
			ind++;
		}
	}
}

void solve(){
	main_init();
	ans=0;
//	cout<<"L:";
//	rep(i,1,n) cout<<L[i]<<" ";
//	cout<<"\n";
//	cout<<"R:";
//	rep(i,1,n) cout<<R[i]<<" ";
//	cout<<"\n";
	Que.clear();
	ms(tr,0);
	rep(i,3,n){
		ll lim=R[i];
//		sum[0]=0;
//		rep(j,1,i-1){
//			sum[j]=sum[j-1]+(L[j]<=R[i]);
//		}
		for(ll j=0;j<pos[i-1].size();j++){
			ll k=pos[i-1][j];      //L[1~k-1]���м���С��R[i]
			Que.push_back(mkp(k-1,lim));
		}
//		cout<<"ans["<<i<<"] = "<<ansi<<"\n";
	}
	count();
	cout<<ans<<"\n";
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	io_speed_up;
	p[0]=1;
	rep(i,1,(1<<20)){
		p[i]=p[i-1]*P;
	}
	ll T; cin>>T;
	while(T--){
		cin>>s;
		solve();
	}
	
	return 0;
}
//remember to check:
//1.long long
//2.freopen
//3.array size
//4.big testdata
//5.file name
//6.file comparison
//7.mod

