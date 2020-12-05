#include<bits/stdc++.h>
using namespace std;
struct node{
	int fz;int fm;
};
int n,m,b=0,c=0,tx,ty,tn=0;
int h1[10005];
int h3[10005];
int h2[10005];
int h4[10005];
node dis[10005];
vector<int>a[10005];
queue<int>q;
int gcd(int x,int y){
	int z=x%y;
	while(z!=0){
		x=y;
		y=z;
		z=x%y;
	}
	return y;
}
int yu(int x){
	int s=gcd(dis[x].fz,dis[x].fm);
	dis[x].fz/=s,dis[x].fm/=s;
}
int jia(int x1,int y1,int x2,int y2){
	return x1*y2+x2*y1;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>tn;
		if (tn==0){
			b++;
			h1[b]=i;
		}
		else {
			for(int j=1;j<=tn;j++){
				cin>>ty;
				a[i].push_back(ty);
			}
		}
		//cout<<i;
	}
	for(int i=1;i<=n;i++){
		if (h3[i]==0){
			c++;
			h2[c]=i;
		}
	}
	//cout<<1;
	for(int i=1;i<=c;i++){
		//cout<<1;
		q.push(h2[i]);
		for(int j=1;j<=n;j++){
			dis[j].fm=1;
		}
		dis[h2[i]].fm=1;
		dis[h2[i]].fz=1;
		while(!(q.empty())){
			int v=q.front();
			for(int j=0;j<a[v].size();j++){
				int u=a[v][j];
				dis[u].fz=jia(dis[v].fz,dis[v].fm*a[v].size(),dis[u].fz,dis[u].fm);
				dis[u].fm=dis[u].fm*dis[v].fm*a[v].size();
				//cout<<dis[u].fz<<" "<<dis[u].fm;
				yu(u);
				if (h4[u]==0){
					q.push(u);	
					h4[u]=1;				
				}
			}
			if (a[v].size()>0){
				dis[v].fz=0;
				dis[v].fm=0;			
			}
			//cout<<1<<v<<endl;
			/*for(int j=1;j<=n;j++){
				cout<<j<<" "<<dis[j].fz<<" "<<dis[j].fm<<endl;
			}*/
			q.pop();
			h4[v]=0;
		}	
	}
	//cout<<1;
	for(int i=1;i<=b;i++){
		cout<<dis[h1[i]].fz<<" "<<dis[h1[i]].fm<<endl;
	}
	return 0;
}

