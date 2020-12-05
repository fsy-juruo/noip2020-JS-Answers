#include<bits/stdc++.h>
using namespace std;
int n,k,w[10];
int c[500001],d[500001];
int a[10],maxa[10],mina[10];
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int ans=0;
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		cin>>w[i];
	}
	for(int i=k+1;i<=5;i++){
		w[i]=1;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i]>>d[i];
		a[c[i]]+=d[i];
		if(a[c[i]]>maxa[c[i]]) maxa[c[i]]=a[c[i]];
		if(a[c[i]]<mina[c[i]]) mina[c[i]]=a[c[i]];
	}
	bool f=1;
	for(int i=1;i<=k;i++){
		if(a[i]!=0){
			f=0;
			break;
		}
	}
	if(n<=100){
	int i[6],p[6];
	for(i[1]=1;i[1]<=w[1];i[1]++){
		for(i[2]=1;i[2]<=w[2];i[2]++){
			for(i[3]=1;i[3]<=w[3];i[3]++){
				for(i[4]=1;i[4]<=w[4];i[4]++){
					for(i[5]=1;i[5]<=w[5];i[5]++){
						ans++;
						for(int j=1;j<=k;j++){
							p[j]=i[j];
						}
						int time=0;
						while(time<=100000){
							f=1;
							for(int l=1;l<=k;l++){
								if(p[l]+maxa[l]>w[l]||p[l]+mina[l]<=0){
									f=0;
									break;
								}
							}
							if(f){
								for(int l=1;l<=k;l++){
									p[l]+=a[l];
								}
								ans+=n;
							}
							else{
								for(int l=1;l<=n;l++){
									int to=p[c[l]]+d[l];
									if(to<=w[c[l]]&&to>0){
										p[c[l]]=to;
										ans++;
									}
									else break;
								}
								break;
							}
						}
						if(time>=100000){
							cout<<-1;
							return 0;
						}
					}
				}
			}
		}
	}
	}
	else{
	int i[6],p[6];
	for(i[1]=1;i[1]<=w[1];i[1]++){
		for(i[2]=1;i[2]<=w[2];i[2]++){
			for(i[3]=1;i[3]<=w[3];i[3]++){
				for(i[4]=1;i[4]<=w[4];i[4]++){
					for(i[5]=1;i[5]<=w[5];i[5]++){
						ans++;
						for(int j=1;j<=k;j++){
							p[j]=i[j];
						}
						int maxre=10000000;
						for(int l=1;l<=k;l++){
							if(a[l]>0) maxre=min(max((w[l]+1-maxa[l]-p[l])/a[l],0),maxre);
							if(a[l]<0) maxre=min(max((p[l]+mina[l])/(-a[l]),0),maxre);
							if(w[l]+1-maxa[l]-p[l]<0) {maxre=0; break;}
							if(p[l]+mina[l]<=0) {maxre=0; break;}
						}
						if(maxre==10000000){
							cout<<-1;
							return 0;
						}
						ans+=maxre*n;
						for(int l=1;l<=k;l++){
							p[l]+=a[l]*maxre;
						}
						for(int l=1;l<=n;l++){
							int to=p[c[l]]+d[l];
							if(to<=w[c[l]]&&to>0){
								p[c[l]]=to;
								ans++;
							}
							else break;
						}
					}
				}
			}
		}
	}
	}
	cout<<ans;
	
	return 0;
}
