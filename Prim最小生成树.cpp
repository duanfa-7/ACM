void Prim(){
	int i,j,k,tmp,ans;
	for(i=1;i<=n;i++)
	dis[i]=inf;//��ʼ�� 
	dis[1]=0;
	for(i=1;i<=n;i++){
		tmp=inf;
		for(j=1;j<=n;j++){
			if(!vis[j]&&tmp>dis[j]){
				tmp=dis[j];
				k=j;
			}//�ҳ���С����Ľڵ� 
		}
		vis[k]=1;//�ѷ��ʵĽڵ������
		for(j=1;j<=n;j++){
			if(!vis[j]&&dis[j]>map[k][j])
			dis[j]=map[k][j];//������̾��� 
		}
	}
}

