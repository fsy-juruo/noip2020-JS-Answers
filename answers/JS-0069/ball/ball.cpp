#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f*=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x*=10;
		x+=ch-'0';
		ch=getchar();
	}
	return x*f;
}
int a[410][40];
int step[10010][5];
int n,m;
int f[410][40];
bool check(){
	for(int i=1;i<=n+1;i++){
		for(int j=2;j<=m;j++){
			if(f[i][j]!=f[i][j-1])return 0;
		}
	}
	return 1;
}
void work(int step1){
	if(check()){
		cout<<step1<<endl;
		for(int i=1;i<=step1;i++)cout<<step[i][1]<<' '<<step[i][2]<<endl;
		exit(0);
	}
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=n+1;j++){
			if(i==j)continue;
			if(f[i][0]==0)break;
			if(f[j][0]==m)break;
			f[i][0]--;
			int k=f[i][f[i][0]+1];
			f[j][0]++;
			f[j][f[j][0]]=k;
			work(step1+1);
			f[i][0]++;
			f[j][0]--;
			f[i][f[i][0]]=k;
		}
	}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];	
		} 
	}	
	for(int i=1;i<=m;i++){
		f[i][0]=n;
		for(int j=1;j<=n;j++)f[i][j]=a[i][j];
	}
	if(n<=2){
		if(n==1){
			cout<<n-1<<endl;
			for(int i=2;i<=m;i++)cout<<i<<' '<<1<<endl;
			return 0;
		}else{
			work(0);
		}
	} else if(n<=10){
		work(0);
	}
	return 0;
}
