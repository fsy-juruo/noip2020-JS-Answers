#include<cstdio>
#include<iostream>
#include<cstring>
#define rep(i,j,k) for(i=j;i<=k;i++)
#define dep(i,j,k) for(i=j;i>=k;i--)
using namespace std;
string s;
int a[1048586],l,i,l2,l1,l3,lmt,ans,T,ch1[104],ch2[104],num1[1048586],num2[1048586];
void work(){
	int i=0,j=0,k=0;
	rep(i,1,l3-2)
		if (num1[i]<=lmt) ans++;
	if ((l3-1)%2!=0) return;
	else {
		rep(i,2,(l3-1)/2){
			if ((l3-1)%i==0)
			rep(k,1,i-1){
				rep(j,1,(l3-1)/i){
					if (a[j]!=a[j+k*(l3-1)/i]) return;
				}
			}
			rep(k,1,(l3-1)/i)
			if (num1[k]<=lmt) ans++;
		}
	}	
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T){
		T--;
		cin>>s;
		l=s.size();
		memset(a,0,sizeof(a));
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		memset(ch1,0,sizeof(ch1));
		memset(ch2,0,sizeof(ch2));
		ans=0;
		rep(i,0,l-1) a[i+1]=s[i]-'a'+1;
		rep(i,1,l){
			ch1[a[i]]++;
			if (ch1[a[i]]%2==1) num1[i]=num1[i-1]+1;
			else num1[i]=num1[i-1]-1;
		}
		dep(i,l,1){
			ch2[a[i]]++;
			if (ch2[a[i]]%2==1) num2[i]=num2[i+1]+1;
			else num2[i]=num2[i+1]-1;
		}
		dep(l3,l,3){
			lmt=num2[l3];
			work();
		}
		cout<<ans<<endl;
	}
}
/*
3
nnrnnr
zzzaab
mmlmmlo


5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab

*/
