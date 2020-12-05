#include<bits/stdc++.h>
using namespace std;
#define CIN int
#define reg register int
CIN rf(){
	CIN num=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		num=num*10+c-'0';
		c=getchar();
	}
	return num*f;
}

int n,k;
int K[500011];
struct node{
	int num,step;
}r[500011];
int S[500011];
long long ans=0;
long long l;
bool Ed=0;
bool C(){
	return clock()>960;
}
void dfs(int st,int p){
	if(C()||st>=l){
		puts("-1");Ed=1;exit(0);
	}
	for(reg i=1;i<=k;++i){
		if(S[i]>K[i]||S[i]<=0){
			ans+=st;
			return;
		}
	}
	S[r[p].num]+=r[p].step;
	int T=p+1;
	if(T>n)T=T-n;
	dfs(st+1,T);
}
int ss[10001];
void STR(int dep){
	if(C()){
		puts("-1");Ed=1;exit(0);
	}
	if(dep==k+1){
		for(reg j=1;j<=k;++j)
		ss[j]=S[j];
		dfs(0,1);
		if(Ed==1)return;
		for(reg j=1;j<=k;++j)
		S[j]=ss[j];
	}
	else {	
		for(reg i=1;i<=K[dep];++i){
			S[dep]=i;		
			STR(dep+1);
		}
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=rf();k=rf();
	for(reg i=1;i<=k;i++){
		K[i]=rf();
	}
	l=1000000;	
	for(reg i=1;i<=n;++i){
		r[i].num=rf();
		r[i].step=rf();
	}
	STR(1);
	if(Ed==1)return 0;
	printf("%d\n",ans);
	return 0;
}
//zz rp++

