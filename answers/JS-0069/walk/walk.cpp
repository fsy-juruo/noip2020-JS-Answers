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
int w[10010];
int c[10010],d[10010];
struct nnn{int x,y;};
int f[10010];
bool inside(int n){
	for(int i=1;i<=n;i++)if(f[i]<0||f[i]>w[i])return 0;
	return 1;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int n,m;
	n=read();
	m=read();
	
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		c[i]=read();
		d[i]=read();
	}
	int ans=0;
	if(m==1){
		for(int i=1;i<=w[1];i++){
			int st=i;
			
			while(st>0&&st<=w[1]){
				for(int j=1;j<=n;j++){
					if(st>0&&st<=w[1]){
						st+=d[j];
						ans++;
					}else{
						break;
					}
				}
				if(st==i){
					cout<<-1<<endl;
					return 0;
				}
			}		
		}
		cout<<ans<<endl;
		return 0;
	}else if(m==2){
		for(int i=1;i<=w[1];i++){
			for(int j=1;j<=w[2];j++){
				nnn tmp;
				tmp.x=i;
				tmp.y=j;
				int tmpx=0;
				while(tmp.x>0&&tmp.x<=w[1]&&tmp.y>0&&tmp.y<=w[2]){
					for(int k=1;k<=n;k++){
						if(tmp.x>0&&tmp.x<=w[1]&&tmp.y>0&&tmp.y<=w[2]){
							if(c[k]==1){
								tmp.x+=d[k];
							}else if(c[k]==2){
								tmp.y+=d[k];
							}
							tmpx++;
						}else{
							break;
						}
					}
					if(tmp.x==i&&tmp.y==j){
						cout<<-1<<endl;
						return 0;
					}
				}
				ans+=tmpx;
			}
		}
		cout<<ans<<endl;
		return 0;
	}else if(m==3){
		for(int i=1;i<=w[1];i++){
			for(int j=1;j<=w[2];j++){
				for(int k=1;k<=w[3];k++){
					f[1]=i;
					f[2]=j;
					f[3]=k;
					while(inside(3)){
						for(int qq=1;qq<=n;qq++){
							if(inside(3)){
								f[c[qq]]+=d[qq];
								ans++;
							}else{
								break;
							}
						}
						if(f[1]==i&&f[2]==j&&f[3]==k){
							cout<<-1<<endl;
							return 0;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
		return 0;
	}else if(m==4){
		for(int i=1;i<=w[1];i++){
			for(int j=1;j<=w[2];j++){
				for(int k=1;k<=w[3];k++){
					for(int l=1;l<=w[4];l++){
						f[1]=i;
						f[2]=j;
						f[3]=k;
						f[4]=l;
						while(inside(4)){
							for(int qq=1;qq<=n;qq++){
								if(inside(4)){
									f[c[qq]]+=d[qq];
									ans++;
								}else{
									break;
								}
							}
							if(f[1]==i&&f[2]==j&&f[3]==k&&f[4]==l){
								cout<<-1<<endl;
								return 0;
							}
						}
					}
				}
			}
		}
		cout<<ans<<endl;
		return 0;
	}else if(m==5){
		for(int i=1;i<=w[1];i++){
			for(int j=1;j<=w[2];j++){
				for(int k=1;k<=w[3];k++){
					for(int l=1;l<=w[4];l++){
						for(int q=1;q<=w[5];q++){
							f[1]=i;
							f[2]=j;
							f[3]=k;
							f[4]=l;
							f[5]=q;
							while(inside(5)){
								for(int qq=1;qq<=n;qq++){
									if(inside(5)){
										f[c[qq]]+=d[qq];
										ans++;
									}else{
										break;
									}
								}
								if(f[1]==i&&f[2]==j&&f[3]==k&&f[4]==l&&f[5]==q){
									cout<<-1<<endl;
									return 0;
								}
							}
						}
					}
				}
			}
		}
		cout<<ans<<endl;
		return 0;
	}else{
		
		cout<<-1<<endl;
	}
	return 0;
}
