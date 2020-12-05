#include<bits/stdc++.h>
using namespace std;
void read(unsigned int &x){
	x=0;char ch=0;
	while((ch<'0'||ch>'9'))ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
}
unsigned int n,m,fa[100005][11],son[100005],h[100005],cnt=0;
unsigned long long g;
unsigned long long gcd(unsigned long long a,unsigned long long b){
	if(a%b==0)
		return min(a,b);
	return gcd(b,a%b);
}
struct A{
	unsigned long long p;
	unsigned long long q;
	unsigned int d;
	unsigned int son;
	unsigned int x;
}a[100005],c[100005];
bool cmp(A x,A y){
	return x.son<y.son;
}
bool cmp2(A x,A y){
	if(x.x>=y.x){
		h[x.x]++;
		h[y.x]--;
	}
	return x.x<y.x;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n);read(m);
	for(unsigned int i=1;i<=n;i++)
		a[i].q=1;
	for(int i=1;i<=n;i++){
		read(a[i].d);
		h[i]=i;
		a[i].x=i;
		for(int j=1;j<=a[i].d;j++){
			read(fa[i][j]);
			a[fa[i][j]].son++;
		}
	} 
	for(unsigned int i=1;i<=m;i++){
		a[i].p=1;
		if(a[i].d==0){
			c[++cnt].x=a[i].x;
			c[cnt].p=1;
			c[cnt].q=1;
			continue;
		}
		for(unsigned int j=1;j<=a[i].d;j++){
			a[h[fa[a[i].x][j]]].p=a[h[fa[a[i].x][j]]].p*a[i].q+a[h[fa[a[i].x][j]]].q*a[i].p;
			a[h[fa[a[i].x][j]]].q=a[h[fa[a[i].x][j]]].q*a[i].d;
			g=gcd(a[h[fa[a[i].x][j]]].p,a[h[fa[a[i].x][j]]].q);
			a[h[fa[a[i].x][j]]].p/=g;
			a[h[fa[a[i].x][j]]].q/=g;
			a[h[fa[a[i].x][j]]].son--;
		} 
		
	}
	sort(a+m+1,a+n+1,cmp);
	for(unsigned int i=m+1;i<=n;i++){
		if(a[i].d==0){
			cnt++;
			c[cnt].p=a[i].p;
			c[cnt].q=a[i].q;
			c[cnt].x=a[i].x;
			continue;
		}
		for(unsigned int j=1;j<=a[i].d;j++){
			a[h[fa[a[i].x][j]]].p=a[h[fa[a[i].x][j]]].p*a[i].q*a[i].d+a[h[fa[a[i].x][j]]].q*a[i].p;
			a[h[fa[a[i].x][j]]].q=a[h[fa[a[i].x][j]]].q*a[i].q*a[i].d;
			g=gcd(a[h[fa[a[i].x][j]]].p,a[h[fa[a[i].x][j]]].q);
			a[h[fa[a[i].x][j]]].p/=g;
			a[h[fa[a[i].x][j]]].q/=g;
			a[h[fa[a[i].x][j]]].son--;	
		}
		for(unsigned int j=1;j<=a[i].d;j++)
		for(unsigned int k=h[fa[a[i].x][j]];k>=m+2;k--){
				if(a[k].son<a[k-1].son){
					h[a[k].x]=k-1;
					h[a[k-1].x]=k;
					swap(a[k],a[k-1]);
				}
				else
					break;
		}
	}
	sort(c+1,c+cnt+1,cmp2);
	for(unsigned int i=1;i<=cnt;i++)
		printf("%lld %lld\n",c[i].p,c[i].q);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
