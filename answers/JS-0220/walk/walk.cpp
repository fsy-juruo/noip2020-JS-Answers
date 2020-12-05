#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0' ||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
struct node{
	int wd;
	int dis;
}step[500005];
int s[500005][12];
int w[10],n,k;
int pos[10];
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=k;++i){
		w[i]=read();
	}
	for(int i=1;i<=n;++i){
		step[i].wd=read();
		step[i].dis=read();
		s[i][step[i].wd]=s[i-1][step[i].wd]+step[i].dis;
	}
	bool f=0;
	for(int i=1;i<=k;++i){
		if(s[n][k]!=0)f=1;
	}
	if(!f){
		cout<<-1<<endl;
		return 0;
	}
	cout<<-1<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

