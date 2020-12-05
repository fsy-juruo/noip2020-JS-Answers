#include<bits/stdc++.h>
using namespace std;
vector<int>chu[100010],ru[100010];
long long n,m;
bitset<200000>h;
struct myt{
	long long x,y;
};
myt a[200000];
long long read(){
	long long x=0,f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(; isdigit(c);c=getchar())x=x*10+c-'0';
	return x*f;
}
long long gcd(long long x,long long y){
	if(x==0||y==0)return 0;
	if(x<y)swap(x,y);
	while(x%y){
		long long t=x;
		x=y;
		y=t%y;
	}
	return y;
}
myt add_fs(long long fz1,long long fm1,long long fz2,long long fm2){
	long long tfz=fz1*fm2+fz2*fm1,tfm=fm1*fm2;
	long long t=gcd(tfz,tfm);
	tfz/=t;
	tfm/=t;
	myt ans;
	ans.x=tfz;
	ans.y=tfm;
	return ans;
}
myt work(long long node){
	if(h[node]==1)return a[node];
	else{
		for(long long i=0;i<ru[node].size();i++){
			work(ru[node][i]);
			a[node]=add_fs(a[ru[node][i]].x,a[ru[node][i]].y,a[node].x,a[node].y);
		}
		if(chu[node].size()!=0)a[node].y*=chu[node].size();
		h[node]=1;
		return a[node];
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();
	m=read();
	for(long long i=1;i<=n;i++){
		 long long t=read();
		 for(long long j=1;j<=t;j++){
		 	long long tt=read();
		 	chu[i].push_back(tt);
		 	ru[tt].push_back(i);
		 }
	}
	for(long long i=1;i<=n;i++)a[i].y=1;
	for(long long i=1;i<=m;i++)a[i].x=1;
	for(long long i=1;i<=n;i++){
		if(chu[i].size()==0){
			myt ans=work(i);
			cout<<ans.x<<' '<<ans.y<<endl;
		}
	}
	return 0;
} 
