#include <stdio.h>
#include <stdlib.h>
int s1, s2, greater, extra = 0, m, carry = 0;
void add(int a[], int b[], int c[], int s1, int s2, int l)
{
    carry = 0;
    int n = l-1;
    for (int i = s1 - 1, j = s2 - 1; i >= 0 || j >= 0; i--, j--)
    {
        if (j >= 0 && i >= 0)
        {
            c[n] = a[i] + b[j] + carry;
            if (c[n] >= 10)
            {
                carry = 1;
                c[n] = c[n] % 10;
            }
            else
                carry = 0;
            n--;
        }
        else if (j >= 0)
        {
            c[n] = b[j] + carry;
            if (c[n] >= 10)
            {
                carry = 1;
                c[n] = c[n] % 10;
            }
            else
                carry = 0;
            n--;
        }
        else if (i >= 0)
        {
            c[n] = a[i] + carry;
            if (c[n] >= 10)
            {
                carry = 1;
                c[n] = c[n] % 10;
            }
            else
                carry = 0;
            n--;
        }
    }
    c[n] += carry;
    carry =0;
}
int main()
{

    scanf("%d %d", &s1, &s2);
    greater = s1 > s2 ? s1 : s2;
    int final_add[greater + 1];
    int arr[s1], arr2[s2], final_mul[s1 + s2];

    for (int i, j = 0; i < s1 + s2; ++i, ++j)
    {
        final_mul[i] = 0;
        if (j < greater + 1)
            final_add[j] = 0;
    }

    for (int i = 0; i < s1; ++i)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < s2; ++i)
    {
        scanf("%d", &arr2[i]);
    }

    // add(arr,arr2,final_add);
    // for(int i=0;i<greater+1;i++){
    //     printf("%d",final_add[i]);
    // }
    printf("\n");

    for (int i = s2 - 1; i >= 0; i--){
        m = s1 + 1 + extra;
        int l = m;
        int temp[m];
        m = m - 1; //index
        for (int i = 1; i <= extra; i++)
        {
            temp[m--] = 0;
        }
        extra++;
        carry = 0;
        for (int j = s1 - 1; j >= 0; j--)
        {
            temp[m--] = (arr2[i] * arr[j] + carry) % 10;
            carry = (arr2[i] * arr[j] + carry) / 10;
        }
        temp[m] = carry;

         for (int k = 0; k < l; k++)
         {
             printf("%d", temp[k]);
         }
         printf("\n");
        add(temp, final_mul, final_mul, l, s1+s2, s1+s2);
    }
        for (int k = 0; k < s1 + s2; k++)
        {
          //  printf("%d", final_mul[k]);
        }
}
