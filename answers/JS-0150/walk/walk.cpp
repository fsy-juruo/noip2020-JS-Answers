#include <bits/stdc++.h>
#define rept(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,a) rept(i,0,a)
#define re return
#define sz(a) ((int)a.size())
#define fill(a,t) memset(a,t,sizeof a)
#define all(a) a.begin(),a.end()
#define erase_end(a) if(sz(a))a.erase(a.end()-1)
#define erase_str(a) if(sz(a))a.erase(a.begin())
#define pb push_back


using namespace std;
int read(){
	int f=1,cur=0;
	char ch=cin.get();
	while ((ch<'0' || ch>'9') && ch!='-')  ch=cin.get();
	if (ch=='-') f=-1;
	else cur=ch-'0';
	ch=cin.get();
	while (ch>='0' && ch<='9')  cur=10*cur+ch-'0',ch=cin.get();
	re f*cur;
}
int w[11];
int pos[11][500005];
int change[11];
int mx[11],mi[11];
int tot;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int n,k;
	cin>>n>>k;int kkk=1;
	rep(i,k) cin>>w[i],mx[i]=-111111111,mi[i]=111111111,kkk*=w[i];
	rept(i,1,n+1){
		int c,d;
		cin>>c>>d;c--;
		rep(j,k) pos[j][i]=pos[j][i-1];
		pos[c][i]+=d;
		mx[c]=max(mx[c],pos[c][i]);
		mi[c]=min(mi[c],pos[c][i]);
	}
	rep(i,k) change[i]=pos[i][n]-pos[i][0],tot+=abs(change[i]);
	if (!tot){
		int l=1;
		rep(i,k) if (mx-mi>=w[i]) l=0;
		if (l) re cout<<-1,0;
	}
	int ans=0;
	rep(i,kkk){
		int ii=i;
		int o[11]={};
		rep(j,k){
			o[j]=ii%w[j];
			ii/=w[j];
		}
		for (int j=0;;j++){
			rep(l,k) if (pos[l][j]+change[l]*(j/n)+o[l]<0 || pos[l][j]+change[l]*(j/n)+o[l]>=w[l]){
				ans+=j;
				break;
			}
		}
	}
	cout<<ans;
	re 0;
}

/****************** /
		1、检查附初值
		2、检查数组大小，绝对不MLE
		3、检查会不会爆int
		4、对拍查错
/ ******************/
