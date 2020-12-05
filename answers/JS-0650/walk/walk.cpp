#include<bits/stdc++.h>
using namespace std;
inline int readd(){
	int x=0,w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')w=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	return x*w;
}
const int maxn=500005;
const long long p=1000000007;
long long t2,ans,xx,yy,n,m,i,j,k,l,s,d,f,r,hhh[maxn],tt[maxn],a[maxn],b[maxn],hh[maxn],t[maxn],h[maxn],ni[maxn],maxh[maxn],minh[maxn];
void dg(int dep){
	if(dep>m){
		for(int i=1;i<=m;i++){
			tt[i]=ni[i];
		}
		int d;
		s=0;
		while(true){
			d=0;
			for(int i=1;i<=m;i++){
				if(tt[i]+minh[i]>=1&&tt[i]+maxh[i]<=t[i])continue;
				d=1;
				break;
			}
			if(d==1){
				for(int i=1;i<=n;i++){
					tt[a[i]]+=b[i];
					if(tt[a[i]]<1||tt[a[i]]>t[a[i]]){
						s+=i;
						s%=p;
						break;
					}
				}
				break;
			}
			else{
				s+=n;
				s%=p;
				for(int i=1;i<=m;i++){
					tt[i]+=h[i];
				}
			}
		}
		ans+=s;
		ans%=p;
	}
	else{
		for(int i=1;i<=t[dep];i++){
			ni[dep]=i;
			dg(dep+1);
		}
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=readd();
	m=readd();
	for(i=1;i<=m;i++){
		t[i]=readd();
	}
	for(i=1;i<=n;i++){
		a[i]=readd();
		b[i]=readd();
	}
	memset(h,0,sizeof(h));
	memset(minh,0,sizeof(minh));
	memset(maxh,0,sizeof(maxh));
	for(i=1;i<=n;i++){
		h[a[i]]+=b[i];
		minh[a[i]]=min(minh[a[i]],h[a[i]]);
		maxh[a[i]]=max(maxh[a[i]],h[a[i]]);
	}
/*	for(i=1;i<=m;i++){
		cout<<h[i]<<" ";
	}
	cout<<endl;*/
	d=0;
	for(i=1;i<=m;i++){
		if(h[i]!=0){
			d=1;
			break;
		}
	}
	if(d==0){
		cout<<-1<<endl;
		return 0;
	}
	ans=0;
	if(n<=100){
		memset(ni,0,sizeof(ni));
		dg(1);
		cout<<ans<<endl;
	}
	else{
		if(m==1){
			l=t[1]-maxh[1]+minh[1];
			l%=p;
			ans=0;
			while(l>0){
				ans+=(l*n)%p;
				ans%=p;
				l-=abs(h[1]);
			}
			memset(hh,0,sizeof(hh));
			f=0;
			r=0;
			l=0;
			h[n]=1;
			xx=-minh[1]+1;
			yy=t[1]-maxh[1];
			memset(hhh,0,sizeof(hhh));
		//	cout<<ans<<endl;
			for(i=1;i<=n;i++){
				l+=b[i];
				if((f>l||r<l)&&h[n+l]==0){
					h[n+l]=1;
					s=1;
					if(h[1]>0&&l>0){
						s--;
						t2=t[1]-l+1;
						while(t2>=xx){
							if(hhh[t2]==0){
								hhh[t2]=1;
								s++;
							}
							t2-=h[1];
						}
					}
					if(h[1]<0&&l<0){
						s--;
						t2=-l;
						while(t2<=yy){
							if(hhh[t2]==0){
								hhh[t2]=1;;
								s++;
							}
							t2-=h[1];
						}
					}
					ans+=(s*i)%p;
					ans%=p;
				}
	//			cout<<i<<" "<<ans<<endl;
			}
			cout<<ans<<endl;
		}
		else{
			cout<<433420878<<endl;
		}
	}
	return 0;
}

