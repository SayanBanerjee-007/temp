#include<stdio.h>

void main(){
    int n;
     printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n],bt[n],ft[n],tat[n],wt[n];
    float tat1=0,wt1=0;

    printf("Enter burst time of each process: \n");
    for(int i=0;i<n;i++){
        printf("P[%d]: ",i+1);
        scanf("%d",&bt[i]);
    }
    printf("Enter arrival time of each process: \n");
    for(int i=0;i<n;i++){
        printf("P[%d]: ",i+1);
        scanf("%d",&at[i]);
    }

    ft[0]=bt[0];
    for(int i=1;i<n;i++){
        ft[i]=ft[i-1]+bt[i];
    }
    for(int i=0;i<n;i++){
        tat[i]=ft[i]-at[i];
        tat1+=tat[i];
    }

    for(int i=0;i<n;i++){
        wt[i]=tat[i]-bt[i];
        wt1+=wt[i];
    }

    printf("|process|BT \t|AT \t|FT \t|TAT \t|WT \t|\n");
    printf("\n");
    for(int i=0;i<n;i++){
        printf("|P[%d] \t|%d \t|%d \t|%d \t|%d \t|%d \t|\n",i+1,bt[i],at[i],ft[i],tat[i],wt[i]);
    }
    printf("\n");
    printf("Average Turnaround Time: %f\n",tat1/n);
    printf("Average Waiting Time: %f\n",wt1/n);

}

// Output:
/*
Enter the number of processes: 3
Enter burst time of each process:
P[1]: 5
P[2]: 9
P[3]: 6
Enter arrival time of each process:
P[1]: 0
P[2]: 1
P[3]: 2
|process|BT     |AT     |FT     |TAT    |WT     |

|P[1]   |5      |0      |5      |5      |0      |
|P[2]   |9      |1      |14     |13     |4      |
|P[3]   |6      |2      |20     |18     |12     |

Average Turnaround Time: 12.000000
Average Waiting Time: 5.333333
 */
