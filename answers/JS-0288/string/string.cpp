#include<bits/stdc++.h>
using namespace std;
int nxt[2000200],a[2000200],jlc[30],f[2000200],jla[2000200];
int T,top,numc,numa,num,t,temp,js;
long long ans,sum;
char ch;
int read(){
	int s=0,w=1;char ch=getchar();
	while (ch<'0' || ch>'9'){
		if (ch=='-') w=-1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}
void bfs(){
	for (int i=1;i<=top;i++){
		nxt[i]=0;
	}
	for (int i=2,j=0;i<=top;i++){
		while (j!=0 && a[i]!=a[j+1]) j=nxt[j];
		if (a[i]==a[j+1]) j++;
		nxt[i]=j;
	}
	/*for (int i=1;i<=top;i++){
		printf("%d ",nxt[i]);
	}*/
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	T=read();
	while (T--){
		ch=getchar();
		top=0;
		while (ch>='a' && ch<='z'){
			a[++top]=ch-'a'+1;
			ch=getchar();
		}
		if (top<=2){
			puts("0");
			continue;
		}
		bfs();
		for (int i=1;i<=top;i++){
			if (i%(i-nxt[i])==0 && nxt[i]!=0){
				if (f[nxt[i]]==0) f[i]=nxt[i];
				else f[i]=f[nxt[i]];
			}
			else f[i]=i;
		}
		ans=0;
		for (int k=2;k<=top-1;k++){
			sum=0;
			for (int i=1;i<=26;i++) jlc[i]=0;
			numc=0;
			for (int i=k+1;i<=top;i++){
				jlc[a[i]]++;
			}
			for (int i=1;i<=26;i++){
				if (jlc[i]%2==1) numc++;
			}
			t=f[k];
			if (t==1){
				num=k;
				if (numc>=1){
					for (int i=2;i<=sqrt(num);i++){
						if (num%i==0){
							ans+=(i-1);
							if (i*i!=num) ans+=(num/i-1);
						}
					}
					ans+=(num-1);
					continue;
				}
				else {
					for (int i=2;i<=sqrt(num);i++){
						if (num%i==0){
							ans+=((i-1)/2);
							if (i*i!=num) ans+=((num/i-1)/2);
						}
					}
					ans+=((num-1)/2);
					continue;
				}
			}
			if (t!=k){
				temp=k/t;
				if (temp==2){
					for (int i=1;i<=t-1;i++){
						for (int j=1;j<=26;j++){
							jla[j]=0;
						}
						for (int j=1;j<=i;j++){
							jla[a[j]]++;
						}
						numa=0;
						for (int j=1;j<=26;j++){
							if (jla[j]%2==1) numa++;
						}
						if (numa<=numc) sum++;
					}
				}
				else {
					for (int z=2;z<=sqrt(temp);z++){
						if (temp%z==0){
							js=t*z;
							for (int i=1;i<=js-1;i++){
								for (int j=1;j<=26;j++){
									jla[j]=0;
								}
								for (int j=1;j<=i;j++){
									jla[a[j]]++;
								}
								numa=0;
								for (int j=1;j<=26;j++){
									if (jla[j]%2==1) numa++;
								}
								if (numa<=numc) sum++;
							}
							if (z*z!=temp){
								js=t*(temp/z);
								for (int i=1;i<=js-1;i++){
									for (int j=1;j<=26;j++){
										jla[j]=0;
									}
									for (int j=1;j<=i;j++){
										jla[a[j]]++;
									}
									numa=0;
									for (int j=1;j<=26;j++){
										if (jla[j]%2==1) numa++;
									}
									if (numa<=numc) sum++;
								}
							}
						}
					}
				}
			}
			for (int i=1;i<=k-1;i++){
				for (int j=1;j<=26;j++){
					jla[j]=0;
				}
				for (int j=1;j<=i;j++){
					jla[a[j]]++;
				}
				numa=0;
				for (int j=1;j<=26;j++){
					if (jla[j]%2==1) numa++;
				}
				if (numa<=numc) sum++;
			}
			ans+=sum;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//npq RP++;

