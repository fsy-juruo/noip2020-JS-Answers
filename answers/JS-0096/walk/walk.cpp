#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
long long w[20],c[500010],d[500010],dd[20],a[20],aa[20];
long long ch[20],mo[20];
void dfs(int x,int step){
	if (step==k){
		for (int i=1;i<=k;i++) aa[i]=a[i];
		long long l=0;
		bool fl=false;
//		long long p=aa[1],q=aa[2];
		while(fl==false){
			fl=false;
			for (int i=1;i<=n;i++){
			aa[c[i]]+=d[i];
			if ((aa[c[i]]<=0)||(aa[c[i]]>w[c[i]])){
				fl=true;
			//	cout<<p<<" "<<q<<" ";
			//	cout<<l*n+i<<endl;
				ans=((ans+l*n%1000000007)%1000000007+i)%1000000007;
				return;
			}
			}
			if (fl==true) exit;
			l++;
		}

	}
	else{
		for (int i=1;i<=w[step+1];i++){
			a[step+1]=i;
			dfs(i,step+1);
		}
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=k;i++) cin>>w[i];
	for (int i=1;i<=n;i++){
		cin>>c[i]>>d[i];
		dd[c[i]]+=d[i];
	}
	int kk=k;
	for (int i=1;i<=k;i++){
		if (dd[i]==0) kk--;
	}
	if (kk==0){
		cout<<"-1"<<endl;
		return 0;
	}
	for (int i=1;i<=w[1];i++) {
		a[1]=i;
		dfs(i,1);
	}
	cout<<ans<<endl;
	return 0;
}

