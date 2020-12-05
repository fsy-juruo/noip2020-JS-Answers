#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int w=1,s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return w*s;
}	
int a[25],b[25],h,n,m,f1,f2,j,c[25],s;
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read();
	m=read();
    for(int i=0;i<m;i++)a[i]=read();
    for(int i=0;i<m;i++)b[i]=read();
	for(int i=0;i<m;i++){
		if(a[i]!=a[0])f1=i;
		break;
	}
	for(int i=0;i<m;i++){
		if(b[i]!=b[0])f2=i;
		break;
	}
	printf("%d",4*m-2*f1-2*f2);
	for(int i=m-1;i>=f1;i--)printf("1 3\n"),c[h]=a[i],h++;
	for(j=m-1;h<m-1&&j>=f2;j--)	{
		if(b[j]=a[0])printf("2 3\n3 1\n");
	else printf("2 3\n"),c[h]=b[j],h++;
	}
 	if(j=f2-1){
 		s=h-1;
 		while(s>=0){
 			if(c[s]==a[0])printf("3 1\n");
 				if(c[s]==b[0])printf("3 2\n");
		 }

		 
	 }
	 if(h=m-1){
	 	if(b[j]==a[0])
        while(b[j]==a[0])printf("2 3\n3 1\n"),j--;
	 }
	return 0;
}
