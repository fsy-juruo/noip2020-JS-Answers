#include<bits/stdc++.h>
using namespace std;
int n,m,c[53][403],needop[53],sz[53];
bool canuse[53],isused[53];
vector<pair<int,int> >op;
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			scanf("%d",&c[i][j]);
			c[i][j]--;
			sz[i]++;
		}
	for(int i=n;i>1;i--){
		for(int j=0;j<n;j++)
			needop[j]=0;
		for(int j=0;j<i;j++)
			for(int k=0;k<m;k++)
				needop[c[j][k]]+=m-k;
		for(int j=0;j<n;j++)
			canuse[j]=0;
		for(int j=0;j<i;j++)
			canuse[c[j][m-1]]=1;
		for(int j=0;j<n;j++)
			if(isused[j])
				canuse[j]=0;
		vector<pair<int,int> >V;
		for(int j=0;j<n;j++)
			if(canuse[j])
				V.push_back(make_pair(needop[j],j));
		sort(V.begin(),V.end());
		int nw=V[0].second;
		isused[nw]=1;
		int notnwdontcome=-1;
		for(int j=0;j<i;j++)
			while(c[j][sz[j]-1]==nw){
				notnwdontcome=j;
				op.push_back(make_pair(j,i));
				c[i][sz[i]++]=c[j][--sz[j]];
			}
		for(int j=0;j<i;j++){
			if(j==notnwdontcome)continue;
			for(int k=sz[j]-1;k>=0;k--)
				if(c[j][k]==nw){
					vector<pair<int,int> >invop;
					for(int l=sz[j]-1,I=0;l>k;l--){
						while(((m-sz[I])-(notnwdontcome==I))<=0||(I==j))I++; 
						c[I][sz[I]++]=c[j][--sz[j]];
						op.push_back(make_pair(j,I));
						invop.push_back(make_pair(I,j));
					}
					op.push_back(make_pair(j,notnwdontcome));
					c[notnwdontcome][sz[notnwdontcome]++]=c[j][--sz[j]];
					for(int l=0;l<invop.size();l++)
						if(invop[l].first!=notnwdontcome){
							c[invop[l].second][sz[invop[l].second]++]=c[invop[l].first][--sz[invop[l].first]];
							op.push_back(invop[l]);
						}
					op.push_back(make_pair(notnwdontcome,i));
					c[i][sz[i]++]=c[notnwdontcome][--sz[notnwdontcome]];
					for(int l=0;l<invop.size();l++)
						if(invop[l].first==notnwdontcome){
							c[invop[l].second][sz[invop[l].second]++]=c[invop[l].first][--sz[invop[l].first]];
							op.push_back(invop[l]);
						}
				}
		}int I=0,tmp=notnwdontcome;
		for(int j=0;j<i;j++)
			if(j!=tmp&&sz[j]!=m)
				notnwdontcome=j;
		int j=tmp;
		for(int k=sz[j]-1;k>=0;k--)
			if(c[j][k]==nw){
				vector<pair<int,int> >invop;
				for(int l=sz[j]-1,I=0;l>k;l--){
					while(((m-sz[I])-(notnwdontcome==I))<=0||(I==j))I++; 
					c[I][sz[I]++]=c[j][--sz[j]];
					op.push_back(make_pair(j,I));
					invop.push_back(make_pair(I,j));
				}
				op.push_back(make_pair(j,notnwdontcome));
				c[notnwdontcome][sz[notnwdontcome]++]=c[j][--sz[j]];
				for(int l=0;l<invop.size();l++)
					if(invop[l].first!=notnwdontcome){
						c[invop[l].second][sz[invop[l].second]++]=c[invop[l].first][--sz[invop[l].first]];
						op.push_back(invop[l]);
					}
				op.push_back(make_pair(notnwdontcome,i));
				c[i][sz[i]++]=c[notnwdontcome][--sz[notnwdontcome]];
				for(int l=0;l<invop.size();l++)
					if(invop[l].first==notnwdontcome){
						c[invop[l].second][sz[invop[l].second]++]=c[invop[l].first][--sz[invop[l].first]];
						op.push_back(invop[l]);
					}
			}
		while(sz[i-1]){
			while(sz[I]==m)I++;
			op.push_back(make_pair(i-1,I));
			c[I][sz[I]++]=c[i-1][--sz[i-1]];
		}
	}
	printf("%d\n",op.size());
	for(int i=0;i<op.size();i++)
		printf("%d %d\n",op[i].first+1,op[i].second+1);
	return 0;
}//tourist bless me!
