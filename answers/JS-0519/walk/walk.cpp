#include<bits/stdc++.h>
using namespace std;
int n,k,w[20],change1[500005],change2[500005][2],change3[500005][3];
long long ans=0;
int read(){
	int x=0,f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(; isdigit(c);c=getchar())x=x*10+c-'0';
	return x*f;
}
int check1(int p,int cyc){
	p+=change1[n]*(cyc-1);
	for(int i=1;i<=n;i++)if(p+change1[i]>w[1]||p+change1[i]<1)return i;
	return 0;
}
int half1(int p){
	int l=0,r=1000000000,mid;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check1(p,mid)==0)l=mid;
		else r=mid-1;
	}
	return l;
}
int check2(int x,int y,int cyc){
	x+=change2[n][0]*(cyc-1);
	y+=change2[n][1]*(cyc-1);
	for(int i=1;i<=n;i++)if(x+change2[i][0]>w[1]||x+change2[i][0]<1||y+change2[i][1]>w[2]||y+change2[i][1]<1)return i;
	return 0;
}
int half2(int x,int y){
	int l=0,r=1000000000,mid;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check2(x,y,mid)==0)l=mid;
		else r=mid-1;
	}
	return l;
}
int check3(int x,int y,int z,int cyc){
	x+=change3[n][0]*(cyc-1);
	y+=change3[n][1]*(cyc-1);
	z+=change3[n][2]*(cyc-1);
	for(int i=1;i<=n;i++){
		if(x+change3[i][0]>w[1]||x+change3[i][0]<1)return i;
		if(y+change3[i][1]>w[2]||y+change3[i][1]<1)return i;
		if(z+change3[i][2]>w[3]||z+change3[i][2]<1)return i;
		
	}
	return 0;
}
int half3(int x,int y,int z){
	int l=0,r=1000000000,mid;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check3(x,y,z,mid)==0)l=mid;
		else r=mid-1;
	}
	return l;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();
	k=read();
	for(int i=1;i<=k;i++)w[i]=read();
	if(k==1){
		for(int i=1;i<=n;i++){
			int wd=read();
			change1[i]=read();
		}
		for(int i=1;i<=n;i++)change1[i]+=change1[i-1];
		for(int i=1;i<=w[1];i++){
			int tp=i,f=1;
			for(int j=1;j<=n;j++){
				if(tp+change1[j]>w[1]||tp+change1[j]<1){
					f=0;
					ans+=j;
					break;
				}
			}
			if(f){
				if(change1[n]==0){
					cout<<"-1"<<endl;
					return 0;
				}else{
					int t=half1(i);
					ans+=t*n;
					ans+=check1(i,t+1);
				}
			}
		}
	}
	if(k==2){
		for(int i=1;i<=n;i++){
			int wd=read();
			change2[i][wd-1]=read();
		}
		for(int i=1;i<=n;i++)
		for(int j=0;j<2;j++)
		change2[i][j]+=change2[i-1][j];
		for(int i=1;i<=w[1];i++){
			for(int j=1;j<=w[2];j++){
				int tx=i,ty=j,f=1;
				for(int h=1;h<=n;h++){
					if(tx+change2[h][0]>w[1]||tx+change2[h][0]<1||ty+change2[h][1]>w[2]||ty+change2[h][1]<1){
						f=0;
						ans+=h;
						break;
					}
				}
				if(f){
					if(change2[n][0]==0&&change2[n][1]==0){
						cout<<"-1"<<endl;
						return 0;
					}else{
						int t=half2(i,j);
						ans+=t*n;
						ans+=check2(i,j,t+1);
					}
				}
			}
		}
	}
	if(k==3){
		for(int i=1;i<=n;i++){
			int wd=read();
			change3[i][wd-1]=read();
		}
		for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++)
		change3[i][j]+=change3[i-1][j];
		for(int i=1;i<=w[1];i++){
			for(int j=1;j<=w[2];j++){
				for(int h=1;h<=w[3];h++){
					int tx=i,ty=j,tz=h,f=1;
					for(int t=1;t<=n;t++){
					if(tx+change3[t][0]>w[1]||tx+change3[t][0]<1||ty+change3[t][1]>w[2]||ty+change3[t][1]<1||tz+change3[t][2]>w[3]||tz+change3[t][2]<1){
						f=0;
						ans+=t;
						break;
						}
					}
					if(f){
						if(change3[n][0]==0&&change3[n][1]==0&&change3[n][2]==0){
							cout<<"-1"<<endl;
							return 0;
						}else{
							int tt=half3(i,j,h);
							ans+=tt*n;
							ans+=check3(i,j,h,tt+1);
						}
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
