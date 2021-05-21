int main(){

int n=0;
scanf("%d",&n);
int a[n][n];
for(int i=0;i<n ;i++){
    for (int j=0; j<n ;j++){
       if(i==j){
        a[i][j]=1;
        }
       else{a[i][j]=0;
       }
    }
}
for(int i =0;i<n;i++){
 for(int j =0;j<n;j++){
        printf("%d",a[i][j]);
    }
    printf("\n");
}


int f[n-1];
f[n-1]=0;

for (int i=0;i<n-1;i++){
    scanf("%d",&f[i]);                  // 0 n-2  index
}
int b=n;

for (int i=0;i<n-1;i++ ){
b = b-f[i];
}

                                          // bxc matrix
printf("\n");


int g[n-1];

for (int i=0;i<n-1;i++){
    scanf("%d",&g[i]);                  // 0 n-2  index
}
int c=n;
for (int i=0;i<n-1;i++ ){
c = c-g[i];
}

printf("Size of matrix will be %d %d\n",b, c);

int temp[b][c];

for (int i = 0; i<n ;i++){
    for(int j=0; j<n;j++ ){

        if(f[i]==0){
            temp[i][j]=a[i][j];
        }

        else if(f[i]==1 && f[i-1]==1){
            temp[i-1][j]=temp[i-1][j]+temp[i][j];
            for(int k=1;k<n-i-1;k++){
           a[i+k][j]=a[i+k+1][j];

           temp[i+k][j]=a[i+k][j];

           }

        }


        else if(f[i]==1){
           temp[i][j]=a[i+1][j]+a[i][j];

           for(int k=1;k<n-i-1;k++){
           a[i+k][j]=a[i+k+1][j];

           temp[i+k][j]=a[i+k][j];

           }






        }
    }
}



for(int i=0;i< b;i++){
    for(int j=0;j<c ;j++){
        printf("%d",temp[i][j]);
    }
    printf("\n");
}









return 0;
}
