//T2
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1100010
#define re register
#define dg() printf("AK IOI!!!");
#define out(x) printf("%d ",(x));
#define hh() printf("\n");
inline int Read() {
	int s=0,w=1; char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
int t,n,f[N],b[N];
int num[30];
ll ans;
string s;
void init() {
	f[0]=0; b[n-1]=0;
	memset(num,0,sizeof(num));
	for(int i=0;i<n;++i) {
		if(i!=0) f[i]=f[i-1];
		num[s[i]-'a']++;
		if(num[s[i]-'a']==2) f[i]--,num[s[i]-'a']-=2;
		else f[i]++;
	}
	memset(num,0,sizeof(num));
	for(int i=n-1;i>=0;--i) {
		if(i!=n-1) b[i]=b[i+1];
		num[s[i]-'a']++;
		if(num[s[i]-'a']==2) b[i]--,num[s[i]-'a']-=2;
		else b[i]++;
	}
}
ll Pow(int x,int k) {
	ll sum=1,xx=(ll)x; 
	while(k) {
		if(k & 1) sum*=xx;
		xx*=xx; k>>=1; 
	}
	return sum;          
}
int main() {
	freopen("string.in","r",stdin);          
	freopen("string.out","w",stdout);           
    t=Read();
    while(t) {
    	cin>>s;
    	n=s.size(); ans=0;
    	init();
    	for(int i=0;i<n-1;++i) {         // A right
    		for(int j=i+1;j<n-1;j++) {  //  B  right 
			    int k=1,len=j+1;
				while(1) {
					ll r=Pow(len,k);            
					if(r>n-1) break;   
					if(f[i]>b[r]) {
						k++; continue;
					}    
					bool flag=true;
					for(int x=1;x<k;x++) {
						for(int y=0;y<=j;y++) {
							if(s[y]!=s[y+x*(j+1)]) {
								flag=false; break;  
							}
						}
					} 
					if(flag) ans++;
					k++;   
				}                                  
    		}
		} 
		printf("%lld\n",ans);
    	t--;
	}
	return 0;
}
/*
3
nnrnnr
zzzaab
mmlmmlo
*/

/*
5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab
*/
