#include<bits/stdc++.h>
using namespace std;
inline int read() {
	register int s=0,f=1;
    register char ch=getchar();
    while(!isdigit(ch)) {if(ch=='-') f=-f; ch=getchar();}
    while(isdigit(ch)) {s=(s<<3)+(s<<1)+(ch^48); ch=getchar();}
    return s*f;
}
const int N=100005;
const int mod=1e9+7;
int n,k,w[N],c[N],d[N],C[N];
int mac[N],mic[N];
long long ans;
map <int,int> mapp;
int walk1(int i1) {
	int j1=1e9,j2=1e9;
	
	if(mac[1]>0) j1=min(j1,(w[1]-i1)/mac[1]);
	if(mic[1]<0) j1=min(j1,(i1-1)/(abs(mic[1])));
	
	int x=j1;
	int sum=x*n;
	i1+=x*C[1];
	
	while(true) {
		for(int i=1;i<=n;i++) {
			sum++;
			i1+=d[i];
			if(i1>w[1] || i1<1) return sum;
		}
		return -1;
	}
}

int walk2(int i1,int i2) {
	int j1=1e9,j2=1e9;
	
	if(mac[1]>0) j1=min(j1,(w[1]-i1)/mac[1]);
	if(mic[1]<0) j1=min(j1,(i1-1)/(abs(mic[1])));
	
	if(mac[2]>0) j2=min(j2,(w[2]-i2)/mac[2]);
	if(mic[2]<0) j2=min(j2,(i2-1)/(abs(mic[2])));
	
	int x=min(j1,j2);
	int sum=x*n;
	i1+=x*C[1],i2+=x*C[2];
	while(true) {
		for(int i=1;i<=n;i++) {
			sum++;
			if(c[i]==1) {
				i1+=d[i];
				if(i1>w[1] || i1<1) return sum;
			}
			if(c[i]==2) {
				i2+=d[i];
				if(i2>w[2] || i2<1) return sum;
			}
		}
		return -1;
	}
}

int walk3(int i1,int i2,int i3) {
	int j1=1e9,j2=1e9,j3=1e9;
	
	if(mac[1]>0) j1=min(j1,(w[1]-i1)/mac[1]);
	if(mic[1]<0) j1=min(j1,(i1-1)/(abs(mic[1])));
	
	if(mac[2]>0) j2=min(j2,(w[2]-i2)/mac[2]);
	if(mic[2]<0) j2=min(j2,(i2-1)/(abs(mic[2])));
	
	if(mac[3]>0) j3=min(j3,(w[3]-i3)/mac[3]);
	if(mic[3]<0) j3=min(j3,(i3-1)/(abs(mic[3])));
	
	int x=min(j1,j2); x=min(x,j3);
	int sum=x*n;
	i1+=x*C[1],i2+=x*C[2],i3+=x*C[3];
	
	while(true) {
		for(int i=1;i<=n;i++) {
			sum++;
			if(c[i]==1) {
				i1+=d[i];
				if(i1>w[1] || i1<1) return sum;
			}
			if(c[i]==2) {
				i2+=d[i];
				if(i2>w[2] || i2<1) return sum;
			}
			if(c[i]==3) {
				i3+=d[i];
				if(i3>w[3] || i3<1) return sum;
			}
		}
		return -1;
	}
}

int walk4(int i1,int i2,int i3,int i4) {
	int j1=1e9,j2=1e9,j3=1e9,j4=1e9;
	
	if(mac[1]>0) j1=min(j1,(w[1]-i1)/mac[1]);
	if(mic[1]<0) j1=min(j1,(i1-1)/(abs(mic[1])));
	
	if(mac[2]>0) j2=min(j2,(w[2]-i2)/mac[2]);
	if(mic[2]<0) j2=min(j2,(i2-1)/(abs(mic[2])));
	
	if(mac[3]>0) j3=min(j3,(w[3]-i3)/mac[3]);
	if(mic[3]<0) j3=min(j3,(i3-1)/(abs(mic[3])));
	
	if(mac[4]>0) j4=min(j4,(w[4]-i4)/mac[4]);
	if(mic[4]<0) j4=min(j4,(i4-1)/(abs(mic[4])));
	
	int x=min(j1,j2); x=min(x,j3); x=min(x,j4);
	int sum=x*n;
	i1+=x*C[1],i2+=x*C[2],i3+=x*C[3],i4+=x*C[4];
	
	while(true) {
		for(int i=1;i<=n;i++) {
			sum++;
			if(c[i]==1) {
				i1+=d[i];
				if(i1>w[1] || i1<1) return sum;
			}
			if(c[i]==2) {
				i2+=d[i];
				if(i2>w[2] || i2<1) return sum;
			}
			if(c[i]==3) {
				i3+=d[i];
				if(i3>w[3] || i3<1) return sum;
			}
			if(c[i]==4) {
				i4+=d[i];
				if(i4>w[4] || i4<1) return sum;
			}
		}
		return -1;
	}
}

int walk5(int i1,int i2,int i3,int i4,int i5) {
	int j1=1e9,j2=1e9,j3=1e9,j4=1e9,j5=1e9;
	
	if(mac[1]>0) j1=min(j1,(w[1]-i1)/mac[1]);
	if(mic[1]<0) j1=min(j1,(i1-1)/(abs(mic[1])));
	
	if(mac[2]>0) j2=min(j2,(w[2]-i2)/mac[2]);
	if(mic[2]<0) j2=min(j2,(i2-1)/(abs(mic[2])));
	
	if(mac[3]>0) j3=min(j3,(w[3]-i3)/mac[3]);
	if(mic[3]<0) j3=min(j3,(i3-1)/(abs(mic[3])));
	
	if(mac[4]>0) j4=min(j4,(w[4]-i4)/mac[4]);
	if(mic[4]<0) j4=min(j4,(i4-1)/(abs(mic[4])));
	
	if(mac[5]>0) j5=min(j5,(w[5]-i5)/mac[5]);
	if(mic[5]<0) j5=min(j5,(i5-1)/(abs(mic[5])));
	
	int x=min(j1,j2); x=min(x,j3); x=min(x,j4); x=min(x,j5);
	int sum=x*n;
	i1+=x*C[1],i2+=x*C[2],i3+=x*C[3],i4+=x*C[4],i5+=x*C[5];
	
	while(true) {
		for(int i=1;i<=n;i++) {
			sum++;
			if(c[i]==1) {
				i1+=d[i];
				if(i1>w[1] || i1<1) return sum;
			}
			if(c[i]==2) {
				i2+=d[i];
				if(i2>w[2] || i2<1) return sum;
			}
			if(c[i]==3) {
				i3+=d[i];
				if(i3>w[3] || i3<1) return sum;
			}
			if(c[i]==4) {
				i4+=d[i];
				if(i4>w[4] || i4<1) return sum;
			}
			if(c[i]==5) {
				i5+=d[i];
				if(i5>w[5] || i5<1) return sum;
			}
		}
		return -1;
	}
}

void solve() {
	if(k==1) {
		for(int i=1;i<=w[1];i++) {
			ans+=walk1(i);
			if(walk1(i)==-1) {
				cout<<-1<<endl;
				exit(0);
			}
		}
	}
	if(k==2) {
		for(int i1=1;i1<=w[1];i1++) {
			for(int i2=1;i2<=w[2];i2++) {
				ans+=walk2(i1,i2);
				if(walk2(i1,i2)==-1) {
					cout<<-1<<endl;
					exit(0);
				}
			}
		}
	}
	if(k==3) {
		for(int i1=1;i1<=w[1];i1++) {
			for(int i2=1;i2<=w[2];i2++) {
				for(int i3=1;i3<=w[3];i3++) {
					ans+=walk3(i1,i2,i3);
					if(walk3(i1,i2,i3)==-1) {
						cout<<-1<<endl;
					    exit(0);
					}
				}
			}
		}
	}
	if(k==4) {
		for(int i1=1;i1<=w[1];i1++) {
			for(int i2=1;i2<=w[2];i2++) {
				for(int i3=1;i3<=w[3];i3++) {
					for(int i4=1;i4<=w[4];i4++) {
						ans+=walk4(i1,i2,i3,i4);
						if(walk4(i1,i2,i3,i4==-1)) {
							cout<<-1<<endl;
							exit(0);
						}
					}
				}
			}
		}
	}
	if(k==5) {
		for(int i1=1;i1<=w[1];i1++) {
			for(int i2=1;i2<=w[2];i2++) {
				for(int i3=1;i3<=w[3];i3++) {
					for(int i4=1;i4<=w[4];i4++) {
						for(int i5=1;i5<=w[5];i5++) {
							ans+=walk5(i1,i2,i3,i4,i5);
							if(walk5(i1,i2,i3,i4,i5)==-1) {
								cout<<-1<<endl;
								exit(0);
							}
						}
					}
				}
			}
		}
	}
}
int main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=k;i++) w[i]=read();
	for(int i=1;i<=n;i++) {
		c[i]=read(),d[i]=read();
		C[c[i]]+=d[i];
		mac[c[i]]=max(mac[c[i]],C[c[i]]);
		mic[c[i]]=min(mic[c[i]],C[c[i]]);
	}
	solve();
	cout<<ans%mod<<endl;
	return 0;
}
/*
3 2
3 3
1 1
2 -1
1 1

10 5 
65 23 19 7 8
1 1
2 1
3 1
4 1
5 1
1 -1
2 -1
3 -1
4 -1
5 -1
*/
