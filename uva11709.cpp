#include <stdio.h>
#include<string.h>
#define N 1000

int matT[N][N];
int matAdj[N][N];
int P=0;
int T;
int posnum[N],visit[N];
int nump=0;
            


void DFS(int v)
{
visit[v]=1;
int i;
for (i=0;i<P;i++)
   if (matAdj[v][i] && visit[i]==0)
      DFS(i);
nump++;
posnum[v] = nump;
}


void DFS2(int v)
{
visit[v]=2;
int i;
for (i=0;i<P;i++)
   if (matT[v][i] && visit[i]==1)
      DFS2(i);
}

int verificaLugarNaMatriz(char string[20],int q,char matNomes[N][20])
{

	for(int i=0;i<q;i++)
	{

		if(strcmp(string,matNomes[i])==0) return i;
	}
	return 1001;	
}

int main() {
	int i,j;

	scanf("%d %d",&P,&T);
	while(P!=0 && T!=0)
    {
        int cont=0;
        char matNomes[P][20];
    	char string1[20],string2[20];
    	int count,inicial;
    	for(i=0;i<P;i++)
    	{
    		strcpy(matNomes[i],"");
    		posnum[i]=0;
    		visit[i]=0;			//Zera matriz adjacências
    		for(j=0;j<N;j++)
    		{
    			matT[i][j]=0;
    			matAdj[i][j]=0;
    		}	
    	}
    
    
    	setbuf(stdin,NULL);			
    	for(count=0;count<P;count++)
    	{
    		fgets(matNomes[count],20,stdin);
    			setbuf(stdin,NULL);
    	}
    /*	printf("Strings digitadas.\n");
    	for(i=0;i<P;i++)
    		printf("%s, posicao %d\n",matNomes[i],i);
    */
    	setbuf(stdin,NULL);
    	for(i=0;i<T;i++)
    	{
    		fgets(string1,20,stdin);
    		setbuf(stdin,NULL);	
    		fgets(string2,20,stdin);
    		setbuf(stdin,NULL);	
    		
    		if(strcmp(string1,string2)){
    			
    			int a = verificaLugarNaMatriz(string1,P,matNomes);
    			int b = verificaLugarNaMatriz(string2,P,matNomes);
    
    			matAdj[a][b]=1;
    			if(i==0) inicial=a;
    		}
    		strcpy(string1,"");
    		strcpy(string2,"");
    
    	}
    	DFS(inicial);
    
    	for (i=0;i<P;i++)					//Cria matriz transposta
    	   for (j=0;j<P;j++)
    	      matT[i][j]=matAdj[j][i];
    	      
    	while (1)
    	   {
    	   int maior=-1,pm=0;
    	   for (i=0;i<P;i++)
    	     if (posnum[i]>maior && visit[i]==1)
    	        {
    	        maior=posnum[i];
    			pm=i;	
    			}
    	   if (maior==-1) break;
    	   DFS2(pm);
    	   for (i=0;i<P;i++)
    	      if (visit[i]==2)
    	         {
    	       //  printf("%d ",i+1);
    	         visit[i]=3;
    			 }
    	   //printf("\n");
    	   cont++;
    	   }
    	   for(i=0;i<P;i++) 
    			if(visit[i]==0) cont++;
    		
    		printf("%d\n",cont);	
    	  
    
        scanf("%d %d",&P,&T);
    }
    return 0;
}





