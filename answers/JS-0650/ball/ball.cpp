#include<bits/stdc++.h>
using namespace std;
inline int readd(){
	int x=0,w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')w=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	return x*w;
}
const int maxn=1005;
int la,n,m,i,j,k,l,s,d,f,ans,r,a[maxn][500],qi[maxn],h[maxn],lie[maxn],ding[maxn],ans1[maxn*maxn],ans2[maxn*maxn];
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=readd();
	m=readd();
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			a[i][j]=readd();
		}
		ding[i]=a[i][1];
		qi[i]=m;
	//	h[ding[i]]++;
	}
	qi[n+1]=0;
	memset(h,0,sizeof(h));
	ans=0;
	for(i=1;i<=n;i++){
		lie[i]=0;
		for(j=2;j<=m;j++){
			if(a[i][j]!=ding[i]){
				lie[i]=j-1;
				break;
			}
		}
		if(lie[i]==0){
			lie[i]=n;
			h[i]=1;
		}
	}
	la=0;
	l=0;
/*	for(i=1;i<=n;i++){
		cout<<lie[i]<<" ";
	}
	cout<<endl;*/
//	cout<<"dg"<<endl;
	while(true){
		if(l<25)
		l++;
	//	cout<<"g"<<endl;
		for(i=1;i<=n;i++){
			if(la==i)continue;
	//		cout<<i<<endl;
			if(h[i]==0){
				if(qi[i]-lie[i]<=m-1){
					for(j=n+1;j>=1;j--){
						if(i==j)continue;
					/*	if(i==15){
							cout<<j<<endl;
						}*/
						while(qi[j]<m&&qi[i]>lie[i]){
							ans1[++ans]=i;
							ans2[ans]=j;
							++qi[j];
							a[j][qi[j]]=a[i][qi[i]];
							--qi[i];
					/*		if(i==15&&j==14)
							cout<<ans<<" "<<qi[i]<<" "<<lie[i]<<" "<<qi[j]<<endl;*/
						}
					}
					la=i;
	//				cout<<"dgsg"<<endl;
				}
				else continue;
	//			cout<<"dgg"<<endl;
				if(qi[i]==lie[i]){
					for(j=1;j<=n+1;j++){
						if(i!=j){
							while(a[j][qi[j]]==ding[i]){
								++qi[i];
								++lie[i];
								a[i][qi[i]]=ding[i];
								--qi[j];
								ans1[++ans]=j;
								ans2[ans]=i;
							}
						}
					}
				}
				la=i;
			}
	//		cout<<i<<endl;
		}
//		cout<<"sdg"<<endl;
	//	cout<<"dg"<<endl;
		for(i=1;i<=n;i++){
			if(lie[i]==m)h[i]=1;
		}
		d=0;
		for(i=1;i<=n;i++){
			if(!h[i]){
				d=1;
				break;
			}
		}
		if(d==0){
			break;
		}
	/*	if(l<=20){
		for(i=1;i<=n+1;i++){
			for(j=1;j<=qi[i];j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}*/
	//	cout<<ans<<endl;
	}
	cout<<ans<<endl;
	for(i=1;i<=ans;i++){
	//	cout<<i<<" ";
		printf("%d %d\n",ans1[i],ans2[i]);
	}
	return 0;
}

