#include<bits/stdc++.h>
using namespace std;

int Min(int a, int b)
{
    if(a>b)
        return b;
    else
        return a;
}

int *DP_totalCoin_Change(int totalCoin[], int coinT, int coinL);
int *Greedy_totalCoin_Change(int totalCoin[], int coinT, int coinL);
int main()
{
    int coinL, coinT;
    cout<<"Coin limit: ";
    cin>>coinL;
    cout<<"Coin type: ";
    cin>>coinT;
    int totalCoin[coinT+1];
    totalCoin[0] = -200;
    cout<<"Coins: ";
    for(int i=1; i<(coinT+1); i++)
    {
        cin>>totalCoin[i];
    }

    sort(totalCoin, totalCoin+coinT);

    int *greedyP = Greedy_totalCoin_Change(totalCoin, coinT, coinL);
    int *dpP = DP_totalCoin_Change(totalCoin, coinT, coinL);

    if(dpP[0] == coinL && dpP[1] < greedyP[1] )
        cout<<"\nGreedy couldn't give the optimal solution but DP did.\n";

    else if(greedyP[0] != coinL && dpP[0] == coinL)
        cout<<"\nGreedy was unable to solve but DP did.\n";

    else if(greedyP[0] == dpP[0] && greedyP[1 == dpP[1]])
        cout<<"\nGreedy and DP both are optimal.\n";

    return 0;
}

int *DP_totalCoin_Change(int totalCoin[], int coinT, int coinL)
{
    int i, j, k, c=0;
    int A[coinT+1][coinL+1];

    for(i=0; i<(coinT+1); i++)
        A[i][0] = 0;

    for(i=1; i<(coinL+1); i++)
        A[0][i] = coinL*2;

    for(i=1; i<(coinT+1); i++)
    {
        for(j=1; j<(coinL+1); j++)
        {
            if(totalCoin[i]>j)
            {
                A[i][j] = A[i-1][j];
            }

            else
            {
                A[i][j] = Min(A[i-1][j], 1+A[i][j-totalCoin[i]]);
            }
        }
    }

    int coinCount2[A[coinT][coinL]];
    i=coinT;
    j=coinL;
    k=0;
    while(A[i][j] != 0)
    {
        if(A[i][j]-1 == A[i][j-totalCoin[i]] and A[i][j-totalCoin[i]]+1 < A[i-1][j])
        {
            coinCount2[k] = totalCoin[i];
            j = j-totalCoin[i];
            k++;
        }

        else if(A[i][j-totalCoin[i]] == A[i-1][j] or A[i-1][j] < A[i][j-totalCoin[i]]+1)
            i--;
    }

    cout<<"DP needs minimum "<<A[coinT][coinL]<<" totalCoins. ";
    for(i=0; i<A[coinT][coinL]; i++)
    {
        cout<<coinCount2[i]<<" ";
    }

    for(i=0; i<A[coinT][coinL]; i++){
        c+=coinCount2[i];}
    cout<<"= "<<c;

    static int dpArray[]= {c, i};
    return dpArray;
}

int *Greedy_totalCoin_Change(int totalCoin[], int coinT, int coinL)
{
    int count=0, s=coinL,i,sum=0;
    int coinCount[coinL+1];
    for(i=coinT; i>=1; i++)
    {
        while(s>=totalCoin[i])
        {
            s -=totalCoin[i];
            coinCount[count] = totalCoin[i];
            count++;
        }
        if(s==0)
            break;
    }

    cout<<"Greedy needs minimum "<<count<<" totalCoins. ";
    for(i=0; i<count; i++)
    {
        cout<<coinCount[i]<<" ";
        sum+=coinCount[i];
    }

    cout<<"= "<<sum<<endl;

    static int greedyarr[] = {sum, i};
    return greedyarr;
}
