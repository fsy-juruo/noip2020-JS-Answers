#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int w=1,s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return w*s;
}
int n,m,d,ans[100005],bns[100005],c,tp,a[100005],b[100005],x,y,z;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=m;i++){
		a[i]=1;
		b[i]=1;
	}
	for(int i=1;i<=n;i++){
		d=read();
		if(d!=0){
			for(int j=0;j<d;j++){
				c=read();
				if(a[c]*b[c]==0){
				    a[c]=a[i];
				    b[c]=d*b[i];
				}
				else{
				    a[c]=a[c]*d*b[i]+b[c]*a[i];
				    b[c]=b[c]*d*b[i];
				}
			}
		}
		if(d==0){
			ans[tp]=a[i];
			bns[tp]=b[i];
			tp++;
		}
	}
	
	for(int i=0;i<tp;i++){
		x=ans[i];
		y=bns[i];
		while(y%x!=0){
			z=x;
			x=max(x,y)-min(x,y);
			y=z;
		}
		ans[i]/=x;
		bns[i]/=x;
	    printf("%d %d\n",ans[i],bns[i]);
	}
	return 0;
}
