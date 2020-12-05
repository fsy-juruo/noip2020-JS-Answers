#include<bits/stdc++.h>
#define r register
using namespace std;
int n,k,wd[11],way[1001][2],ans;
inline int read(){
	r int w=1,x=0; r char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}return w*x;
}
inline void walk1(r int k){
	bool flag=0;
	while(!flag)
	for(r int i=1;i<=n;i++){
		k+=way[i][1]; ans++;
		if(ans==1000000000){
			flag=1; ans=-1;
			break;
		}
		if(k<1||k>wd[1]){
			flag=1;
			break;
		}
	}
}
inline void walk2(r int k1,r int k2){
	bool flag=0;
	while(!flag)
	for(r int i=1;i<=n;i++){
		if(way[i][0]==1) k1+=way[i][1]; 
		if(way[i][0]==2) k2+=way[i][1]; 
		ans++;
		if(ans==1000000000){
			flag=1; ans=-1;
			break;
		}
		if(k1<1||k1>wd[1]||k2<1||k2>wd[2]){
			flag=1;
			break;
		}
	}
}
inline void walk3(r int k1,r int k2,r int k3){
	bool flag=0;
	while(!flag)
	for(r int i=1;i<=n;i++){
		if(way[i][0]==1) k1+=way[i][1]; 
		if(way[i][0]==2) k2+=way[i][1];
		if(way[i][0]==3) k3+=way[i][1]; 
		if(ans==1000000000){
			flag=1; ans=-1;
			break;
		}
		if(k1<1||k1>wd[1]||k2<1||k2>wd[2]||k3<1||k3>wd[3]){
			flag=1;
			break;
		}
	}
}
inline void walk4(r int k1,r int k2,r int k3,r int k4){
	bool flag=0;
	while(!flag)
	for(r int i=1;i<=n;i++){
		if(way[i][0]==1) k1+=way[i][1]; 
		if(way[i][0]==2) k2+=way[i][1];
		if(way[i][0]==3) k3+=way[i][1]; 
		if(way[i][0]==4) k4+=way[i][1];
		ans++;
		if(ans==1000000000){
			flag=1; ans=-1;
			break;
		}
		if(k1<1||k1>wd[1]||k2<1||k2>wd[2]||k3<1||k3>wd[3]||k4<1||k4>wd[4]){
			flag=1;
			break;
		}
	}
}
inline void walk5(r int k1,r int k2,r int k3,r int k4,r int k5){
	bool flag=0;
	while(!flag)
	for(r int i=1;i<=n;i++){
		if(way[i][0]==1) k1+=way[i][1]; 
		if(way[i][0]==2) k2+=way[i][1];
		if(way[i][0]==3) k3+=way[i][1]; 
		if(way[i][0]==4) k4+=way[i][1];
		if(way[i][0]==5) k5+=way[i][1]; 
		ans++;
		if(ans==1000000000){
			flag=1; ans=-1;
			break;
		}
		if(k1<1||k1>wd[1]||k2<1||k2>wd[2]||k3<1||k3>wd[3]||k4<1||k4>wd[4]||k5<1||k5>wd[5]){
			flag=1;
			break;
		}
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(); k=read();
	for(r int i=1;i<=k;i++)	
		wd[i]=read();
	for(r int i=1;i<=n;i++)
		way[i][0]=read(),way[i][1]=read();	
	if(k>5){
		cout<<-1;
		return 0;
	}
	if(k==1){
		for(r int i=1;i<=wd[1];i++)
			walk1(i);
	}
	if(k==2){
		for(r int i=1;i<=wd[1];i++)
			for(r int j=1;j<=wd[2];j++)
				walk2(i,j);
	}
	if(k==3){
		for(r int i=1;i<=wd[1];i++)
		for(r int j=1;j<=wd[2];j++)
		for(r int ij=1;ij<=wd[3];ij++)
			walk3(i,j,ij);
	}
	if(k==4){
		for(r int i=1;i<=wd[1];i++)
		for(r int j=1;j<=wd[2];j++)
		for(r int ij=1;ij<=wd[3];ij++)
		for(r int ijj=1;ijj<=wd[4];ijj++)
			walk4(i,j,ij,ijj);
	}
	if(k==5){
		for(r int i=1;i<=wd[1];i++)
		for(r int j=1;j<=wd[2];j++)
		for(r int ij=1;ij<=wd[3];ij++)
		for(r int ijj=1;ijj<=wd[4];ijj++)
		for(r int ii=1;ii<=wd[5];ii++)
			walk5(i,j,ij,ijj,ii);
	}
	cout<<ans;
	return 0;
}
