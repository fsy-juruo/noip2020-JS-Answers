#include<bits/stdc++.h>
using namespace std;
int a[10][30],r[30],b[90000][2];
int tot,n,m;
bool sol(int p,int q){
	int f1=a[p][1],tot1=m,tot2=m,tot3=0,f2=a[q][1];
	for (int i=1;i<=m;i++){
		if (a[p][i]!=f1){
			for (int j=m;j>=i;j--){
				tot1--,tot3++,r[tot3]=a[p][i];
			    tot++;
			    b[tot][1]=p;b[tot][2]=n+1;
			}
			break;
		}
	}
	for (int j=1;j<=m;j++){
		if (a[q][j]!=f2){
			for (int i=m;i>=j;i--){
		if (a[q][i]!=f1){
			tot2--,tot3++,r[tot3]=a[q][i];
			tot++;
			b[tot][1]=q;b[tot][2]=n+1;
			if (tot3>m) return 0;
		}
		if (a[q][i]==f1){
			tot2--,tot1++,a[p][tot1]=f1;
			tot++;
			b[tot][1]=q;b[tot][2]=p;
		}
	    }
		}
	}
	
	for (int i=tot3;i>=1;i--){
		if (r[i]==f1) {
			tot++;
			b[tot][1]=n+1;
			b[tot][2]=p;
		}
		else{
			tot++;
			b[tot][1]=n+1;
			b[tot][2]=q;
		}
	}
	return 1;
}
int main(){
	freopen("r","ball.in",stdin);
	freopen("w","ball.out",stdout);

    scanf("%d%d",&n,&m);
    if (n==1){
    	cout<<0<<endl;
    	return 0;
	}
	if (n==2){
		for (int i=1;i<=m;i++)
		   cin>>a[1][i];
	    for (int i=1;i<=m;i++)
	       cin>>a[2][i];
	    memset(b,0,sizeof(b));
	    tot=0;
		bool f=sol(1,2);
		if (f==0) tot=0,f=sol(2,1);
		cout<<tot<<endl;
		for (int i=1;i<=tot;i++)
		   printf("%d %d\n",b[i][1],b[i][2]);
	}

	return 0;
}

