
#include <stdio.h>
#include<string.h>
#define N 1000
//int G[N][N]={{0,1,0},
//			 {0,0,0},
//			 {0,1,0}};
			 
//int GL[N][N];

int matT[N][N];
int matAdj[N][N];
int P=0;
int T;
int posnum[N],visit[N];
int nump=0;
            


void DFS(int v)
{
    	printf("Dentro do DFS\nP=%d\n",P);
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

int verificaLugarNaMatriz(char string[11],int q,char matNomes[N][11])
{
	printf("String=%s\n",string);
	for(int i=0;i<q;i++)
	{
		printf("%d vez que entrou!\n",i);
		if(strcmp(string,matNomes[i])==0) return i;
	}
	return 1001;	
}

int main() {
	int i,j;
	int cont=0;
	scanf("%d %d",&P,&T);
	char matNomes[P][11];
	char string1[11],string2[11];
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
		printf("P=%d\n",P);

	setbuf(stdin,NULL);			
	for(count=0;count<P;count++)
	{
		printf("Digite uma string:\n");
		gets(matNomes[count]);
			setbuf(stdin,NULL);
	}
/*	printf("Strings digitadas.\n");
	for(i=0;i<P;i++)
		printf("%s, posicao %d\n",matNomes[i],i);
*/
	setbuf(stdin,NULL);
	for(i=0;i<T;i++)
	{
		gets(string1);
		setbuf(stdin,NULL);	
		gets(string2);
		setbuf(stdin,NULL);	
		
		if(strcmp(string1,string2)){
			
			int a = verificaLugarNaMatriz(string1,P,matNomes);
			printf("String1=%s\nLugar na matriz=%d",string1,a);
			int b = verificaLugarNaMatriz(string2,P,matNomes);
			printf("String2=%s\nLugar na matriz=%d",string2,b);
			matAdj[a][b]=1;
		}
		strcpy(string1,"");
		strcpy(string2,"");

	}
	DFS(0);
	printf("\nposnum!\n");
	for(i=0;i<P;i++) printf("%d\t",posnum[i]);

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
		
		printf("Cont:%d",cont);	
	  return 0;
}





