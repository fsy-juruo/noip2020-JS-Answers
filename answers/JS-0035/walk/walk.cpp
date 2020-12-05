#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
inline int read(){
	int ret=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			w=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*w;
}
void print(int x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>=10){
		print(x/10);
		putchar('0'+x%10);
	}
	if(x<=9){
		putchar('0'+x);
	}
}
int n,k,w[N],c[N],d[N],pos[N],ans;
void dfs(int dim){
	if(dim==k+1){
		for(int i=1;i<=n;i++){
			ans++;
//			printf("pos[1]:%d pos[2]:%d\n",pos[1],pos[2]);
			if(pos[c[i]]+d[i]>w[i]||pos[c[i]]+d[i]<0){
//				printf("\n");
				return;
			}else{
				pos[c[i]]+=d[i];
			}
		}
//		printf("\n");
		return;
	}
	for(int i=1;i<=w[dim];i++){
		int tmp=pos[dim];
		pos[dim]=i;
		dfs(dim+1);
		pos[dim]=tmp;
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();
	k=read();
	for(int i=1;i<=k;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		c[i]=read();
		d[i]=read();
	}
	dfs(1);
	print(ans);
	putchar('\n');
	return 0;
}
