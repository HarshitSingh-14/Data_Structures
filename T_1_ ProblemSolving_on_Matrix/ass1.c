 int main(){

int a[4][4]= {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};

for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
printf("%d ", a[i][j]);
    }
    printf("\n");
}


int f[3];

for (int i=0;i<3;i++){
    scanf("%d",&f[i]);
}

int b=0,c=0,d=0;
b=f[0];
c=f[1];
d=f[2];
int e= 4-b-c-d;




if (b==1){
        for(int j=0;j<4;j++){
    a[0][j]=a[1][j]+a[0][j];
    a[1][j]=a[2][j];
    a[2][j]=a[3][j];
        }
    if(c==1){
        for (int j=0;j<4;j++){
            a[0][j]=a[0][j]+a[1][j];
            a[1][j]=a[3][j];
        }
        if(d==1){for(int j=0;j<4;j++)
            a[0][j]=a[0][j]+a[1][j];

        }
    }
    else if(c==0){


                if(d==1){
                for(int j =0;j<4;j++){
                 a[1][j]= a[1][j]+a[2][j];
                }
            }
        }
    }



else if (c==1){
        for (int j =0 ;j < 4; j++){
            a[1][j]= a[1][j]+a[2][j];
            a[2][j]=a[3][j];
        }

    if (d==1){for(int j=0;j<4;j++)
            a[1][j]=a[1][j]+a[2][j];
    }
}

else if(d==1){
    for(int j=0; j<4; j++){
        a[2][j]= a[2][j]+ a[3][j];
    }
    
for(int i=0;i<e;i++){
    for(int j=0;j<4;j++){
printf("%d ", a[i][j]);
    }
    printf("\n");
}


return 0;
}
