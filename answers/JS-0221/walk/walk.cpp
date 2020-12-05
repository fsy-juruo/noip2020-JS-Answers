#include<bits/stdc++.h>
using namespace std;
void read(int &sum){
	sum=0;char ch=getchar();int p=1;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')p=-1;
	for(; isdigit(ch);ch=getchar())sum=sum*10+ch-48;
	sum*=p;
}
const int mo=1000000007;
void write(int sum){
	if(sum<0){
		putchar('-');
		sum=0-sum;
	}
	if(sum>9){
		write(sum/10);
		sum%=10;
	}
	putchar(sum+48);
}
void writek(int sum){
	write(sum);
	putchar(' ');
}
void writeln(int sum){
	write(sum);
	putchar('\n');
}
int wid[20],zt[20],W,w[20],ans,n,c[500010],d[500010];
//bool check(){
//	int i;
//	for(i=1;i<=W;i++){
//		if(zt[i]>w[i]||zt[i]<1){
//			return false;
//		}
//	}
//	return true;
//}
void work(){
	int i=0,j;
	for(i=1;i<=W;i++){
		zt[i]=wid[i];
	}
	i=0;
	while(true){
		ans++;
		if(ans>=mo){
			ans-=mo;
		}
		i++;
		if(i>n){
			i-=n;
		}
		zt[c[i]]+=d[i];
		if(zt[c[i]]>w[c[i]]||zt[c[i]]<1){
			break;
		}
	}
//	ans--;
//	if(ans<0){
//		ans+=mo;
//	}
}
void dfs(int dep){
	if(dep>W){
		work();
//		int i;
		
//		cout<<ans<<endl;
		return ;
	}
	int i;
//	for(i=1;i<=W;i++){
//			cout<<wid[i]<<' ';
//		}
//		cout<<endl;
//	
	for(i=1;i<=w[dep];i++){
		wid[dep]=i;
		dfs(dep+1);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(n);read(W);
	int nn=n,nnn=0,ww=W,www=0;
	while(nn){
		nn/=10;
		nnn++;
	}	
	nnn--;
	int i;
	for(i=1;i<=W;i++){
		read(w[i]);
		ww=max(ww,w[i]);
	}
	for(i=1;i<=n;i++){
		read(c[i]);read(d[i]);
	}
	while(ww){
		ww/=10;
		www++;
	}
	www--;
	if(nnn+www*W>7){
		cout<<-1<<endl;
		return 0;
	}
	dfs(1);
	writeln(ans);
	return 0;
}

