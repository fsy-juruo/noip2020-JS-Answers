#include<bits/stdc++.h>
using namespace std;

int t,n,len;
long long ans=0;
string s;
int num[150010][50],h[150010],ned[110],a[150010],od1[150010],od2[150010];

int read(){
	int x=0,f=1; char ch;
	while (ch>'9'||ch<'0'){
		  if (ch=='-') f=-1;
		  ch=getchar();
	}
	while (ch>='0'&&ch<='9'){
		  x=(x<<3)+(x<<1)+ch-'0';
		  ch=getchar();
	}
	return x*f;
}

bool check(int l,int r){
int odd1=0,odd2=0;
	for (int i=1;i<=n;i++){
		if (num[l][ned[i]]%2==1) odd1++;
		if ((num[len][ned[i]]-num[r][ned[i]])%2==1) odd2++;
	}
	if (odd1<=odd2) return 1; else return 0;	
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	t=read();
	for (int k=1;k<=t;k++){
		cin>>s;
		ans=0;
		len=s.length();
		for (int i=1;i<=len;i++){
			a[i]=s[i-1]-'a'+1; h[a[i]]=1; 
			for (int j=1;j<=26;j++) num[i][j]=num[i-1][j];
			num[i][a[i]]++;
		}
		n=0;
		for (int i=1;i<=26;i++){
			if (h[i]!=0) {n++; ned[n]=i;}
			h[i]=0;
		}
		for (int i=3;i<=(len+1)/2;i++){
			int fl=1,z=i,t=1;
			for (int j=1;j<i;j++)
				if (a[j]!=a[z]) {fl=0; break;} else z++;
			if (fl==1){
				t=2;
				while ((t+1)*(i-1)<len){
					fl=1; z=t*(i-1)+1;
					for (int j=1;j<i;j++)
						if (a[j]!=a[z]) {fl=0; break;} else z++;
					if (fl==0) break; else t++;
				}
				for (int j=1;j<i-1;j++){
					od1[j]=0;
					for (int l=1;l<=n;l++)
						if (num[j][ned[l]]%2==1) od1[j]++;	
				}
				for (int j=2;j<=t;j++){
					od2[j]=0;
					for (int l=1;l<=n;l++)
						if ((num[len][ned[l]]-num[j*(i-1)][ned[l]])%2==1) od2[j]++;
				}
				for (int j=1;j<i-1;j++)
				for (int l=2;l<=t;l++)
					if (od1[j]<=od2[l]) ans++;
			}
		}
		for (int i=1;i<len-1;i++)
		for (int j=i+1;j<len;j++)
			if (check(i,j)) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
