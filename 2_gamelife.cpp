#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

void show_life(int a[], int n, int m              );
int next_state(int a[], int n, int m, int i, int j);

int main()
{
    int i, j;
    int asleep=100;
    int n=20;
    int m=40;
    int summa=0;
    int a[n][m];
    int b[n][m];
    srand(time(NULL));

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            a[i][j] = rand() % 2;
            b[i][j] = 0;
        }
    }

    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        show_life(&a[0][0], n, m);
        Sleep(asleep);

        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                b[i][j] = next_state(&a[0][0], n, m, i, j);
            }
        }

        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                a[i][j] = b[i][j];
            }
        }

        system("cls");
    }
}


void show_life(int a[], int n, int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(a[i*m+j]==1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int next_state(int a[], int n, int m, int i, int j)
{
    int summa=0;

    summa=((a[((n+(i-1))% n)*m + ((m+(j-1))%m)])+
           (a[((n+(i-1))% n)*m + j            ])+
           (a[((n+(i-1))% n)*m + ((j+1)%m)    ])+
           (a[i             *m + ((m+(j-1))%m)])+
           (a[i             *m + ((j+1)%m)    ])+
           (a[((i+1)%n)     *m + ((m+(j-1))%m)])+
           (a[((i+1)%n)     *m + j            ])+
           (a[((i+1)%n)     *m + ((j+1)%m)    ]));

    if( (summa==3)  || ( (a[i*m+j]==1) && (summa==2) ) )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
