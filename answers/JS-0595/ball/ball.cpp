#include<bits/stdc++.h>
using namespace std;
int a[55][405],top[55],ans1[1000005],ans2[1000005];
int p=0;
int find1(){
	int pos=1;
	while(a[1][pos]==1)pos++;
	return pos;
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	if(n!=2){
		printf("?????????");
		return 0;
	}
	for(int i=1;i<=n;i++){
		top[i]=m;
		for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
	}
	for(int t=0;t<m;t++){
		int pp;
		pp=find1();
		for(int i=m;i>=pp;i--){
			a[3][++top[3]]=a[1][top[1]--];
			ans1[++p]=1;
			ans2[p]=3;
		}
		for(int i=1;i<=m;i++){
			if(top[1]==m){
				a[3][++top[3]]=a[2][top[2]--];
				ans1[++p]=2;
				ans2[p]=3;
			}
			else if(top[3]==m){
				a[1][++top[1]]=a[2][top[2]--];
				ans1[++p]=2;
				ans2[p]=1;
			}
			else if(a[2][top[2]]==1){
				a[1][++top[1]]=a[2][top[2]--];
				ans1[++p]=2;
				ans2[p]=1;
			}
			else{
				a[3][++top[3]]=a[2][top[2]--];
				ans1[++p]=2;
				ans2[p]=3;
			}
		}
		for(int i=1;i<=m;i++){
			a[2][++top[2]]=a[3][top[3]--];
			ans1[++p]=3;
			ans2[p]=2;
		}
	}
	printf("%d\n",p);
	for(int i=1;i<=p;i++)printf("%d %d\n",ans1[i],ans2[i]); 
	return 0;
} 
