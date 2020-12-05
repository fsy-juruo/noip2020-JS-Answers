#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+10;
int a[N],ans[N],temb[N];//»ã¼¯ 
LL f1[N],f2[N];//´æ´¢
vector<int> b[N];//ÅÅ³ö 
int n,m,tot;
queue<int> q;
LL Gcd(LL a,LL b){
	if(a<b) swap(a,b);
	if(b==0) return a;
	LL c=a%b;
	return Gcd(b,c);
}
void Add(int x,int y){
	LL q1=f1[x],p1=f2[x]*b[x].size();
	LL q2=f1[y],p2=f2[y];
	if(q2!=0){
		int k=p1/Gcd(p1,p2)*p2;
		f1[y]=q1*(k/p1)+q2*(k/p2);
		f2[y]=k;
		k=Gcd(f1[y],f2[y]);
		f1[y]/=k,f2[y]/=k;
	}else{
		f1[y]=q1,f2[y]=p1;
	}

}
void Pai(int x[],int ll,int rr){
	if(ll==rr) return;
	int mid=(ll+rr)>>1,tot=ll,i=ll,j=mid+1;
	Pai(x,ll,mid),Pai(x,mid+1,rr);
	while(i<=mid&&j<=rr){
		if(x[i]<=x[j]) temb[tot++]=x[i],i++;
		else temb[tot++]=x[j],j++;
	}
	while(i<=mid)	temb[tot++]=x[i++];
	while(j<=rr)	temb[tot++]=x[j++];
	for(int i=ll;i<=rr;++i) x[i]=temb[i];
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		int k,x;
		scanf("%d",&k);
		for(int j=1;j<=k;++j){
			scanf("%d",&x);
			b[i].push_back(x);
			a[x]++;
		}
	}
	
	for(int i=1;i<=n;++i){
		if(a[i]==0){
			f1[i]=1,f2[i]=1;
			q.push(i);
		}
	}
	
	while(q.size()){
		int x=q.front();
		if(b[x].size()==0){
			ans[++tot]=x;
		}
		for(int i=0;i<b[x].size();++i){
			int y=b[x][i];
			Add(x,y);
			a[y]--;
			if(a[y]==0){
				q.push(y);
			}
		}
		q.pop();
	}
	Pai(ans,1,tot);
	
	for(int i=1;i<=tot;++i){
		cout<<f1[ans[i]]<<" "<<f2[ans[i]]<<endl;
	}
	return 0;
}

