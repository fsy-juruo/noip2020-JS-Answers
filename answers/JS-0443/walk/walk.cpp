#include<bits/stdc++.h>
using namespace std;
int o,x;
int w[15];
int c[105],d[105];
long long ans;
int main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&o,&x);
	for(int i=1; i<=x; ++i) {
		scanf("%d",&w[i]);
	}
	for(int i=1; i<=o; ++i) {
		scanf("%d%d",&c[i],&d[i]);
	}
	if(x==1) {

	} else if(x==2) {
		for(int i=1; i<=w[1]; ++i)
			for(int j=1; j<=w[2]; ++j) {
				int a=i,b=j;
				while(1) {
					bool flag=false;
					for(int n=i; n<=o; ++n) {
						if(c[n]==1) {
							if(a+d[n]>0&&a+d[n]<=w[1]) {
								a+=d[n];
								ans++;
							} else {
								ans++;
								flag=true;
								break;
							}
						}
						if(c[n]==2) {
							if(b+d[n]>0&&a+d[n]<=w[2]) {
								b+=d[n];
								ans++;
							} else {
								ans++;
								flag=true;
								break;
							}
						}
					}
					if(flag) {
						cout<<ans<<endl;
						break;
					}
					if(a==i&&b==j) {
						printf("-1");
						exit(0);
					}
					ans%=1000000007;
				}

			}
		printf("%d",ans);
	} else if(x==3) {
		for(int i=1; i<=w[1]; ++i)
			for(int j=1; j<=w[2]; ++j)
				for(int k=1; k<=w[3]; ++k) {
					int a=i,b=j,e=k;
					while(1) {
						bool flag=false;
						for(int n=i; n<=o; ++n) {
							if(c[n]==1) {
								if(a+d[n]>0&&a+d[n]<=w[1]) {
									a+=d[n];
									ans++;
								} else {
									ans++;
									flag=true;
									break;
								}
							}
							if(c[n]==2) {
								if(b+d[n]>0&&a+d[n]<=w[2]) {
									b+=d[n];
									ans++;
								} else {
									ans++;
									flag=true;
									break;
								}
							}
							if(c[n]==3) {
								if(e+d[n]>0&&e+d[n]<=w[3]) {
									e+=d[n];
									ans++;
								} else {
									ans++;
									flag=true;
									break;
								}
							}
						}
						if(flag) {
							cout<<ans<<endl;
							break;
						}
						if(a==i&&b==j&&e==k) {
							printf("-1");
							exit(0);
						}
						ans%=1000000007;
					}

				}
		printf("%d",ans);
	} else if(x==4) {
		for(int i=1; i<=w[1]; ++i)
			for(int j=1; j<=w[2]; ++j)
				for(int k=1; k<=w[3]; ++k)
					for(int l=1; l<=w[4]; ++l) {
						int a=i,b=j,e=k,f=l;
						while(1) {
							bool flag=false;
							for(int n=i; n<=o; ++n) {
								if(c[n]==1) {
									if(a+d[n]>0&&a+d[n]<=w[1]) {
										a+=d[n];
										ans++;
									} else {
										ans++;
										flag=true;
										break;
									}
								}
								if(c[n]==2) {
									if(b+d[n]>0&&a+d[n]<=w[2]) {
										b+=d[n];
										ans++;
									} else {
										ans++;
										flag=true;
										break;
									}
								}
								if(c[n]==3) {
									if(e+d[n]>0&&e+d[n]<=w[3]) {
										e+=d[n];
										ans++;
									} else {
										ans++;
										flag=true;
										break;
									}
								}
								if(c[n]==4) {
									if(f+d[n]>0&&f+d[n]<=w[4]) {
										f+=d[n];
										ans++;
									} else {
										ans++;
										flag=true;
										break;
									}
								}
							}
							if(flag) {
								cout<<ans<<endl;
								break;
							}
							if(a==i&&b==j&&e==k&&f==l) {
								printf("-1");
								exit(0);
							}
							ans%=1000000007;
						}

					}
		printf("%d",ans);
	} else if(x==5) {
		for(int i=1; i<=w[1]; ++i)
			for(int j=1; j<=w[2]; ++j)
				for(int k=1; k<=w[3]; ++k)
					for(int l=1; l<=w[4]; ++l)
						for(int m=1; m<=w[5]; ++k) {
							int a=i,b=j,e=k,f=l,g=m;
							while(1) {
                                bool flag=false;
								for(int n=i; n<=o; ++n) {
									if(c[n]==1) {
										if(a+d[n]>0&&a+d[n]<=w[1]) {
											a+=d[n];
											ans++;
										} else {
											ans++;
											flag=true;
											break;
										}
									}
									if(c[n]==2) {
										if(b+d[n]>0&&a+d[n]<=w[2]) {
											b+=d[n];
											ans++;
										} else {
											ans++;
											flag=true;
											break;
										}
									}
									if(c[n]==3) {
										if(e+d[n]>0&&e+d[n]<=w[3]) {
											e+=d[n];
											ans++;
										} else {
											ans++;
											flag=true;
											break;
										}
									}
									if(c[n]==4) {
										if(f+d[n]>0&&f+d[n]<=w[4]) {
											f+=d[n];
											ans++;
										} else {
											ans++;
											flag=true;
											break;
										}
									}
									if(c[n]==5) {
										if(g+d[n]>0&&g+d[n]<=w[5]) {
											f+=d[n];
											ans++;
										} else {
											ans++;
											flag=true;
											break;
										}
									}
								}
								if(a==i&&b==j&&e==k&&f==l&&g==m) {
									printf("-1");
									exit(0);
								}
								ans%=1000000007;
							}
						}
	}
	printf("%d",ans);
	return 0;
}
