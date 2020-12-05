#include<bits/stdc++.h>
using namespace std;
long long n,k,a[100],ans;
pair<long long,long long> b[500010];
long long c[20];
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for (long long i=0;i<k;i++) cin>>a[i];
	for (long long i=0;i<n;i++){
		cin>>b[i].first>>b[i].second;
		c[b[i].first]+=b[i].second;
	}
	if (k==1){
		long long d[10],f=0,num;
		memset(d,0,sizeof(d));
		for (int i=1;i<=a[0];i++){
			int x=i;
			for (int j=0;j<n;j++)
				if (x+b[j].second<a[b[j].first-1]&&x+b[j].second>0){
					num++;
					x+=x+b[j].second;
				}
				else{
					f=1;
					break;
				}
			if (f==1) ans+=num;
			if (f==0){
				cout<<-1<<endl;
				return 0;
			}
		}
	}
	if (k==2){
		long long d[10][10];
		memset(d,0,sizeof(d));
		for (int i=1;i<=a[0];i++)
			for (int j=1;j<=a[1];j++){
				int x=i,y=j,num=0,f=0;
				for (int k=0;k<n;k++)
					if (b[k].first==0){
						if (x+b[k].second<a[b[k].first-1]&&x+b[k].second>0){
							num++;
							x+=x+b[k].second;
						}
						else{
							f=1;
							break;
						}
					}
					else{
						if (y+b[k].second<a[b[k].first-1]&&y+b[k].second>0){
							num++;
							y+=y+b[k].second;
						}
						else{
							f=1;
							break;
						}
					}
				if (f==1) ans+=num;
				if (f==0){
					if (c[0]==0&&c[1]==0){
						cout<<-1<<endl;
						return 0;
					}
					while (x+c[0]<a[0]&&x+c[0]>0&&y+c[1]<a[1]&&y+c[1]>0){
						x+=c[0];
						y+=c[1];
						num+=n;
					}
					for (int k=0;k<n;k++)
						if (b[k].first==0){
							if (x+b[k].second<a[b[k].first-1]&&x+b[k].second>0){
								num++;
								x+=x+b[k].second;
							}
							else
								break;
						}
						else{
							if (y+b[k].second<a[b[k].first-1]&&y+b[k].second>0){
								num++;
								y+=y+b[k].second;
							}
							else
								break;
						}
					ans+=num;
				}
			}
	}
	if (k==3){
		long long d[10][10][10];
		memset(d,0,sizeof(d));
		for (int i=1;i<=a[0];i++)
			for (int j=1;j<=a[1];j++)
				for (int k=1;k<=a[2];k++){
					int x=i,y=j,z=k,num=0,f=0;
					for (int l=0;l<n;l++)
						if (b[l].first==0){
							if (x+b[l].second<a[b[l].first-1]&&x+b[l].second>0){
								num++;
								x+=x+b[l].second;
							}
							else{
								f=1;
								break;
							}
						}
						else if (b[l].first==1){
							if (y+b[l].second<a[b[l].first-1]&&y+b[l].second>0){
								num++;
								y+=y+b[l].second;
							}
							else{
								f=1;
								break;
							}
						}
						else{
							if (z+b[l].second<a[b[l].first-1]&&z+b[l].second>0){
								num++;
								z+=z+b[l].second;
							}
							else{
								f=1;
								break;
							}
						}
					if (f==1) ans+=num;
					if (f==0){
						if (c[0]==0&&c[1]==0){
							cout<<-1<<endl;
							return 0;
						}
						while (x+c[0]<a[0]&&x+c[0]>0&&y+c[1]<a[1]&&y+c[1]>0&&z+c[2]<a[2]&&z+c[2]>0){
							x+=c[0];
							y+=c[1];
							z+=c[2];
							num+=n;
						}
						for (int l=0;l<n;l++)
							if (b[l].first==0){
								if (x+b[l].second<a[b[l].first-1]&&x+b[l].second>0){
									num++;
									x+=x+b[l].second;
								}
								else
									break;
							}
							else if (b[l].first==1){
								if (y+b[l].second<a[b[l].first-1]&&y+b[l].second>0){
									num++;
									y+=y+b[l].second;
								}
								else
									break;
							}
							else{
								if (z+b[l].second<a[b[l].first-1]&&z+b[l].second>0){
									num++;
									z+=z+b[l].second;
								}
								else
									break;
							}
						ans+=num;
					}
				}
	}
	cout<<ans<<endl;
	return 0;
}
