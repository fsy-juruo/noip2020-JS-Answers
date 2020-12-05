#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[51][401];
vector<pair<int,int> > v;
int l[51];
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	l[i]=m;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	cin>>a[i][j];
	for(int d=0;d<n;d++){
		int mn=1;
		while(mn<m){
			if(a[d][mn]==-1)
			break;
			if(a[d][mn]!=a[d][mn-1])
			break;
			mn++;
		}
		if(mn==m)
		continue;
		for(int i=mn;i<m;i++){
			v.push_back(make_pair(d,n));
			a[n][m-i-1]=a[d][i];
			a[d][i]=-1;
			l[d]--;
			l[n]++;
		}
		int now=mn;
		for(int i=d+1;i<=n;i++){
			int j=m-1;
			for(;j>=0;j--){
				if(a[i][j]!=a[d][0])
				break;
				a[d][now++]=a[i][j];
				a[i][j]=-1;
				l[d]++;
				l[i]--;
				v.push_back(make_pair(i,d));
			}
			vector<int> now;
			for(int k=j;k>=0;k--)
			if(a[i][k]==a[d][0]){
				now.push_back(k);
			}
			if((int)(now.size())==0)
			continue;
			int syg=j,nn=0;
			while(nn<(int)(now.size())){
				int xynz=syg-now[nn];
				
				int hh=-1;
				int yl=l[d];
				for(int k=d;k<=n;k++){
					if(k==i)
					continue;
					int ll=l[k];
					if(m-ll==0)
					continue;
					for(int i1=0;i1<min(xynz,m-ll);i1++){
						v.push_back(make_pair(i,k));
						l[i]--;
						a[k][l[k]]=a[i][l[i]];
						a[i][l[i]]=-1;
						l[k]++;
					}
					
					xynz-=min(xynz,m-ll);
					if(xynz==0){
						hh=k;
						break;
					}
					
				}
				syg=now[nn]-1;
				nn++;
				for(int k=hh+1;k<=n;k++){
					if(k==i)
					continue;
					if(l[k]!=m){
						l[i]--;
						a[k][l[k]]=a[i][l[i]];
						a[i][l[i]]=-1;
						l[k]++;
						v.push_back(make_pair(i,k));
						hh=k;
						break;
					}
				}syg+=l[d]-yl;
				for(int k=0;k<l[d]-yl;k++){
					v.push_back(make_pair(d,i));
					l[d]--;
					a[i][l[i]]=a[d][l[d]];
					a[d][l[d]]=-1;
					l[i]++;
	
				}
				v.push_back(make_pair(hh,d));
				l[hh]--;
				a[d][l[d]]=a[hh][l[hh]];
				a[hh][l[hh]]=-1;
				l[d]++;
			}
		}
		while(l[n]>0){
			for(int j=d+1;j<n;j++){
				while(l[j]<m){
					if(l[n]==0)
					break;
					v.push_back(make_pair(n,j));
					l[n]--;
					a[j][l[j]]=a[n][l[n]];
					a[n][l[n]]=-1;
					l[j]++;
				}
				if(l[n]==0)
				break;
			}
		}
	}
	cout<<(int)(v.size())<<"\n";
	for(int i=0;i<(int)(v.size());i++){
		cout<<v[i].first+1<<" "<<v[i].second+1<<"\n";
	}
	return 0;
}

