#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

int m,n,nowx,nowy,boxnum,map[100][100],nowmap[100][100],setboxx[10000],setboxy[10000];

void printmap()
{
	int i,j;
        system("cls");
	for (i=1;i<=m;i++)
	{
		for (j=1;j<=n;j++)
                {
                        printf("%d ",nowmap[i][j]);
                }
		printf("\n");
	}
}

void getmap()
{
        int i,j;
        scanf("%d %d",&m,&n);
        boxnum=0;
        for (i=1;i<=m;i++)
        {
                for (j=1;j<=n;j++)
                {
                        scanf("%d",&map[i][j]);
                        nowmap[i][j]=map[i][j];
                        if (map[i][j]==0)
                        {
                                nowx=i;
                                nowy=j;
                        }
                        else if (map[i][j]==2)
                        {
                                boxnum++;
                                setboxx[boxnum]=i;
                                setboxy[boxnum]=j;
                        }//0 人起始位置 1 箱子 2 箱子需达到位置 3 障碍 4 空地
                }
        }
}

int checkwin()
{
        int flag,i;
        flag=1;
        for (i=1;i<=boxnum;i++)
        {
                if (nowmap[setboxx[i]][setboxy[i]]!=1)
                {
                        flag=0;
                }
        }
        return flag;
}
void startgame()
{
        char option;
        while (checkwin()!=1)
        {
                scanf("%c",&option);
                if (option=='s')
                {
                        if (map[nowx+1][nowy]==3)
                        {
                                printf("you can't do that!");
                        }
                        else if (nowmap[nowx+1][nowy]==1)
                        {
                                if (map[nowx+2][nowy]==3 || map[nowx+2][nowy]==1)
                                {
                                        printf("you can't do that!");
                                }
                                else
                                {
                                        nowmap[nowx+1][nowy]=1;
                                }
                        }
                        if (map[nowx][nowy]==2)
                        {
                                nowmap[nowx][nowy]=2;
                        }
                        else
                        {
                                nowmap[nowx][nowy]=4;
                        }
                        nowx++;
                }
                if (option=='w')
                {
                        if (map[nowx-1][nowy]==3)
                        {
                                printf("you can't do that!");
                        }
                        else if (nowmap[nowx-1][nowy]==1)
                        {
                                if (map[nowx-2][nowy]==3 || map[nowx-2][nowy]==1)
                                {
                                        printf("you can't do that!");
                                }
                                else
                                {
                                        nowmap[nowx-1][nowy]=1;
                                }
                        }
                        if (map[nowx][nowy]==2)
                        {
                                nowmap[nowx][nowy]=2;
                        }
                        else
                        {
                                nowmap[nowx][nowy]=4;
                        }
                        nowx--;
                }
                if (option=='a')
                {
                        if (map[nowx][nowy-1]==3)
                        {
                                printf("you can't do that!");
                        }
                        else if (nowmap[nowx][nowy-1]==1)
                        {
                                if (map[nowx][nowy-2]==3 || map[nowx][nowy-2]==1)
                                {
                                        printf("you can't do that!");
                                }
                                else
                                {
                                        nowmap[nowx][nowy-2]=1;
                                }
                        }
                        if (map[nowx][nowy]==2)
                        {
                                nowmap[nowx][nowy]=2;
                        }
                        else
                        {
                                nowmap[nowx][nowy]=4;
                        }
                        nowy--;
                }
                if (option=='d')
                {
                        if (map[nowx][nowy+1]==3)
                        {
                                printf("you can't do that!");
                        }
                        else if (nowmap[nowx][nowy+1]==1)
                        {
                                if (map[nowx][nowy+2]==3 || map[nowx][nowy+2]==1)
                                {
                                        printf("you can't do that!");
                                }
                                else
                                {
                                        nowmap[nowx][nowy+2]=1;
                                }
                        }
                        if (map[nowx][nowy]==2)
                        {
                                nowmap[nowx][nowy]=2;
                        }
                        else
                        {
                                nowmap[nowx][nowy]=4;
                        }
                        nowy++;
                }
                nowmap[nowx][nowy]=0;
                printmap();
	}
	printf("Congratulations!\n");
}

int main()
{
        getmap();
        startgame();
        return 0;
}
