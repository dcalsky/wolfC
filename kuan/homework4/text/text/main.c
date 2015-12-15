#include<stdio.h>
int main(void)
{
    int m,n,i,j,is,js,num=0;
    char maze[120][120],move[120],moves,k;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m+1;j++)
        {
            scanf("%c",&maze[i][j]);
            if(maze[i][j]=='S')
            {
                is=i;
                js=j;
            }
        }
    }
    while(scanf("%s",&move[num]) == 1)
    {
        moves=move[num];
        switch(moves)
        {
            case'E':
            {
                if(js!=m&&maze[is][js+1] == '.')
                {
                    k=maze[is][js];
                    maze[is][js]=maze[is][js+1];
                    maze[is][js+1]=k;
                    js+=1;
                }
                break;
            }
            case'W':
            {
                if(js!=0&&maze[is][js-1] == '.')
                {
                    k=maze[is][js];
                    maze[is][js]=maze[is][js-1];
                    maze[is][js-1]=k;
                    js-=1;
                }
                break;
            }
            case'N':
            {
                if(is!=0&&maze[is-1][js] == '.')
                {
                    k=maze[is][js];
                    maze[is][js]=maze[is-1][js];
                    maze[is-1][js]=k;
                    is-=1;
                }
                break;
            }
            case'S':
            {
                if(is!=n-1&&maze[is+1][js] == '.')
                {
                    k=maze[is][js];
                    maze[is][js]=maze[is+1][js];
                    maze[is+1][js]=k;
                    is+=1;
                }
                break;
            }
            default: break;	
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m+1;j++)
            {
                printf("%c",maze[i][j]);
            }
        }
        printf("\n");
        num++;
    }
    return(0);
}