#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#define IN 99

int n,array[20],count=0;
int dijkstra(int cost[10][10], int source, int target);

int max(int a, int b) { return (a > b) ? a : b; }


int i,j,m,n,c[20][20];
char g[20],h[20],b[20][20];
void print(int i,int j)
{

    if(i==0 || j==0)
        return;
    if(b[i][j]=='c')
    {
        print(i-1,j-1);
        printf("%c",g[i-1]);
    }
    else if(b[i][j]=='u')
        print(i-1,j);
    else
        print(i,j-1);
}
void lcs()
{

    m=strlen(g);
    n=strlen(h);
    for(i=0;i<=m;i++)
        c[i][0]=0;
    for(i=0;i<=n;i++)
        c[0][i]=0;
//c, u and l denotes cross, upward and downward directions respectively
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            if(g[i-1]==h[j-1])
            {

                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='c';

            }
            else if(c[i-1][j]>=c[i][j-1])
            {

                    c[i][j]=c[i-1][j];
                    b[i][j]='u';

            }

            else
            {

            c[i][j]=c[i][j-1];
            b[i][j]='l';

            }
        }

}


// Prints the items which are put in a knapsack of capacity W
void printknapSack(int W, int wt[10], int val[10], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                    K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    int res = K[n][W];

    w = W;
    for (i = n; i > 0 && res > 0; i--) {
        if (res == K[i - 1][w])
            continue;
        else {

                array[count]=i;
                // This item is included.
                printf("\t\t\tHouse number %d is having profit %d and weight %d\n",i,val[i-1], wt[i - 1]);
                    count ++;

            // Since this weight is included its
            // value is deducted
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
     printf("\n\t\t\t*** Total number of houses selected:%d ***",count);
    char z = getch();
    printf("%c",z);


    if(count==0)
    {
        printf("\n\n\n\t\tNO house is selected according to Theif carrying capacity\n");
        exit (0);
    }


}

// Driver code
int main()
{
    int val[10],wt[10],i;
    int W,as=0;

    printf("\t\t\t\t\t\t ______________");
    printf("\n\t\t\t\t\t\t|              |");
    printf("\n\t\t\t\t\t\t|   ROBBERY    |");
    printf("\n\t\t\t\t\t\t|______________|");
    printf("\n\n");
    printf("\n\n\t<-- A Theif decides to rob in his locality.Therefore He finds out the details of his locality.-->\n");
    char c = getch();
    printf("%c",c);
    printf("\nEnter the number of houses in the locality:\t");
    scanf("%d",&n);
    printf("\nEnter the profit and weight of Jewllery of each house:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&val[i],&wt[i]);
    }
    printf("\nEnter the weight that Theif can carry:\t");
    scanf("%d",&W);
    printf("\n");
    printknapSack(W, wt, val, n);

     int cost[10][10],j,p,co;
    int source, target,x,y;
    printf("\n\n<-- Enter the different possible routes to each house in the locality.Considering the roads are Bidirectional -->\n\n");
    char xz = getch();
    printf("%c",xz);
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    cost[i][j] = IN;
    printf("Enter the distance between\n");
    for(x=1;x<=n;x++)
    {
        for(y=x+1;y<=n;y++)
        {
            printf("Houses %d and %d: ",x,y);
            scanf("%d",&p);
            cost [x][y] = cost[y][x] = p;
            if(cost[x][y]==0)
            {
                cost[x][y]=cost[y][x]=IN;
            }
        }
        printf("\n");
    }
    printf("Enter the House no. of Theif:\t");
    scanf("%d", &source);

    while(1)
    {
        printf("Enter the House no. the Theif decides to rob:\t");
        scanf("%d", &target);

        for(int n=0;n<count;n++)
        {
            if(array[n]==target)
            {
            co = dijsktra(cost,source,target);
            printf("\n\t\t*** The Shortest distance between the Theif's house and the victim's house is %d km ***\n",co);
            as++;
            }
        }
        if(as==0)
        {
            printf("\n\t\t\t***This house is not listed based on theif capacity***\n\n");
        }
        else
            break;

    }
    char cv = getch();
    printf("%c",cv);

    printf("\n\n\t\t||  The Thief enters the house and finds the locker.\t\t    ||\n\t\t||  While searching for the locker he finds a note reading two      ||\n\t\t||  sequences,");
    printf("in which some of the letters where coloured.\t    ||\n\t\t||  So he guesses that actual password will have some common letters||\n\t\t||  between the two written passwords.\t\t\t\t    ||");
    char vc = getch();
    printf("%d",vc);

    printf("\n\nEnter the first password sequence:");
    scanf("%s",g);
    printf("Enter the second password sequence:");
    scanf("%s",h);
    printf("\n\t\t\t*** The common Password is ");
    lcs();
    print(m,n);
    printf(" ***");
    printf("\n\n");

    printf("\t\t++>> The theif was successful in opening the locker and taking off the Jewellery with him. <<++");
    printf("\n\n\n");
    getch();

    return 0;
}


int dijsktra(int cost[10][10],int source,int target)
{

    int dist[10],selected[10]={0},i,m,min,start,d,as=16;
    char path[10],prev[10];

    if(source==target)
    {
        printf("\n\t\tA Theif cannot rob his own home\n\n\n");
        exit(0);
    }
    else
    {
    for(i=1;i<=n;i++)
    {
        dist[i] = IN;
        prev[i] = -1;
    }
    start = source;
    selected[start]=1;
    dist[start] = 0;
    while(selected[target] ==0)
    {
        min = IN;
        m = 0;
        for(i=1;i<=n;i++)
        {
            d = dist[start] +cost[start][i];
            if(d< dist[i]&&selected[i]==0)
            {
                dist[i] = d;
                prev[i]=start;
            }
            if(min>dist[i] && selected[i]==0)
            {
                min = dist[i];
                m = i;
            }
        }
        start = m;
        selected[start] = 1;
    }
    start=target;
    j=0;
    while(start!=-1)
    {
        path[j++]=start+64;
        start=prev[start];
    }
    path[j++]='\0';
    strrev(path);
    printf("\t\t\t\t");
    for(int i=0;i<strlen(path);i++)
    {
        printf("%c-->",(path[i]-as));
    }

    return dist[target];
    }
}

