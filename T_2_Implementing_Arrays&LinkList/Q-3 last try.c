#include <stdio.h>

void add(int a[], int b[], int c[], int m, int n, int p)
{
    int d = 0, k = p;

}

void multiply(int a[], int b[], int d[], int m, int n, int p)
{
    for (int i = 0; i < p; ++i)
        d[i] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int q = m + n - i;
        int c[q];
        int r = q - 1;
        for (int j = 0; j < n - i - 1; j++)
        {
            c[r] = 0;
            r--;
        }
        int e = 0;
        for (int j = m - 1; j >= 0; j--)
        {
            c[r] = (b[i] * a[j]) + e;
            if (c[r] / 10 > 0)
            {
                e = c[r] / 10;
                c[r] = c[r] % 10;
            }
            else
                e = 0;
            r--;
        }
        c[r] = e;
        int f[p];
        add(c, d, f, q - 1, p - 1, p - 1);
        for (int k = 0; k < p; k++)
            d[k] = f[k];
    }
}

int subtract(int a[], int b[], int e[], int m, int n, int p)
{
    int x = 0, y = 0, z;
    for (int i = 0; i < m; ++i)
    {
        if (x == 0)
        {
            if (a[i] == 0)
                continue;
            else
                x++;
        }
        else
            x++;
    }
    for (int i = 0; i < n; ++i)
    {
        if (y == 0)
        {
            if (b[i] == 0)
                continue;
            else
                y++;
        }
        else
            y++;
    }
    if(x==y)
    {
        int i = 0, j = 0;
        while(!a[i])
        {
            i++;
        }
        while(!b[j])
        {
            j++;
        }
        for(; i<m; i++, j++)
        {
            if(a[i] > b[j])
            {
                z=1;
                break;
            }
            else if(b[j] > a[i])
            {
                z=0;
                break;
            }
        }
        if(i == m)
        return -1;

    }
    else if(x>y)
    z=1;
    else if(x<y)
    z=0;

    int c[p], d[p];
    for(int i=0; i<p;++i)
    {
        if(z==1)
        c[i] = 9 - a[i];
        else if(z==0)
        c[i] = 9 - b[i];

    }
    if(z==1)
    add(c, b, d, p-1, n-1, p - 1);
    else if(z==0)
    add(c, a, d, p-1, m-1, p - 1);

    for(int i=0; i<p;++i)
    {
        e[i] = 9 - d[i];
    }

    return z;
}

int main()
{
    int m, n;
    printf("Enter the number of digits in first : ");
    scanf("%d", &m);
    printf("Enter the number of digits in second : ");
    scanf("%d", &n);

    int a[m], b[n];

    printf("Enter Number-1 : ");
    for (int i = 0; i < m; i++)
        scanf("%d", &a[i]);
    printf("Enter Number-2 : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);


    int p = m > n ? m : n;
    p++;
    int c[p];
    add(a, b, c, m - 1, n - 1, p - 1);


    printf("\nADDITION : ");
    for (int i = 0; i < p; i++)
        printf("%d ", c[i]);

    printf("\n\n");
    int d[m + n];
    p = m + n;
    multiply(a, b, d, m, n, p);


    printf("\nMULTIPLICATION : ");
    for (int i = 0; i < p; i++)
        printf("%d ", d[i]);

    printf("\n\n");
    p = m > n ? m : n;
    int e[p];
    int s = subtract(a, b, e, m, n, p);


    printf("\nSUBTRACTION : ");
    if(s == -1)
    {
        for (int i = 0; i < p; i++)
        printf("0 ");
        return 0;
    }
    else if(s == 0)
    printf("-");
    for (int i = 0; i < p; i++)
        printf("%d ", e[i]);

    return 0;
}
