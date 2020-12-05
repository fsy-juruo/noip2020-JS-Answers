#include<bits/stdc++.h>
using namespace std;
struct f{
	int m,s;
}an[110000];
int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
f pl(f a,f b){
	if(a.m==0||a.s==0) return b;
	if(b.m==0||b.s==0) return a;
	f result;
	int k=gcd(a.m,b.m);
	int a1=b.m/k;
	int b1=a.m/k;
	result.m=a.m*a1;
	a.s*=a1;
	b.s*=b1;
	result.s=a.s+b.s;
	int k2=gcd(result.m,result.s);
	result.m/=k2;
	result.s/=k2;
	return result;
}
f ch(f a,int b){
	if(a.m==0||a.s==0) return a;
	if(b==0){
		a.m=0;
		a.s=0;
		return a;
	}
	a.m*=b;
	int k=gcd(a.m,a.s);
	a.m/=k;
	a.s/=k;
	return a;
}
int n,m,a[110000][6],cnt[110000],num,v[110000];
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cnt[i]=i;
		an[i].s=1;
		an[i].m=1;
	}
	num=m;
	for(int i=1;i<=n;++i){
		cin>>a[i][0];
		for(int j=1;j<=a[i][0];++j)
		cin>>a[i][j];
	}
	bool flag=false;
	do{
	//	cout<<endl<<num<<" ";
		flag=false;
		memset(v,0,sizeof(v));
		int num2=0,cnt2[110000];
		memset(cnt2,0,sizeof(cnt2));
		for(int i=1;i<=num;++i){
		bool td=true;
		f out=ch(an[cnt[i]],a[cnt[i]][0]);
	//	cout<<cnt[i]<<"|";
		for(int j=1;j<=a[cnt[i]][0];++j){
			td=false;
		//	cout<<a[cnt[i]][j]<<" /";
		flag=true;
		if(!v[a[cnt[i]][j]]){
			v[a[cnt[i]][j]]=1;
		    num2++;
		    cnt2[num2]=a[cnt[i]][j];
		   // cout<<endl<<cnt2[num2]<<" ";
		}
		//cout<<endl<<an[a[cnt[i]][j]].s<<" "<<an[a[cnt[i]][j]].m;
		an[a[cnt[i]][j]]=pl(an[a[cnt[i]][j]],out);
		//cout<<endl<<an[a[cnt[i]][j]].s<<" "<<an[a[cnt[i]][j]].m<<endl;
		}
		if(!td){
		an[cnt[i]].s=0;
		an[cnt[i]].m=0;
		}
		}
		for(int i=1;i<=num2;++i)
		cnt[i]=cnt2[i];
		num=num2;
		//cout<<endl;
	}while(flag);
	for(int i=1;i<=n;++i){
		if(a[i][0]==0) 
		cout<<an[i].s<<" "<<an[i].m<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
