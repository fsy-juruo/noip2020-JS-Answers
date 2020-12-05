#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1050000;
const int inf=0x3f3f3f3f;

struct Seg{
	int l,r,dat;
}t[4*maxn];

int n,m=30,ans,T;
string s;
int pre1[maxn],pre2[maxn];
map<char,int> mp1,mp2;

void prework(){
	mp1[s[0]]++;
	pre1[0]=1;
	for(int i=1;i<=n;++i){
		mp1[s[i]]++;
		if(mp1[s[i]]%2==1) pre1[i]=pre1[i-1]+1;
		else pre1[i]=pre1[i-1]-1;
	}
	mp2[s[n]]++;
	pre2[n]=1;
	for(int i=n-1;i>=0;--i){
		mp2[s[i]]++;
		if(mp2[s[i]]%2==1) pre2[i]=pre2[i+1]+1;
		else pre2[i]=pre2[i+1]-1;
	}
}

void push_up(int x){
	t[x].dat=t[x<<1].dat+t[x<<1|1].dat;
}

void build(int l,int r,int x){
	t[x].l=l,t[x].r=r,t[x].dat=0;
	if(l==r) return ;
	int mid=(l+r)>>1;
	build(l,mid,x<<1);
	build(mid+1,r,x<<1|1);
	push_up(x);
}

void update(int pos,int d,int x){
	if(t[x].l>pos||t[x].r<pos) return ;
	if(t[x].l==t[x].r&&t[x].l==pos){
		t[x].dat+=d;
		return ;
	}
	int mid=(t[x].l+t[x].r)>>1;
	if(pos<=mid) update(pos,d,x<<1);
	else update(pos,d,x<<1|1);
	push_up(x);
}

int query(int l,int r,int x){
	if(t[x].l>=l&&t[x].r<=r){
		return t[x].dat;
	}
	int mid=(t[x].l+t[x].r)>>1,res=0;
	if(l<=mid) res+=query(l,r,x<<1);
	if(r>mid) res+=query(l,r,x<<1|1);
	return res;
}

void init(){
	for(map<char,int>::iterator it=mp1.begin();it!=mp1.end();++it){
		it->second=0;
	}
	for(map<char,int>::iterator it=mp2.begin();it!=mp2.end();++it){
		it->second=0;
	}
	memset(pre1,0,sizeof(pre1));
	memset(pre2,0,sizeof(pre2));
	ans=0;
}

bool check1(){
	char c=s[0];
	for(int i=0;i<=n;++i) if(s[i]!=c) return false;
	return true;
}

void sol1(){
	int cnt1=0,cnt2=0;
	for(int l=1;l<=n;++l){
		int p=(n+1)/l;
		if((n+1)%l==0) p--;
		for(int i=0;i<p;++i){
			int bound=pre2[0+((i+1)*l)];
			if(bound==0) ans+=(cnt1);
			else ans+=(cnt1+cnt2);
		}
		if(pre1[l-1]==1) cnt2++;
		else cnt1++;
	}
	cout<<ans<<endl;
}

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>s;
		n=s.size()-1;
		prework();
		if(check1()){
			sol1();
			init();
			continue;
		}
		build(0,m,1);
		for(int l=1;l<=n;++l){
			int p=(n+1)/l;
			string str=s.substr(0,l);
			if((n+1)%l==0) p--;
			for(int i=0;i<p;++i){
				string nw=s.substr(0+i*l,l);
				if(nw!=str) break;
				int bound=pre2[0+(i+1)*l];
				ans+=query(0,bound,1);
			}
			update(pre1[l-1],1,1);
		}
		cout<<ans<<endl;
		init();
	}
	return 0;
}
