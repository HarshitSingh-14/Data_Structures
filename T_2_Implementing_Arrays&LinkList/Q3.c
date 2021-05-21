#include<stdio.h>
void addNumber(int no1[],int no2[], int o){

    int no3[o];
    int carry =0;
    for(int i =o-1 ;i>=0;i--){
        no3[i]=(no2[i]+no1[i]+carry)%10;
        carry=(no2[i]+no1[i]+carry)/10;
    }
    if(carry !=0){
    printf("%d ", carry);
    }
    for(int i=0;i<o ;i++){
        printf("%d ", no3[i]);
    }
}


void subNumber(int no1[], int no2[], int o, int m, int n ){
    int no3[o];
    int borrow=0;
    if(m>=n){
    for(int i =o-1; i>=0;i--){
        no3[i]=(no1[i]-no2[i]-borrow+10)%10;
        if(no1[i]-no2[i]<0){
            borrow=1;
        }
        else {borrow = 0;}
    }
}
    else {
    for(int i =o-1; i>=0;i--){
        no3[i]=(no2[i]-no1[i]-borrow+10)%10;
        if(no2[i]-no1[i]<0){
            borrow=1;
        }
        else {borrow = 0;}
    }
}
    if(m>=n){
        for(int i=0;i<o ;i++){
        printf("%d ", no3[i]);
        }
    }

    else {
        printf("%d ", -1*no3[0]);
        for(int i=1;i<o ;i++){
        printf("%d ", no3[i]);
        }
    }
}

 mulNumber(int no1[],int no2[], int o , int m , int n ){
    int rev_no1[o];
    int no3[2*o];
    for(int i = 0; i < o; i++)
    {
        rev_no1[i] = no1[o - 1 - i];
    }
    int rev_no2[o];
    for(int i = 0; i < o; i++)
    {
        rev_no2[i] = no2[o - 1 -i];
    }

for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            no3[i+j] += rev_no1[i] * rev_no2[j];
        }
    }
    int carry;
    for(int i = 0; i < o * 2; i++)
    {
        carry = 0;
        carry = no3[i]/10;
        no3[i] = no3[i]%10;
        no3[i+1] += carry;
    }
    for(int i =o*2-1 ;i>=0;i--){
    printf("%d", no3[i]);
    }
 }


int main(){
 printf("write the size of first number ");
int m;
scanf("%d",&m );
printf("Write the size of second number ");
int n;
scanf("%d",&n );
int o=m<n?n:m;
int no1[o];
int no2[o];
printf("Write the number 1 & number 2 -> \n");
if(m>n){
    for (int i=0;i<m;i++){
    scanf("%d",&no1[i]);
    }
    for (int i=0;i<m-n;i++){
    no2[i]=0;
    }
    for (int i=m-n;i<m;i++){
    scanf("%d",&no2[i]);
    }
}
else if(n>m){
    for (int i=0;i<n-m;i++){
    no1[i]=0;
    }
    for (int i=n-m;i<n;i++){
    scanf("%d",&no1[i]);
    }

    for (int i=0;i<n;i++){
    scanf("%d",&no2[i]);
    }
}
else{
    for (int i=0;i<m;i++){
    scanf("%d",&no1[i]);
    }
    for (int i=0;i<n;i++){
    scanf("%d",&no2[i]);
    }
}

for(int i =0 ;i< o ;i++){
    printf("%d ", no1[i]);
}
printf("\n");

for(int i =0 ;i< o ;i++){
    printf("%d ", no2[i]);
}
printf("\n");

addNumber(no1, no2,o);
// subNumber(no1, no2,o,m,n);
 //ulNumber(no1, no2,o,m,n);
return 0;
}

