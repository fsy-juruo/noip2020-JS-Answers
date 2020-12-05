#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	char c=getchar();
	while(!isdigit(c))c=getchar();
	ll f=0;
	for(;isdigit(c);c=getchar())f=f*10+(c-'0');
	return f;
}
const int GG=1e6;
int n,k,a[12],mx[12],mn[12],x[505050],y[505050],i0,i1,i2,i3,i4;
ll c[2][101010];
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<k;i++)cin>>a[i];
	ll ans=0;
	if(k==1){
		mx[0]=mn[0]=0;
		int h=0;
		for(int i=0;i<100010;i++)c[0][i]=c[1][i]=1e18;
		c[0][0]=c[1][0]=0;
		for(int i=0;i<n;i++){
			int cr=read(),d=read();
			if(h+d>mx[i]){
				for(int j=mx[i]+1;j<=h+d;j++)c[0][j]=i+1;
				mx[i]=h+d;
			}
			if(h+d<mn[i]){
				for(int j=1-mn[i];j<=-h-d;j++)c[1][j]=i+1;
				mn[i]=h+d;
			}
		}
		if(h==0){
			if(mx[0]-mn[0]<n||mx==0||mn==0)cout<<"-1\n";
			else{
				for(int i=0;i<a[0];i++)ans+=min(c[0][a[0]-i],c[1][i+1]);
				cout<<ans<<endl;
			}
		}
		if(h<0){
			for(int i=0;i<a[0];i++)ans+=min(c[0][a[0]-i],(ll)n*((i+1)/(-h))+c[1][(i+1)%(-h)]);
			cout<<ans<<endl;
		}
		if(h>0){
			for(int i=0;i<a[0];i++)ans+=min(c[1][1+i],(ll)n*((a[0]-i)/(-h))+c[0][(a[0]-i)%(-h)]);
			cout<<ans<<endl;
		}
		return 0;
	}
	for(int i=0;i<n;i++){
		x[i]=read()-1;
		y[i]=read();
	}
	ans=0;
	if(k<5)a[4]=1;
	if(k<4)a[3]=1;
	if(k<3)a[2]=1;
	for(i0=0;i0<a[0];i0++) for(i1=0;i1<a[1];i1++) for(i2=0;i2<a[2];i2++)
	for(i3=0;i3<a[3];i3++) for(i4=0;i4<a[4];i4++){
		ll p=0;
		int j0=i0,j1=i1,j2=i2,j3=i3,j4=i4;
		while(j0>=0&&j0<a[0]&&j1>=0&&j1<a[1]&&j2>=0&&j2<a[2]&&j3>=0&&j3<a[3]&&j4>=0&&j4<a[4]){
			if(p>1e7){
				cout<<"-1\n";
				return 0;
			}
			int i=p%n;
			if(x[i]==0)j0+=y[i];
			if(x[i]==1)j1+=y[i];
			if(x[i]==2)j2+=y[i];
			if(x[i]==3)j3+=y[i];
			if(x[i]==4)j4+=y[i];
			p++;
		}
		ans+=p;
	}
	cout<<ans<<endl;
	return 0;
}
