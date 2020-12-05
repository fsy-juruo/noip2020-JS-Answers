#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mem(x,v) memset(x,v,sizeof(x))

const int N=50+5;
const int M=400+5;
const int inf=1e9+7;
const int mod=998244353;

int n,m,a[N][M],b[N][M],cnt[N];
vector <pii> ans,tmp;
void move(int x,int y){
	ans.pb((pii){x,y});
	a[y][++cnt[y]]=a[x][cnt[x]--];
}
struct col{
	ll id,dep;
	bool operator < (const col &v) const {
		return dep<v.dep;
	}
}cc[N];
int top(int x){return a[x][cnt[x]];}
void solve(){
	for(int c=1;c<n;c++){
		for(int i=c;i<n;i++){
			int num=0,over=0; for(int j=1;j<=m;j++)num+=a[i][j]==c;
			if(num==0)continue;
			for(int j=1;j<=num;j++)move(i+1,n+1);
			for(int j=m;j;j--)
				if(a[i][j]==c)move(i,i+1);
				else if(cnt[i-1]<m)move(i,i-1);
				else move(i,n+1),over++;
			for(int j=1;j<=over+num;j++)move(n+1,i);
			for(int j=1;j<=num;j++)move(i+1,n+1);
			for(int j=1;j<=num;j++)move(i,i+1);
		} while(cnt[n])
			if(top(n)==c)move(n,n+1);
			else move(n,n-1);
		while(cnt[c])move(c,n);
		while(cnt[n+1])move(n+1,c);
	}
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m; cnt[0]=m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cin>>a[i][j],b[i][j]=a[i][j];
		cnt[i]=m;
	} solve(),cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}
