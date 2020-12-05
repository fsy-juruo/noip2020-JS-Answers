#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
using namespace std;
template <typename T>inline void read(T &x){
	x=0;int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
template <typename T>inline void write(T x){
	ull y=0;ull t=x;int l=0;
	if(x<0){putchar('-');x++;t=-x;t++;}
	if(!t){putchar('0');return;}
	while(t){y=y*10+t%10;t/=10;l++;}
	while(l){putchar(y%10+'0');y/=10;l--;}
}
template <typename T>inline void writes(T x){
	write(x);
	putchar(' ');
}
template <typename T>inline void writeln(T x){
	write(x);
	puts("");
}
stack<int>a[60];
int vis[60][401];
int col[60];
int cz[1000010][2];
long long ans=0;
void cq(int x,int y){
	int z=a[x].top();
	vis[x][z]--;
	vis[y][z]++;
	a[x].pop();
	a[y].push(z);
	cz[++ans][0]=x;
	cz[ans][1]=y;
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int n,m,x,c;
	read(n),read(m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			read(x);
			a[i].push(x);
			if(!vis[i][x]){
				col[i]++;
			}
			vis[i][x]++;
		}
	}
	int l=n+1;
	int flag=0;
	while(l!=2){
		c=a[1].top();
		cq(1,l);
		for(int i=1;i<l;i++){
			while(vis[i][c]){
				for(int j=1;j<=l;j++){
					if(flag==1){
						while(a[l].top()!=c){
							cq(l,i);
						}
						flag=0;break;
					}
					if(j==i)continue;
					while(a[j].size()<m){
						if(!vis[i][c]){
							flag=1;
							break;
						}
						x=a[i].top();
						if(x==c){
							if(j==l){
								int k;
								for(k=1;i<l;k++){
									if(k==i)continue;
									if(!a[k].empty()){
										cq(k,l);
										cq(i,k);
										cq(l,i);
										break;
									}
								}
								while(a[l].top()!=c){
									cq(l,i);
								}
								cq(k,l);
							}
							else{
								cq(i,j);
								while(a[l].top()!=c){
									cq(l,i);
								}
								cq(j,l);	
							}
						}
						if(x!=c){
							cq(i,j);
						}
					}
				}
			}
		}
		l--;
		while(!a[l].empty()){
			for(int j=1;j<l;j++){
				while(a[j].size()<m){
					cq(l,j);
				}
			}
		}
	}
	writeln(ans);
	for(int i=1;i<=ans;i++){
		writes(cz[i][0]);
		writeln(cz[i][1]);
	}
	return 0;
}


