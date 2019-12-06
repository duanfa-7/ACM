void Prim(){
	int i,j,k,tmp,ans;
	for(i=1;i<=n;i++)
	dis[i]=inf;//初始化 
	dis[1]=0;
	for(i=1;i<=n;i++){
		tmp=inf;
		for(j=1;j<=n;j++){
			if(!vis[j]&&tmp>dis[j]){
				tmp=dis[j];
				k=j;
			}//找出最小距离的节点 
		}
		vis[k]=1;//把访问的节点做标记
		for(j=1;j<=n;j++){
			if(!vis[j]&&dis[j]>map[k][j])
			dis[j]=map[k][j];//更新最短距离 
		}
	}
}

