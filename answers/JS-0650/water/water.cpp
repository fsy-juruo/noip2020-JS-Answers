#include<bits/stdc++.h>
using namespace std;
inline long long readd(){
	long long x=0,w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')w=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	return x*w;
}
const int maxn=200005;
struct node{
	long long x,y;
}t[maxn];
vector<long long>a[maxn];
long long n,m,m1,mm,i,j,k,l,s,d,f,r,h[maxn],ans[maxn],depth[maxn],b[maxn],bb[maxn];
long long gcd(long long a,long long b){
	if(b==1)return 1;
	long long r=a%b;
	while(r){
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
void jia(long long xx,long long yy,long long chu,long long dep){
	long long aa=xx,bb=yy,aaa=t[dep].x,bbb=t[dep].y,ax,by;
	if(xx%chu==0){
		aa=xx/chu;
	}
	else
	if(chu==4&&xx%2==0){
		aa/=2;
		bb*=2;
	}
	else{
		bb*=chu;
	}
	if(aaa==0&&bbb==0){
		t[dep].x=aa;
		t[dep].y=bb;
		return;
	}
	ax=aa*bbb+aaa*bb;
	by=bb*bbb;
	long long k=gcd(ax,by);
	t[dep].x=ax/k;
	t[dep].y=by/k;
	return;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=readd();
	m=readd();
	m1=0;
	memset(depth,0,sizeof(depth));
	for(i=1;i<=n;i++){
		l=readd();
		if(l==0){
			ans[++m1]=i;
		}
		for(j=1;j<=l;j++){
			f=readd();
			a[i].push_back(f);
			depth[f]++;
		}
	}
	for(i=1;i<=m;i++){
		b[i]=i;
		t[i].x=1;
		t[i].y=1;
	}
	while(m){
		mm=0;
		for(i=1;i<=m;i++){
			for(j=0;j<a[b[i]].size();j++){
				jia(t[b[i]].x,t[b[i]].y,a[b[i]].size(),a[b[i]][j]);
				depth[a[b[i]][j]]--;
				if(depth[a[b[i]][j]]==0){
					bb[++mm]=a[b[i]][j];
				}
			}
		}
		for(i=1;i<=mm;i++){
			b[i]=bb[i];
		}
		m=mm;
	}
	for(i=1;i<=m1;i++){
		int xx=t[ans[i]].x,yy=t[ans[i]].y;
		printf("%d %d\n",xx,yy);
	}
	return 0;
}

