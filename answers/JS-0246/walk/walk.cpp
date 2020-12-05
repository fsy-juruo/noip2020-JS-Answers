#include<bits/stdc++.h>
using namespace std;
inline int R(){
	int x=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=x*10+ch-48;
	return x*f;
}
int n,k,cnt=1;
int l[50],r[50],z[50];
int f[500010],x[500010],o[500010];
bool ch(){
	for(int i=1;i<=k;i++){
		if(z[i]!=0)return true;
	}
	return false;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=R();
	k=R();
	long long sum=0;
	unsigned long long ss=1;
	for(int i=1;i<=k;i++){
		int x;
		x=R();
		l[i]=1;
		r[i]=x;
		o[i]=x;
		ss*=x;
	}
	for(int i=1;i<=n;i++){
		f[i]=R();
		x[i]=R();
	}
	long long s=1;
	while(ch()||cnt!=n){
		int ff=f[cnt],xx=x[cnt];
		z[ff]+=xx;
		if(xx>0){
			if(z[ff]+r[ff]>o[ff]){
				sum+=ss/(r[ff]-l[ff]+1)*s;
				ss-=ss/(r[ff]-l[ff]+1);
				r[ff]--;
				if(r[ff]<l[ff])break;
			}
		}else{
			if(z[ff]+l[ff]<1){
				sum+=ss/(r[ff]-l[ff]+1)*s;
				ss-=ss/(r[ff]-l[ff]+1);
				l[ff]++;
				if(r[ff]<l[ff])break;
			}
		}
		s++;
		cnt=cnt%n+1;
		if(sum<0)break;
	}
	if(!ch()||sum<0)cout<<-1<<endl;
	else cout<<sum<<endl;
	return 0;
}

