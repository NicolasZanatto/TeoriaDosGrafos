
#include <stdio.h>

int main()
{
    
    	int m,n,x,y,z,i,j;
	
	scanf("%d %d",&m,&n);  // m - vértices / n - arestas
	while(m!=0 && n!=0)
	{
		int mat[m][m];
		int visitado[m],valor[m];
		int cont=0;
		
		for(i=0;i<m;i++)
			for(j=0;j<m;j++)
				mat[i][j]=-1;
				
		for(i=0;i<m;i++){              //Inicializa
	        visitado[i]=0;
	        valor[i]=2147483646;
	    }
		scanf("%d %d %d",&x,&y,&z);  //0 1 2 
		int inicial = x;
		visitado[inicial]=1;
		valor[inicial]=0;
		
		mat[x][y]=z;					
		mat[y][x]=z;
		cont+=z;
		for(i=0;i<n-1;i++)				//Inicializa Matriz
		{
			scanf("%d %d %d",&x,&y,&z);
			mat[x][y]=z;					
			mat[y][x]=z;
			cont+=z;
		}
		
		
		for(i=0;i<m;i++){                 //Verifica se há uma aresta entre esses vértices.
	        if(mat[inicial][i]!=-1) valor[i]=mat[inicial][i];
	    }
	
	    int ar=0;
	    int i;
	    while(ar<m-1){
	    	int Vmenor;
	        int menor=2147483647;    
	        for(i=0;i<m;i++){
	            if(valor[i]<menor && i!=inicial && visitado[i]==0){
	                menor=valor[i];
	                Vmenor=i;
	            }
	        
	        }
	        
	        visitado[Vmenor]=1;
	        ar++;
	    	
		    if(ar==m-1) break;     
	        for(i=0;i<m;i++)
	    	{
	            if(mat[Vmenor][i]!=-1 && visitado[i]==0 && mat[Vmenor][i]<valor[i])  //Atualiza valor e visitado
	            {
	
	                valor[i]=mat[Vmenor][i];
	
	            }
	        }
	    }
	    int contador=0;
	    for(j=0;j<m;j++) 
			contador+=valor[j];

		printf("%d",cont-contador);
		
		scanf("%d %d",&m,&n);
	}

    return (0);
}




