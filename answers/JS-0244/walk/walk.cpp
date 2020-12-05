#include<bits/stdc++.h>
using namespace std;
int n,k,w[15],a[15],c[10001],d[10001],i[20],x,y,oo,www,wwww,z;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i]>>d[i];
	}
	if(k==2){
		for(i[1]=1;i[1]<=w[1];i[1]++){
			for(i[2]=1;i[2]<=w[2];i[2]++){
				x=i[1];
				y=i[2];
				int mm=1;
				while(x>0&&x<=w[1]&&y>0&&y<=w[2]){
					oo++;
					if(c[mm]==1){
						x+=d[mm];
					}else{
						y+=d[mm];
					}
					mm++;
					if(mm>n)mm=1;
				}
			}
		}
		cout<<oo;
		return 0;
	}else if(k==1){
		for(i[1]=1;i[1]<=w[1];i[1]++){
			x=i[1];
			int mm=1;
			while(x>0&&x<=w[1]){
				oo++;
				x+=d[mm];
				mm++;
				if(mm>n)mm=1;
			}
		}
		cout<<oo;
		return 0;
	}else if(k==3){
		for(i[1]=1;i[1]<=w[1];i[1]++){
			for(i[2]=1;i[2]<=w[2];i[2]++){
				for(i[3]=1;i[3]<=w[3];i[3]++){
				x=i[1];
				y=i[2];
				z=i[3];
				int mm=1;
					while(x>0&&x<=w[1]&&y>0&&y<=w[2]&&z>0&&z<=w[3]){
						oo++;
						if(c[mm]==1){
							x+=d[mm];
						}else if(c[mm]==2){
							y+=d[mm];
						}else{
							z+=d[mm];
						}
						mm++;
						if(mm>n)mm=1;
					}
				}	
			}	
		}
		cout<<oo;
		return 0;
	}else if(k==4){
		for(i[1]=1;i[1]<=w[1];i[1]++){
			for(i[2]=1;i[2]<=w[2];i[2]++){
				for(i[3]=1;i[3]<=w[3];i[3]++){
					for(i[4]=1;i[4]<=w[4];i[4]++){
						x=i[1];
						y=i[2];
						z=i[3];
						www=i[4];
						int mm=1;
						while(x>0&&x<=w[1]&&y>0&&y<=w[2]&&z>0&&z<=w[3]&&www>0&&www<=w[4]){
							oo++;
							if(c[mm]==1){
								x+=d[mm];
							}else if(c[mm]==2){
								y+=d[mm];
							}else if(c[mm]==3){
								z+=d[mm];
							}else{
								www+=d[mm];
							}
							mm++;
							if(mm>n)mm=1;
						}	
					}
				}
			}
		}
		cout<<oo;
		return 0;
	}else if(k==5){
		for(i[1]=1;i[1]<=w[1];i[1]++){
			for(i[2]=1;i[2]<=w[2];i[2]++){
				for(i[3]=1;i[3]<=w[3];i[3]++){
					for(i[4]=1;i[4]<=w[4];i[4]++){
						for(i[5]=1;i[5]<=w[5];i[5]++){
							x=i[1];
							y=i[2];
							z=i[3];
							www=i[4];
							wwww=i[5];
							int mm=1;
							while(x>0&&x<=w[1]&&y>0&&y<=w[2]&&z>0&&z<=w[3]&&www>0&&www<=w[4]&&wwww>0&&wwww<=w[5]){
								oo++;
								if(c[mm]==1){
									x+=d[mm];
								}else if(c[mm]==2){
									y+=d[mm];
								}else if(c[mm]==3){
									z+=d[mm];
								}else if(c[mm]==4){
									www+=d[mm];
								}else{
									wwww+=d[mm];
								}
								mm++;
								if(mm>n)mm=1;
							}
						}
					}
				}
				
			}
		}
		cout<<oo;
		return 0;
	}
	return 0;
}
