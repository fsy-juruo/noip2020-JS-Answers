#include<bits/stdc++.h>
#define N 105
using namespace std;
int n,m;
int a[N],b[N],c[N],sa,sb;
int ste1[N],ste2[N],opt;
bool ck(int &p1,int&p2){
	p1=p2=n;
	int l;
	bool flag=0;
	for(int i=m;i>=1;i--){
		if(a[i]!=sa){
			p1=i;flag=1;l=m-(n-i+1);
			break;
		}
	}
	for(int i=n;i>=m-l+1;i--){
		if(b[i]!=sb){
			p2=i;flag=1;
			break;
		}
	}
	return flag;
}
void rever(int p1,int p2){
	int t1=p1,t2=p2;
	int top=0;
	while(p1<=m){
		ste1[++opt]=1;ste2[opt]=3;c[++top]=a[m-(p1-t1)];p1++;
	}
	while(p2<=m){
		ste1[++opt]=2;ste2[opt]=3;c[++top]=b[m-(p2-t2)];p2++;
	}
	while(top){
		if(c[top]==sa){
			a[t1]=sa;
			ste1[++opt]=3;ste2[opt]=1;
		}
		else{
			b[t2]=sb;
			ste1[++opt]=3;ste2[opt]=2;
		}
		top--;
	}
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==2){
		for(int i=1;i<=m;i++)scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)scanf("%d",&b[i]);
		sa=a[1],sb=b[1];
		int p1,p2;
		while(ck(p1,p2)){
			rever(p1,p2);
		}
		printf("%d\n",opt);
		for(int i=1;i<=opt;i++){
			printf("%d %d\n",ste1[i],ste2[i]);
		}
	}
	return 0;
}
/*
2 3
1 1 2
2 1 2*/
