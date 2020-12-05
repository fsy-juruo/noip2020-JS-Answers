#include<bits/stdc++.h>
using namespace std;
int n,k,wd[11];
struct node{
	int c,d;
}step[100005];
inline int read(){
	int x=0;
	int t=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*t;
}
void yw(){
	bool yes=1;
	unsigned long long bs=0;
	for(int i=1;i<=wd[1];i++){
		int j=1;
		int wz=i;
		int wzz=wz;
		while(1){
			int b;
			if(j%n==0) b=n;
			else b=j%n;
			wz+=step[b].d;
			bs++;
			j++;
			if(wz<1||wz>wd[1]) break;
			if(j==2*n&&wz==wzz) {
				yes=0;
				break;
			}
		}
		if(!yes) break;
	}
	if(yes)cout<<bs%1000000007<<endl;
	else cout<<-1<<endl;
}
void ew(){
	bool yes=1;
	unsigned long long bs=0;
	for(int i=1;i<=wd[1]*wd[2];i++){
		int x=i/wd[1]+1;
		int y;
		if(i%wd[1]==0) y=wd[1];
			else y=i%wd[1];
		int j=1;
		int xx=x;
		int yy=y;
		while(1){
			int b;
			if(j%n==0) b=n;
			else b=j%n;
			if(step[b].c==1) y+=step[b].d;
			else x+=step[b].d;
			bs++;
			j++;
			if(x<1||x>wd[2]||y<1||y>wd[1]) break;
			if(j==2*n&&x==xx&&y==yy) {
				yes=0;
				break;
			}
		}
		if(!yes) break;
	}
	if(yes)cout<<bs%1000000007<<endl;
	else cout<<-1<<endl;
}
int main(){
    freopen("walk.in","r",stdin);
    freopen("walk.out","w",stdout);
	n=read();
	k=read();
	for(int i=1;i<=k;i++){
		wd[i]=read();
	}
	for(int i=1;i<=n;i++){
		step[i].c=read();
		step[i].d=read();
	}
	if(k==1){
	    yw();
	    return 0;
	}
	if(k==2){
		ew();
		return 0;
	}
	cout<<-1<<endl;
	return 0;
}
