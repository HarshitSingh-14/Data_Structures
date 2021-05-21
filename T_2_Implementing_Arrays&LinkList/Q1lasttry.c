#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int mat[n][n];
    for(int i =0 ;i< n ;i++){
        for (int j =0;j<n;j++){
            scanf("%d", &mat[i][j]);
        }
    }

    int sumOfRows[n];
    for(int i =0; i< n ;i++){
            sumOfRows[i]=0;
            for (int j=0; j< n ;j++){
            sumOfRows[i]=sumOfRows[i]+mat[i][j];
    }
}

// Q1 Rows average
int max= 0;
int j=0;
for(int i =0 ;i< n ;i++){
    max=max<sumOfRows[i]?sumOfRows[i]:max;
}
for(int i =0 ;i< n ;i++){
    if(max==sumOfRows[i]){
        break;
    }
    else{
        j++;
    }
}
printf("%d\n", max);
printf("%d\n", j+1);

//Question 2 Column average
 int sumOfColumns[n];
    for(int i =0; i< n ;i++){
            sumOfColumns[i]=0;
            for (int j=0; j< n ;j++){
            sumOfColumns[i]=sumOfColumns[i]+mat[j][i];
    }
}

int min = sumOfColumns[0];
int k=0;
for(int i =0 ;i< n ;i++){
    min=min>sumOfColumns[i]?sumOfColumns[i]:min;
}
for(int i =0 ;i< n ;i++){
    if(min==sumOfColumns[i]){
        break;
    }
    else{
        k++;
    }
}
printf("%d\n", min);
printf("%d\n", k+1);


// Q3 Swapping max And Min
max=0;
min=mat[0][0];
int a=0,b=0,c=0,d=0;

for(int i =0 ;i< n ;i++){
    for(int j =0 ; j< n ;j++){
        if(max<mat[i][j]){
            max=mat[i][j];
            a=i;
            b=j;
        }
        if(min>mat[i][j]){
            min=mat[i][j];
            c=i;
            d=j;
        }
    }
}
int temp =0;

temp=mat[a][b];
mat[a][b]=mat[c][d];
mat[c][d]=temp;

for(int i =0; i< n ;i++){
    for(int j =0;j<n ;j++){
        printf("%d ", mat[i][j]);
    }
    printf("\n");
}
printf("\n");

// Q4
int x=0, y=0;
scanf("%d", &x);
scanf("%d", &y);
printf("\n");

int tempMat[j];
x--;
y--;
for(int j =0 ;j< n ;j++){
    tempMat[j]=mat[x][j];
    mat[x][j]= mat[y][j];
    mat[y][j]= tempMat[j];
}
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        printf("%d ", mat[i][j]);
    }
    printf("\n");
}
printf("\n");



for(int j =0 ;j< n ;j++){
    tempMat[j]=mat[j][x];
    mat[j][x]= mat[j][y];
    mat[j][y]= tempMat[j];
}

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        printf("%d ", mat[i][j]);
    }
    printf("\n");
}
printf("\n");

// Q5 address of firstElement

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        printf("%d ", &mat[i][j]);
    }
    printf("\n");
}
printf("\n");

//Q6

if(((&mat[0][1])-(&mat[0][0]))==1){
    printf("stored in row major");
}
else {printf("stored in column major");}
printf("\n");

int rowMajor[n*n];
int t=0;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        rowMajor[t+j]=mat[i][j];
    }
    t=t+n;
}

for(int i=0;i<n*n;i++){
        printf("%d ", rowMajor[i]);
}
printf("\n");


int colMajor[n*n];
int u=0;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        colMajor[u+j]=mat[j][i];
    }
    u=u+n;
}

for(int i=0;i<n*n;i++){
        printf("%d ", colMajor[i]);
}
printf("\n");


// Q8 store in DiagonalForm..
int diag[n*n];
int p1 =0,p2=0,s1=0,s2=0;
for(int k =0; k<n-1; k++){
        for(int i =0 ; i< n-k; i++)
        {
            diag[i+s1+s2]=mat[i][i+k];
            p1++;
        }
        s1=p1;

    if(k==0){
        continue;}

    else    {    for(int j =0 ; j< n-k; j++)
        {
            diag[j+s1+s2]=mat[j+k][j];
            p2++;
        }
        s2=p2;
    }
}
diag[n*n-2]=mat[0][n-1 ];
diag[n*n-1]=mat[n-1][0];

for(int i =0;i< n*n;i++){
printf("%d ", diag[i]);
}

return 0;
}
