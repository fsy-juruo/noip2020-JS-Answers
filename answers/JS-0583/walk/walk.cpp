#include<bits/stdc++.h>
#define M 1000000007
#define K 11
#define N 500001
using namespace std;
int n,k,w[K]= {},c[N]= {},d[N]= {};
long long P=1ll;
int ans=0;
struct vec {
	int d[K];
	vec() {
		memset(d,0,sizeof(d));
	}
};
vec operator +(vec a,vec b) {
	vec c;
	for(int i=1; i<=k; i++)
		c.d[i]=a.d[i]+b.d[i];
	return c;
}
bool ins(vec a) {
	for(int i=1; i<=k; i++)
		if(a.d[i]<1||a.d[i]>w[i])return 0;
	return 1;
}
void Put(vec a) {
	for(int i=1; i<=k; i++)
		cout<<a.d[i]<<(i<k?" ":"\n");
}
bool nul(vec a) {
	for(int i=1; i<=k; i++) {
		if(a.d[i])return 0;
	}
	return 1;
}
int main() {
	freopen("walk.in","r",stdin);freopen("walk.out","w",stdout);
	cin>>n>>k;
	//vec MAX,MIN;
	for(int i=1; i<=k; i++)cin>>w[i],P*=1ll*w[i];
	vec x,xu,xd;//x weiyi ;xu zhengxiang zuida weiyi; xd fuxiang zuida weiyi
	for(int i=1; i<=n; i++) {
		cin>>c[i]>>d[i];
		x.d[c[i]]+=d[i];
		xu.d[c[i]]=max(xu.d[c[i]],x.d[c[i]]);
		xd.d[c[i]]=min(xd.d[c[i]],x.d[c[i]]);
	}
	//Put(x),Put(xd),Put(xu);
	vec d0;
	for(int i=1; i<=k; i++)
		d0.d[i]=1;
	//if(k==1)
	for(long long i=1; i<=P; i++) {
		vec dx=d0;
		while(ins(dx+xd)&&ins(dx+xu)) {
			dx=dx+x;
			if(nul(x)) {
				cout<<-1<<endl;   //Put(dx);
				return 0;
			}
			ans=(ans+n)%M;
		}
		for(int i=1; i<=n; i++) {
			dx.d[c[i]]+=d[i];
			ans=(ans+1)%M;//Put(dx);
			if(!ins(dx))break;//,cout<<ans<<endl;
		}
		d0.d[1]++;
		int j=1;
		while(j<=k&&d0.d[j]>w[j])d0.d[j]-=w[j],d0.d[++j]++;
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

