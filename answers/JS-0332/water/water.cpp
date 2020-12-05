#include<bits/stdc++.h>
using namespace std;
vector<int>g[100500];
int d[100500];
int ans[100500];
bool vh[100500];
int cnt;
int n,m;
struct node{
	int zi,mu;
};
node q[100500];
int gcd(int a,int b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')
			w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return w*s;
}
void readp(){
	n=read(),m=read();
	int num=0;
	for(int i=1;i<=n;i++){
		num=read();
		int x;
		if(num==0){
			ans[++cnt]=i;
			vh[i]=true;
		}		
		else{
			for(int j=1;j<=num;j++){
				x=read();
				d[x]++;
				g[i].push_back(x);
			}	
		}	
	}	
}

void work(int s,int mm,int zz){
	if(vh[s]==true){
		int m2=q[s].mu,z2=q[s].zi;
		if(m2==0&&z2==0){
		q[s].mu=mm,q[s].zi=zz;	
		}
		else{
			int maxn=mm*m2/gcd(mm,m2);
			zz=zz*(maxn/mm);
			z2=z2*(maxn/m2)+zz,m2=maxn;
			q[s].mu=m2,q[s].zi=z2;	
		}
		return ;
	}
	for(int i=0;i<g[s].size();i++){
		int vv=g[s][i];
		work(vv,mm*g[s].size(),zz);
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	readp();
	for(int i=1;i<=n;i++){
		if(d[i]==0){
			q[i].zi=q[i].mu=1;
			work(i,1,1);
		}
	}
	for(int i=1;i<=cnt;i++){
		int mm=q[ans[i]].mu;
		int zz=q[ans[i]].zi;
		int summ=gcd(mm,zz);
		if(summ!=1){
			mm=mm/summ;
			zz=zz/summ;
		}
		cout<<zz<<' '<<mm<<endl;
	}
	return 0;
}

