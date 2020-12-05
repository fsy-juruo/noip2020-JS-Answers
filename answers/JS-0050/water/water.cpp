#include <bits/stdc++.h>
using namespace std;
void swap(int &x,int &y){
	int c;
	c=x;
	x=y;
	y=c;
	return;
}
void ss(int &a,int &b){
	int x=a,y=b,c;
	if(x<y) swap(x,y);
	while(x%y){
		c=x%y;
		x=y;
		y=c;
	}
	a=a/y;
	b=b/y;
	return;
}
void ha(int &a,int ao,int &b,int bo){
	if(a==0){
		a=ao;
		b=bo;
		return;
	}
	if(b==bo){
		a+=ao;
		ss(a,b);
		return;
	}
	else{
		int x=b,y=bo,c;
		if(x<y) swap(x,y);
		while(x%y){
		      c=x%y;
		      x=y;
		      y=c;
	    }
	    a=a*bo/y+ao*b/y;
	    b=b*bo/y;
	    ss(a,b);
	}
	return;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int a[n+1],b[n+1],i,j,x,y;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	a[1]=m;
	b[1]=1;
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		if(x!=0&&a[i]!=0){
			for(j=0;j<x;j++){
		   	   scanf("%d",&y);
		   	   if(a[i]%x==0) ha(a[y],a[i]/x,b[y],b[i]);
			   else ha(a[y],a[i],b[y],b[i]*x);
		   }
		   a[i]=0;
		}
	}
	for(i=1;i<=n;i++){
		if(a[i]!=0) printf("%d %d\n",a[i],b[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

