#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int isReflexive(int n, int matrix[][n])
{
        for(int i =0; i<n; i++)
        {
            if(matrix[i][i] != 1)
            {
                return 0; 
            } 
        } 

        return 1; 
}

void toReflexive(int n , int matrix[][n])
{
    for(int i =0; i<n; i++)
    {
        matrix[i][i] = 1; 
    } 

    for(int i = 0; i<n; i++)
    {
        for(int j =0; j<n ; j++)
        {
            printf("%d ", matrix[i][j]); 

        } 
        printf("\n");
    } 
} 

void toSymmetric(int n, int matrix[][n])
{
    for(int i = 0; i<n;i++)
    {
        for(int j =0; j<n; j++)
        {
            if(i!=j)
            {
                if(matrix[i][j] == 1)
                {
                    matrix[j][i] = 1; 
                }
            }
        }
    } 
    for(int i = 0; i<n; i++)
    {
        for(int j =0; j<n ; j++)
        {
            printf("%d ", matrix[i][j]); 

        } 
        printf("\n");
    }
}

int isNonirreflexive(int n, int matrix[][n])
{
    for(int i =0; i<n; i++)
    {
        if(matrix[i][i]==1)
        {
            return 1; 
        }
    } 

    return 0; 
} 

void toAllSymmetric(int n, int matrix[][n])
{
    for(int i =0; i<n; i++)
    {
        for(int j =0; j<n; j++)
        {
            if(i!=j)
            {
                matrix[i][j] = 1; 
            }
        }
    } 
    for(int i = 0; i<n; i++)
    {
        for(int j =0; j<n ; j++)
        {
            printf("%d ", matrix[i][j]); 

        } 
        printf("\n");
    }

}

int isSymmetric(int n, int matrix[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                return 0;
                break; 
            }
        }
    }
    return 1;
}

int isTransitive(int n,int matrix[][n])
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            for (int k = 0; k < n; k++)
            {
                if ((i!=j && j!=k) && !(matrix[i][j] == 1 && matrix[j][k] == 1 && matrix[k][i] == 1))
                    return 0;
            }
        }
    }
}

int checkAntisymmetricforall(int n,int matrix[][n])
{
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j<n; j++)
        {
            if(matrix[i][j] != 0 && matrix[j][i] != 0) 
            {
                return 0;
            } 
            
        }
    }
    return 1;
} 

int checkAntiSymmetric(int n, int matrix[][n])
{
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j<n; j++)
        {
            if((i != j) && matrix[i][j] != 0 && matrix[j][i] != 0) 
            {
                return 0;
            }
        }
    }
    return 1;
} 

int isAllsymmetric(int n, int matrix[][n])
{

    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j<n; j++)
        {
            if(matrix[i][j] == 1 && matrix[j][i] == 1)
            {
                return 1; 
            }
        }
    } 
    return 0;
}

int main()
{
    FILE* fp;
    fp = fopen("SampleInput.csv", "r");
    if (fp == NULL) {
      perror("Failed: ");
      return 1;
    }

    int no_of_websites = -1;

    char buffer[1000];
    
    while (fgets(buffer, sizeof(buffer), fp))
    {   
        no_of_websites++;
    }
    int n=no_of_websites;

    int matrix[no_of_websites][no_of_websites];
    int x = 0;
    int y = 0;

    fp = fopen("SampleInput.csv", "r");
    fgets(buffer, sizeof(buffer), fp);

    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        char* token = strtok(buffer, ",");
        y=0;
  
        while (token != NULL) {
            if(y == 0){
                printf("%s", token);
                }
                else{
                    printf("%d", atoi(token));
                    matrix[x][y-1] = atoi(token);
                      
                    }
            y++;  
            token = strtok(NULL, ",");
        }
        x++;
        
    }
    printf("\n");
    printf("%d\n", no_of_websites);
    printf("\n");
    for(int i = 0; i < no_of_websites; i++) {
    for(int j = 0; j < no_of_websites; j++) {
        printf("%d ", matrix[i][j]);
    }
    printf("\n");
} 
    fclose(fp);
    int a=checkAntiSymmetric(n,matrix);
    int b=isSymmetric(n,matrix);
    int c=isTransitive(n,matrix);
    int d=isReflexive(n, matrix);
    int e=isNonirreflexive(n, matrix); 
    printf("\n");
    printf("\n");
    toReflexive(n,matrix); 
    printf("\n");
    printf("\n");
    toSymmetric(n,matrix); 
    printf("\n");
    printf("\n");
    toAllSymmetric(n,matrix); 
    printf("\n");
    printf("\n");
  

    printf("%d %d %d %d %d\n",a,b,c,d,e);
}