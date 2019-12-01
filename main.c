#include<stdio.h>

char c[3][3];
char m[2] = {'X', 'O'};
int cnt = 0;

int check(int ind)
{
    int b; char ch = m[ind];
    for(int i=0;i<3;i++)
    {
        b = 1;
        for(int j = 0; j<3;j++)
            if(c[i][j] != ch)
                b = 0;
        if(b) return ind+1;
    }
    for(int i=0;i<3;i++)
    {
        b = 1;
        for(int j = 0; j<3;j++)
            if(c[j][i] != ch)
                b = 0;
        if(b) return ind+1;
    }
    b = 1;
    for(int j = 0; j<3;j++)
        if(c[j][j] != ch)
            b = 0;
    if(b) return ind+1;

    b = 1;
    for(int j = 0; j<3;j++)
        if(c[j][2-j] != ch)
            b = 0;
    if(b) return ind+1;
    if(cnt == 9)
        return 3;
    return 0;
}

int main(){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            c[i][j] = ' ';
    int b = 0;
    while(1){
        int n;
        printf("Player %c:\n", m[b]);
        scanf("%d", &n); n--;
        c[n/3][n%3] = m[b];
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<5;j++)
                if(j%2)
                    printf("|");
                else
                    printf("%c", c[i][j/2]);
            printf("\n");
        }
        cnt ++;
        n = check(b);
        if(n){
            if(n==1)
                printf("Player X Won!\n");
            else if(n==2)
                printf("Player O Won!\n");
            else if(n==3)
                printf("Draw!\n");
            break;
        }
        b ^= 1;
    }
    return 0;
}
