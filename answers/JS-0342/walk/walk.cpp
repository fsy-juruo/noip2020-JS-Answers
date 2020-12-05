#include<bits/stdc++.h>
using namespace std;
int m[100001];
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int k,n,sum=0;
	cin>>n>>k;
	if(k==5){
		int s[4][4][4][4][4],f[6],step[6],w[6],wm[6],wn[6];
		for(int i=1;i<=n;i++){
			cin>>w[i];
			
		}
		for(int i=1;i<=5;i++){
			wm[i]=-1000000;
			wn[i]=1000000;
			m[i]=0;
		}
		for(int i=1;i<=n;i++){
			
		int ym1,ym2;
		cin>>ym1>>ym2;
		f[i]=ym1;
		step[i]=ym2;
		m[f[i]]+=step[i];
		wm[ym1]=max(wm[ym1],m[ym1]);
		wn[ym1]=min(wn[ym1],m[ym1]);
		}
		int a[6];
		for(a[1]=1;a[1]<=w[1];a[1]++){
			for(a[2]=1;a[2]<=w[2];a[2]++){
				for(a[3]=1;a[3]<=w[3];a[3]++){
					for(a[4]=1;a[4]<=w[4];a[4]++){
						for(a[5]=1;a[5]<=w[5];a[5]++){
							int b[6];
							b[1]=a[1],b[2]=a[2],b[3]=a[3],b[4]=a[4],b[5]=a[5];
							
							bool flag=0;
							while(flag!=true){
								for(int i=1;i<=5;i++){
								if(b[i]+wm[i]>w[i]||b[i]+wn[i]<1)flag=true;
							}
							if(flag==true)break;
							for(int i=1;i<=5;i++){
								b[i]+=m[i];
							}
							sum+=n;
							}
							
								for(int i=1;i<=n;i++){
									b[f[i]]+=step[i];
									if(b[f[i]]>w[f[i]]||b[f[i]]<1){
									sum+=i;
									break;
									}
								
							}
							sum%=1000000007;
						}
					}
				}
			}
		}
		
	}
	else if(k==4){
		int s[4][4][4][4];
	}
	else if(k==1){
		int w;
		cin>>w;
		int a,msum=0,maxn=0,minn=1000000;
		for(int i=1;i<=n;i++){
			cin>>a>>m[i];
			msum+=m[i];
			maxn=max(maxn,msum);
			minn=min(minn,msum);
		}
		
		if(msum==0&&maxn<w&&-minn<w){
			cout<<-1;
			return 0;
		}
		for(int i=1;i<=w;i++){
			int b=i;
			while(true){
			if(b+maxn>w||b+minn<1){
				for(int j=1;j<=n;j++){
					b+=m[j];
					if(b>w||b<1){
						sum+=j;
						break;
					}
				}
				break;
			}
			sum+=n;
			b+=msum;
			
			}
			sum%=1000000007;
		}
		
	}
	cout<<sum;
	return 0;
}

