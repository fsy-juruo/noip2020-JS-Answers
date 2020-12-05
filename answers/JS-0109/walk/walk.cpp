#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=b;++i)
const int M=1e9+7,N=100005;
int rd(){int aaa;scanf("%d",&aaa);return aaa;}
void intpf(int aaa){printf("%d",aaa);return;}
int n,k,w[15],maxx[15][2],ult[15],p[15],ans[N],cnt;
int walk[N][2];
bool prework(){
	F(i,1,n){
		int c=walk[i][0],d=walk[i][1];
		ult[c]+=d;
		maxx[c][0]=min(maxx[c][0],ult[c]);
		maxx[c][1]=max(maxx[c][1],ult[c]);
	}
	int f=1;
	F(i,1,k)if(ult[i]!=0)f=0;
	if(f){
		F(i,1,k)if(abs(maxx[i][0])+maxx[i][1]+1>w[i])f=0;
	}
	return f;
}
int tell(int i,int j){
	int sum=0;
	while(1){
		F(ii,1,n){
		    int c=walk[ii][0],d=walk[ii][1];
		    if(c==1){i+=d;sum++;if(i>w[1]||i<1)return sum%M;}
		    if(c==2){j+=d;sum++;if(j>w[2]||j<1)return sum%M;}
	    }
	}
}
int tell2(int i,int j,int k){
	int sum=0;
	while(1){
		F(ii,1,n){
		    int c=walk[ii][0],d=walk[ii][1];
		    if(c==1){i+=d;sum++;if(i>w[1]||i<1)return sum%M;}
		    if(c==2){j+=d;sum++;if(j>w[2]||j<1)return sum%M;}
		    if(c==3){k+=d;sum++;if(k>w[3]||k<1)return sum%M;}
	    }
	}
}
int tell3(int i,int j,int k,int h){
	int sum=0;
	while(1){
		F(ii,1,n){
		    int c=walk[ii][0],d=walk[ii][1];
		    if(c==1){i+=d;sum++;if(i>w[1]||i<1)return sum%M;}
		    if(c==2){j+=d;sum++;if(j>w[2]||j<1)return sum%M;}
		    if(c==3){k+=d;sum++;if(k>w[3]||k<1)return sum%M;}
		    if(c==4){h+=d;sum++;if(h>w[4]||h<1)return sum%M;}
	    }
	}
}
int tell4(int i,int j,int k,int h,int l){
	int sum=0;
	while(1){
		F(ii,1,n){
		    int c=walk[ii][0],d=walk[ii][1];
		    if(c==1){i+=d;sum++;if(i>w[1]||i<1)return sum%M;}
		    if(c==2){j+=d;sum++;if(j>w[2]||j<1)return sum%M;}
		    if(c==3){k+=d;sum++;if(k>w[3]||k<1)return sum%M;}
		    if(c==4){h+=d;sum++;if(h>w[4]||h<1)return sum%M;}
		    if(c==5){l+=d;sum++;if(l>w[5]||l<1)return sum%M;}
	    }
	}
}
void work(){
	if(k==2){
		F(i,1,w[1])
		    F(j,1,w[2])cnt=(tell(i,j)+cnt)%M;
		cout<<cnt<<endl;
	}
	if(k==3){
		F(i,1,w[1])
		    F(j,1,w[2])
			    F(k,1,w[3])cnt=(tell2(i,j,k)+cnt)%M;
		cout<<cnt<<endl;
	}
	if(k==4){
		F(i,1,w[1])
		    F(j,1,w[2])
			    F(k,1,w[3])
				    F(h,1,w[4])cnt=(tell3(i,j,k,h)+cnt)%M;
		cout<<cnt<<endl;
	}
	if(k==5){
		F(i,1,w[1])
		    F(j,1,w[2])
			    F(k,1,w[3])
				    F(h,1,w[4])
					    F(l,1,w[5])cnt=(tell4(i,j,k,h,l)+cnt)%M;
		cout<<cnt<<endl;
	}
	return;
}
int solve(int x){
	if(ans[x])return ans[x];
	if(x+maxx[1][0]>=1&&x+maxx[1][1]<=w[1])return ans[x]=(solve(x+ult[1])+n)%M;
}
void subwork(){
	ult[1]=maxx[1][0]=maxx[1][1]=0;
	
	F(i,1,n){
		int d=walk[i][1];
		ult[1]+=d;
		if(ult[1]<maxx[1][0]){maxx[1][0]=ult[1];ans[-ult[1]]=i;}
		if(ult[1]>maxx[1][1]){maxx[1][1]=ult[1];ans[w[1]-ult[1]+1]=i;}
	}
	F(i,1,w[1]){
		cnt=(cnt+solve(i)%M)%M;
	}
	cout<<cnt<<endl;return;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	
	cin>>n>>k;
	F(i,1,k)w[i]=rd();
	F(i,1,n)walk[i][0]=rd(),walk[i][1]=rd();
	
	if(prework()){intpf(-1);return 0;}
	if(k==1)subwork();
	else work();
	return 0;
}
/*3 1
6
1 1
1 -1
1 -1
*/
