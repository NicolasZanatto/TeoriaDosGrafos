#include<stdio.h>
#define MAX 1000
int main()
{
	int i,j,a,b,N,k;
//	int mat[110][110];
	int custo[110][110];
	float cont=0;
	int vertMaior=0;
	float contdenom=0;
	int contCase=1;
	
    while(1)
	{
	    cont=0;
    	vertMaior=0;
	    contdenom=0;
	
	for(i=1;i<=100;i++)
		for(j=1;j<=100;j++)
		{
		 //   mat[i][j]=0;
			custo[i][j]=0;
		}
		
    	scanf("%d %d",&a,&b);
    	if(a==0 && b==0) break;
    	while(a!=0 && b!=0)				//adiciona os valores a matriz padrao
    	{
    		custo[a][b]=1;
    		if(a>b)
    		{
    			if(a>vertMaior) vertMaior=a;
    		}
    		else{
    			if(b>vertMaior) vertMaior=b;
    		}
    		
    		scanf("%d %d",&a,&b);
    	}
    	
    	
   	for(i=1;i<=vertMaior;i++)		//Adiciona os valores ao custo;
    	{
    		for(j=1;j<=vertMaior;j++)
    		{
    		    if(custo[i][j]==0) custo[i][j]=1000;
    		//    else custo[i][j]=mat[i][j];
    		}
    	}
    	
    	
    	for(k=1;k<=vertMaior;k++){
    		for(i=1;i<=vertMaior;i++){
    			for(j=1;j<=vertMaior;j++){
    				if(custo[i][j] > custo[i][k] + custo[k][j] )  custo[i][j]= custo[i][k] + custo[k][j];
    			}
    		}
    	}
    	
    

    	for(i=1;i<=vertMaior;i++)
    	{
    	    for(j=1;j<=vertMaior;j++)
    	    {
    	        if(i==j)
    	        {
    	            custo[i][j]=0;
    	        }
    	        else
    	        {
    	            if(custo[i][j]!=1000)
    	            {
    	                contdenom++;
    	                cont+=custo[i][j];
    	            }
    	                
    	        }
    	            
    	 }

    	}
    	
    	for(i=1;i<=vertMaior;i++)
    	{
    	    printf("\n");
    	    for(j=1;j<=vertMaior;j++)
    	        printf("%d\t",custo[i][j]);
    	}
    	float resultado = cont/contdenom;
    	    printf("Cont=%f\ncontDenom=%f\n",cont,contdenom);
    		printf("Case %d: average length between pages = %.3f clicks\n",contCase++,resultado);
	}
	return 0;
}
