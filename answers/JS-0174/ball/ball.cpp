#include<bits/stdc++.h>
using namespace std;
//#define int long long
void read(int &x){
	char c=getchar();int fc=1;
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') fc=-1,c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	x*=fc;
}
int n,m,to[60][410],a[60][410],ans;
int vis[60],ji[60];// ji:line  vis:color
void mem(){
	for(int i=1;i<=n;i++){
		if(!ji[i]&&!vis[to[i][1]]){
			vis[to[i][1]]=i;ji[i]=1;
			for(int j=1;j<=m;j++){
				a[i][j]=to[i][1];
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(ji[i]) continue;
		for(int j=1;j<=m;j++){
			if(vis[j]) continue;
			vis[j]=i;ji[i]=1;
			for(int k=1;k<=m;k++){
				a[i][k]=j;
			}
		}
	}
}
int sw[1000010][5],top;
int fw[60];
int calc(int sy,int ty){
	if(sy==ty&&sy==m) return 3;
	if(sy==m) return (m-ty+1)*2+1;
	if(ty==m) return (m-sy+1)*2+1;
	return calc(m,sy)+calc(m,ty)+min(calc(m,sy),calc(m,ty));
}
void find(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[j][i]!=to[j][i]){
				if(i>=(m-fw[j])){
					for(int k=1;k<=n;k++){
						if(a[k][i]==to[j][i]){
							sw[++top][1]=j;sw[top][2]=i;
							sw[top][3]=k;sw[top][4]=i;break;
						}
					}
				}
				else{
					sw[++top][1]=j;sw[top][2]=i;
					sw[top][3]=vis[to[j][i]];sw[top][4]=m-fw[j];
				}
				ans+=calc(i,m-fw[j]);fw[j]++;
				swap(a[sw[top][1]][sw[top][2]],a[sw[top][3]][sw[top][4]]);
			}
		}
	}
}
void print(int sx,int sy,int tx,int ty){
	if(sy==ty&&sy==m)
	printf("%d %d\n%d %d\n%d %d\n",tx,n+1,sx,tx,n+1,sx);
	else if(sy==m){
		for(int i=1;i<=(m-ty+1);i++){
			printf("%d %d\n",tx,n+1);
		}
		printf("%d %d\n%d %d\n",sx,tx,n+1,sx);
		for(int i=1;i<=(m-ty);i++){
			printf("%d %d\n",n+1,tx);
		}
	}
	else if(ty==m){
		for(int i=1;i<=(m-sy+1);i++){
			printf("%d %d\n",sx,n+1);
		}
		printf("%d %d\n%d %d\n",tx,sx,n+1,tx);
		for(int i=1;i<=(m-sy);i++){
			printf("%d %d\n",n+1,sx);
		}
	}
	else{
		int temp;
		for(int i=1;i<=n;i++){
			if(i!=sx&&i!=tx){
				temp=i;break;
			}
		}
		if(sy>=ty) print(temp,m,sx,sy),print(temp,m,tx,ty),print(temp,m,sx,sy);
		else print(temp,m,tx,ty),print(temp,m,sx,sy),print(temp,m,tx,ty);
	}
}
void solve(){
	for(int i=top;i>=1;i--){
		print(sw[i][1],sw[i][2],sw[i][3],sw[i][4]);
	}
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			read(to[i][j]);
		}
	}
	mem();find();
	printf("%d\n",ans);solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

