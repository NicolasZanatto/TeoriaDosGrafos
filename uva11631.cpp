
#include <stdio.h>

int main()
{
    
    	int m,n,x,y,z;
	
	scanf("%d %d",&m,&n);  // m - vértices / n - arestas
	int mat[m][m];
	int visitado[m],valor[m];
	int cont=0;
	
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			mat[i][j]=-1;
			
	for(int i=0;i<m;i++){              //Inicializa
        visitado[i]=0;
        valor[i]=1000000;
    }
	scanf("%d %d %d",&x,&y,&z);  //0 1 2 
	int inicial = x;
	visitado[inicial]=1;
	valor[inicial]=0;

	while(x!=0 || y!=0)				//Inicializa Matriz
	{
		mat[x][y]=z;					
		mat[y][x]=z;
		cont+=z;
		scanf("%d %d",&x,&y);    // 0 2 
		if(x==0 && y==0) break;
		scanf("%d",&z);  //6 
	}
	
	
	for(int i=0;i<m;i++){                 //Verifica se há uma aresta entre esses vértices.
        if(mat[inicial][i]!=-1) valor[i]=mat[inicial][i];
    }

    int ar=0;
    int i;
    while(ar<m-1){
    	int Vmenor;
        int menor=10000001;    
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
    for(int j=0;j<m;j++)
	 
		contador+=valor[j];
	




printf("%d",cont-contador);


    return 0;
}




