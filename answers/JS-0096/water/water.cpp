#include<bits/stdc++.h>
using namespace std;
long long n,m,tot,mm,s;
long long head[500050],b[500050],a[10],la[500050],p[100010],q[100010],t[100010];
vector<int> vec;
bool vis[100010],vi[100010],v[100010];
void add(long long x,long long y){
	tot++;la[tot]=head[x];head[x]=tot;b[tot]=y;
}
int work(long long xx,long long yy){
	if (xx%yy==0) return yy;
	else return work(yy,xx%yy);
}
int work2(long long aa,long long bb,long long cc,long long dd){
	long long s1=bb*dd;
	long long s2=aa*dd+cc*bb;
	return work(s1,s2);
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i<=n;i++){
		cin>>t[i];
		if (t[i]==0){
			vi[i]=1; 
			s++;
		} 
		for (long long j=1;j<=t[i];j++){
			cin>>a[j];
			vis[a[j]]=1;
			add(i,a[j]);
		}
	}
	for (long long i=1;i<=n;i++){
		if (vis[i]==0){
			vec.push_back(i);
			p[i]=1;q[i]=1;
			v[i]=true;
		}
	}
	while (vec.empty()==0){
		long long k=vec[vec.size()-1];
		vec.pop_back();v[k]=false;
		for (long long i=head[k];i!=0;i=la[i]){
			long long ch=b[i];
			if(v[ch]==false){
				vec.push_back(ch);
				v[ch]=true;
			}
			int ma=work(max(p[k],t[k]),min(p[k],t[k]));
			if (p[ch]==0){
				p[ch]=p[k]/ma;q[ch]=q[k]*t[k]/ma;
			}
			else{
				int pp=p[k]/ma,qq=q[k]*t[k]/ma;
				int mm=work2(pp,qq,p[ch],q[ch]);
				p[ch]=(pp*q[ch]+p[ch]*qq)/mm;q[ch]=qq*q[ch]/mm;
			}
			
		}
		if (vi[k]!=1){
			p[k]=0;q[k]=0;
		}
	}
	for (long long i=1;i<=n;i++){
		if (vi[i]==1) cout<<p[i]<<" "<<q[i]<<endl;
	}
	return 0;
}

