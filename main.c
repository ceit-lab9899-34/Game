#include<stdio.h>

int main(){
    char c[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            c[i][j] = ' ';
    int b = 0;
    char m[2] = {'X', 'O'};
    while(1){
        int n;
        scanf("%d", &n);
        c[n/3][n%3] = m[b];
        n = check();
        if(n){
            if(n==1)
                printf("Player X Won!\n");
            else if(n==2)
                printf("Player O Won!\n");
            else if(n==3)
                printf("Draw!\n");
            break;
        }
    }
    return 0;
}
