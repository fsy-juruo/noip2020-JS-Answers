#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,w[11],maxb[11],minb[11],dq[11],a[500001],b[500001],i,j,h[11],tf,ans,a1,a2,a3,a4,a5,maxw,qj[200001],dqqj;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d",&w[i]);
		maxw=max(maxw,w[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		dq[a[i]]+=b[i];
		maxb[a[i]]=max(dq[a[i]],maxb[a[i]]);
		minb[a[i]]=min(dq[a[i]],minb[a[i]]); 
	}
	tf=1;
	for(i=1;i<=n;i++)
	if(dq[i]!=0)tf=0;
	if(tf==1) for(i=1;i<=m;i++)
	if(maxb[i]-minb[i]<w[i]){
		tf=-1;
	}
	if(tf==-1){
		printf("-1\n");
		return 0;
	}
	if(n<=5){
		if(m==1){
			for(a1=1;a1<=w[1];a1++){
			j=1;
			h[1]=a1;
			h[1]+=b[1];
			ans++;
			while(h[1]>0&&h[1]<w[1]+1){
				j++;
				if(j>n)
				j=1;
				h[a[j]]+=b[j];
				ans++;
			}
		}
		printf("%d\n",ans);
		}
		if(m==2){
			for(a1=1;a1<=w[1];a1++)
			for(a2=1;a2<=w[2];a2++){
			j=1;
			h[1]=a1;
			h[2]=a2;
			h[a[1]]+=b[1];
			ans++;
			while(h[1]>0&&h[1]<w[1]+1&&h[2]>0&&h[2]<w[2]+1){
				j++;
				if(j>n)
				j=1;
				h[a[j]]+=b[j];
				ans++;
			}
//			printf("%d %d %d\n",a1,a2,ans);
		}
		printf("%d\n",ans);
		}
		if(m==3){
			for(a1=1;a1<=w[1];a1++)
			for(a2=1;a2<=w[2];a2++)
			for(a3=1;a3<=w[2];a3++){
			j=1;
			h[1]=a1;
			h[2]=a2;
			h[3]=a3;
			h[a[1]]+=b[1];
			ans++;
			while(h[1]>0&&h[1]<w[1]+1&&h[2]>0&&h[2]<w[2]+1&&h[3]>0&&h[3]<w[3]+1){
				j++;
				if(j>n)
				j=1;
				h[a[j]]+=b[j];
				ans++;
			}
		}
		printf("%d\n",ans);
		}
		if(m==4){
			for(a1=1;a1<=w[1];a1++)
			for(a2=1;a2<=w[2];a2++)
			for(a3=1;a3<=w[2];a3++)
			for(a4=1;a4<=w[2];a4++){
			j=1;
			h[1]=a1;
			h[2]=a2;
			h[3]=a3;
			h[4]=a4;
			h[a[1]]+=b[1];
			ans++;
			while(h[1]>0&&h[1]<w[1]+1&&h[2]>0&&h[2]<w[2]+1&&h[3]>0&&h[3]<w[3]+1&&h[4]>0&&h[4]<w[4]+1){
				j++;
				if(j>n)
					j=1;
				h[a[j]]+=b[j];
				ans++;
			}
		}
		printf("%d\n",ans);
		}
		if(m==5){
			for(a1=1;a1<=w[1];a1++)
			for(a2=1;a2<=w[2];a2++)
			for(a3=1;a3<=w[2];a3++)
			for(a4=1;a4<=w[2];a4++)
			for(a5=1;a5<=w[2];a5++){
			j=1;
			h[1]=a1;
			h[2]=a2;
			h[3]=a3;
			h[4]=a4;
			h[5]=a5;
			h[a[1]]+=b[1];
			ans++;
			while(h[1]>0&&h[1]<w[1]+1&&h[2]>0&&h[2]<w[2]+1&&h[3]>0&&h[3]<w[3]+1&&h[4]>0&&h[4]<w[4]+1&&h[5]>0&&h[5]<w[5]+1){
				j++;
				if(j>n)
				j=1;
				h[a[j]]+=b[j];
				ans++;
			}
		}
		printf("%d\n",ans);
		}
	}//n<=5
	else if(n<=100){
	if(m==1){
		for(a1=1;a1<=w[1];a1++){
			j=1;
			h[1]=a1;
			while(h[1]+minb[1]>=1&&h[1]+maxb[1]<=w[1]){
			ans+=n;
			h[1]+=dq[1];
		}
			h[1]+=b[1];
			ans++;
			while(h[1]>0&&h[1]<w[1]+1){
				j++;
				if(j>n)
				j=1;
				h[a[j]]+=b[j];
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	if(m==2){
		for(a1=1;a1<=w[1];a1++)
		for(a2=1;a2<=w[2];a2++){
			j=1;
			h[1]=a1;
			h[2]=a2;
			while(h[1]+minb[1]>=1&&h[1]+maxb[1]<=w[1]&&h[2]+minb[2]>=1&&h[2]+maxb[2]<=w[2]){
			ans+=n;
			h[1]+=dq[1];
			h[2]+=dq[2];
//			printf("h1=%d\n",h[1]);
		}
			h[a[1]]+=b[1];
			ans++;
			while(h[1]>0&&h[1]<w[1]+1){
				j++;
				if(j>n)
				j=1;
				h[a[j]]+=b[j];
				ans++;
	//			printf("h1=%d\n",h[1]);
			}
		}
		printf("%d\n",ans);
	}
	if(m==3){
		for(a1=1;a1<=w[1];a1++)
		for(a2=1;a2<=w[2];a2++)
		for(a3=1;a3<=w[3];a3++){
			j=1;
			h[1]=a1;
			h[2]=a2;
			h[3]=a3;
			while(h[1]+minb[1]>=1&&h[1]+maxb[1]<=w[1]&&h[2]+minb[2]>=1&&h[2]+maxb[2]<=w[2]&&h[3]+minb[3]>=1&&h[3]+maxb[3]<=w[3]){
			ans+=n;
			h[1]+=dq[1];
			h[2]+=dq[2];
			h[3]+=dq[3];
//			printf("h1=%d\n",h[1]);
		}
			h[a[1]]+=b[1];
			ans++;
			while(h[1]>0&&h[1]<w[1]+1){
				j++;
				if(j>n)
				j=1;
				h[a[j]]+=b[j];
				ans++;
	//			printf("h1=%d\n",h[1]);
			}
		}
		printf("%d\n",ans);
	}
	}
	else{
		printf("-1\n");
	}
	return 0;
}/*
dq:һ�����ڵ�ά�Ȳ�
maxb:���߽� 
minb:��С�߽� 
4 2
2 2
1 2
2 2
1 -2
2 -2
*/