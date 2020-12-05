#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
	return x*f;
}
int n,m;
int s[55][405],top[55];
int ans[820000+5][2],cnt;
int get(int x){
	return s[x][top[x]];
}
void yidong(int x,int y){
	ans[++cnt][0]=x,ans[cnt][1]=y;
	s[y][++top[y]]=s[x][top[x]--];
}
void dfs(int x,int y,int z,int color){
	int c=0,i;
	bool ok=1;
	for(i=1;i<=top[y];i++){
		if(s[y][i]==color){
			c++;
			break;
		}
	}
	for(i++;i<=top[y];i++){
		if(s[y][i]==color)c++;
		else ok=0;
	}
	if(ok){
		return;
	}
	for(int i=1;i<=c;i++)yidong(x,z);
	while(c){
		if(get(y)==color)yidong(y,x),c--;
		else yidong(y,z);
	}
	while(top[z]){
		yidong(z,y);
	}
	dfs(x,y,z,color);
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read();m=read();
	top[0]=1;
	for(int i=1;i<=n;i++){
		top[i]=m;
		for(int j=1;j<=m;j++)s[i][j]=read();
	}
	for(int k=1;k<=n;k++){
		for(int i=n-1;i>=k;i--)dfs(i,i+1,n+1,k);
		dfs(n,k,n+1,k);
		for(int i=k;i<=n;i++){
			while(get(i)==k)yidong(i,n+1);
		}
		for(int i=k+1;i<=n;i++){
			while(top[i]<m)yidong(k,i);
		}
		while(top[n+1])yidong(n+1,k);
	}
	cout<<cnt<<endl;
//	for(int i=1;i<=n+1;i++){
//			for(int j=1;j<=top[i];j++){
//				cout<<s[i][j]<<" ";
//			}
//			cout<<endl;
//		}
	for(int i=1;i<=cnt;i++)printf("%d %d\n",ans[i][0],ans[i][1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

