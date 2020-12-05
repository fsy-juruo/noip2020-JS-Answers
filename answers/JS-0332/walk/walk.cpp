#include<bits/stdc++.h>
using namespace std;
int n,k;
int k1,k2,k3,k4,k5;
struct node{
	int c,d;
};
node q[100500];
int sum[100500];
int work1(int x){
	int num=1;
	int cnt=0;
	while(x>0&&x<=k1){
		cnt++;
		cnt=cnt%1000000007;
		int xx=q[num].c,dd=q[num].d;
		if(xx==1)
			x+=dd;
		if(num==n)
			num=1;
		else
			num++;
	}
	return cnt;
}
int work2(int x,int y){
	int num=1;
	int cnt=0;
	while(x>0&&y>0&&x<=k1&&y<=k2){
		cnt++;
		cnt=cnt%1000000007;
		int xx=q[num].c,dd=q[num].d;
		if(xx==1)
			x+=dd;
		if(xx==2)
			y+=dd;
		if(num==n)
			num=1;
		else
			num++;
	}
	return cnt;
}
int work3(int x,int y,int z){
	int num=1;
	int cnt=0;
	while(x>0&&y>0&&z>0&&x<=k1&&y<=k2&&z<=k3){
		cnt++;
		cnt=cnt%1000000007;
		int xx=q[num].c,dd=q[num].d;
		if(xx==1)
			x+=dd;
		if(xx==2)
			y+=dd;
		if(xx==3)
			z+=dd;
		if(num==n)
			num=1;
		else
			num++;
	}
	return cnt;
}
int work4(int x,int y,int z,int g){
	int num=1;
	int cnt=0;
	while(x>0&&y>0&&z>0&&g>0&&x<=k1&&y<=k2&&z<=k3&&g<=k4){
		cnt++;
		cnt=cnt%1000000007;
		int xx=q[num].c,dd=q[num].d;
		if(xx==1)
			x+=dd;
		if(xx==2)
			y+=dd;
		if(xx==3)
			z+=dd;
		if(xx==4)
			g+=dd;
		if(num==n)
			num=1;
		else
			num++;
	}
	return cnt;
}
int work5(int x,int y,int z,int g,int e){
	int num=1;
	int cnt=0;
	while(x>0&&y>0&&z>0&&g>0&&e>0&&x<=k1&&y<=k2&&z<=k3&&g<=k4&&e<=k5){
		cnt++;
		cnt=cnt%1000000007;
		int xx=q[num].c,dd=q[num].d;
		if(xx==1)
			x+=dd;
		if(xx==2)
			y+=dd;
		if(xx==3)
			z+=dd;
		if(xx==4)
			g+=dd;
		if(xx==5)
			e+=dd;
		if(num==n)
			num=1;
		else
			num++;
	}
	return cnt;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	int ans=0;
	if(k==1){
		cin>>k1;
		for(int i=1;i<=n;i++){
			cin>>q[i].c>>q[i].d;
			sum[i]=sum[i-1]+q[i].d;	
		}
		for(int i=1;i<=k1;i++){
			ans=(work1(i)+ans)%1000000007;
		}			
	}
	if(k==2){
		cin>>k1>>k2;
		for(int i=1;i<=n;i++)
			cin>>q[i].c>>q[i].d;
		for(int i=1;i<=k1;i++){
			for(int j=1;j<=k2;j++){
				ans=(work2(i,j)+ans)%1000000007;
			}
		}			
	}
	if(k==3){
		cin>>k1>>k2>>k3;
		for(int i=1;i<=n;i++)
			cin>>q[i].c>>q[i].d;
		for(int i=1;i<=k1;i++){
			for(int j=1;j<=k2;j++){
				for(int w=1;w<=k3;w++)
					ans=(work3(i,j,w)+ans)%1000000007;
			}
		}	
	}
	if(k==4){
		cin>>k1>>k2>>k3>>k4;
		for(int i=1;i<=n;i++)
			cin>>q[i].c>>q[i].d;
		for(int i=1;i<=k1;i++){
			for(int j=1;j<=k2;j++){
				for(int w=1;w<=k3;w++)
					for(int gg=1;gg<=k4;gg++)
						ans=(work4(i,j,w,gg)+ans)%1000000007;
			}
		}	
	}
	if(k==5){
		cin>>k1>>k2>>k3>>k4>>k5;
		for(int i=1;i<=n;i++)
			cin>>q[i].c>>q[i].d;
		for(int i=1;i<=k1;i++){
			for(int j=1;j<=k2;j++){
				for(int w=1;w<=k3;w++)
					for(int gg=1;gg<=k4;gg++)
						for(int ee=1;ee<=k5;ee++)
							ans=(work5(i,j,w,gg,ee)+ans)%1000000007;
			}
		}	
	}
	cout<<ans<<endl;
	return 0;
}
