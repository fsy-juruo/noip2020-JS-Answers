#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1;
	char ch;
	long long k=0;
	ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		k=k*10+ch-'0';
		ch=getchar();
	}
	return k*f;
}
int n,k,ans=0;
int w[14];
struct Info{
	int wei,d;
}operate[500004];
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++)w[i]=read();
	for(int i=0;i<n;i++){
		operate[i].wei=read(),operate[i].d=read();
	}
	if(k==1){
		for(int i=1;i<=w[1];i++){
			int q=i;
			int t=0;
			while(q>0&&q<=w[1]){
				q+=operate[t%n].d;
				t++;
				if(t%n==0&&q==i){
					cout<<-1<<endl;
					return 0;
				}
			}
			ans=(ans+t)%1000000007;
		}
		printf("%d\n",ans);
		return 0;
	}
	if(k==2){
		for(int i=1;i<=w[1];i++){
			for(int j=1;j<=w[2];j++){
				int q=i,r=j,t=0;
				while(q>0&&q<=w[1]&&r>0&&r<=w[2]){
					if(operate[t%n].wei==1){
						q+=operate[t%n].d;
						t++;
					}else{
						r+=operate[t%n].d;
						t++;
					}
					if(t%n==0&&q==i&&r==j){
						cout<<-1<<endl;
						return 0;
					}
				}
				ans=(ans+t)%1000000007;
			}
		}
		printf("%d\n",ans);
		return 0;
	}
	if(k==3){
		for(int i=1;i<=w[1];i++){
			for(int j=1;j<=w[2];j++){
				for(int k=1;k<=w[3];k++){
					int q=i,r=j,s=k,t=0;
					while(q>0&&q<=w[1]&&r>0&&r<=w[2]&&s>0&&s<=w[3]){
						if(operate[t%n].wei==1){
							q+=operate[t%n].d;
							t++;
						}else if(operate[t%n].wei==2){
							r+=operate[t%n].d;
							t++;
						}else{
							s+=operate[t%n].d;
							t++;
						}
						if(t%n==0&&q==i&&r==j&&s==k){
							cout<<-1<<endl;
							return 0;
						}
					}
					ans=(ans+t)%1000000007;
				}
			}
		}
		printf("%d\n",ans);
		return 0;
	}
	cout<<-1<<endl;
	return 0;
}

