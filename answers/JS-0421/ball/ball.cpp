#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
int n,m;
vector<int>v[60];int co[820010][2];int k=0;
bool ok[60];
inline void scz(int x,int y){
	v[y].push_back(v[x].back());v[x].pop_back();
	co[++k][0]=x;co[k][1]=y;
	return;
}
inline bool chk(){
	int tmp=1;
	rep(i,1,n)tmp&=((int)v[i].size()!=0);
	return tmp;
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	read(n);read(m);
	rep(i,1,n){
		rep(j,1,m){int x;read(x);v[i].push_back(x);}
	}
	
	if(n<=2){
		int opt=v[1].back();
		while(!v[1].empty()&&v[1].back()==opt)scz(1,3);
		while(!v[2].empty()&&v[2].back()==opt)scz(2,3);
		while((int)v[3].size()<m){
			if(v[1].size()>v[2].size()){
				while(!v[1].empty()&&v[1].back()!=opt){
					if((int)v[2].size()==m){
						opt=3-opt;
						while(!v[3].empty())scz(3,1);
						while(!v[2].empty()&&v[2].back()==opt)scz(2,3);
						continue;
					}
					scz(1,2);
				}
				while(!v[1].empty()&&v[1].back()==opt)scz(1,3);
			}else{
				while(!v[2].empty()&&v[2].back()!=opt){
					if((int)v[1].size()==m){
						opt=3-opt;
						while(!v[3].empty())scz(3,2);
						while(!v[1].empty()&&v[1].back()==opt)scz(1,3);
					}
					scz(2,1);
				}
				while(!v[2].empty()&&v[2].back()==opt)scz(2,3);
			}
		}
		int pos=((v[1].size()<v[2].size())?1:2);
		rep(i,1,m)scz(3,pos);
	}else{
		while(1){
			int opt=0;
			rep(i,1,n){if(!ok[i]){opt=v[i].back();break;}}
			if(!opt)break;
			rep(i,1,n){
				while(!v[i].empty()&&v[i].back()==opt)scz(i,n+1);
			}
			while(v[n+1].size()<m||chk()){
				bool flag=true;
				rep(i,1,n){
					if(ok[i]||v[i].empty())continue;
					rep(j,i+1,n){
						if(ok[j]||v[j].empty())continue;
						if(v[i].size()>v[j].size()){
							while(!v[i].empty()&&v[i].back()!=opt){
								if((int)v[j].size()==m){
									if(v[n+1].size()+v[i].size()>m){flag=false;break;}
									opt=v[j].back();
									while(!v[n+1].empty())scz(n+1,i);
									while(!v[j].empty()&&v[j].back()==opt)scz(j,n+1);
									continue;
								}
								scz(i,j);
							}
							while(!v[i].empty()&&v[i].back()==opt)scz(i,n+1);
						}else{
							while(!v[j].empty()&&v[j].back()!=opt){
								if((int)v[i].size()==m){
									if(v[n+1].size()+v[i].size()>m){flag=false;break;}
									opt=v[i].back();
									while(!v[n+1].empty())scz(n+1,j);
									while(!v[i].empty()&&v[i].back()==opt)scz(i,n+1);
									continue;
								}
								scz(j,i);
							}
							while(!v[j].empty()&&v[j].back()==opt)scz(j,n+1);
						}
						flag=false;break;
					}
					if(flag==false)break;
				}
			}
			int pos=0;
			rep(i,1,n){if((int)v[i].size()==0){pos=i;break;}}
			ok[pos]=1;
			while(!v[n+1].empty())scz(n+1,pos);
		}
	}
	write(k);
	rep(i,1,k){qwq(co[i][0]);putchar(' ');write(co[i][1]);}
	return 0;
}
