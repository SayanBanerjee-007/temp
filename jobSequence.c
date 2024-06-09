

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int deadline;
    int profit;
} Job;

int compare(const void *a, const void *b)
{
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    return jobB->profit - jobA->profit;
}

void printJobs(Job *jobs, int n)
{
    printf("ID\tDeadline\tProfit\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    }
}

void jobSequencing(Job *jobs, int n)
{
    qsort(jobs, n, sizeof(Job), compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        if (jobs[i].deadline > maxDeadline)
        {
            maxDeadline = jobs[i].deadline;
        }
    }

    int *timeSlots = (int *)malloc(maxDeadline * sizeof(int));
    for (int i = 0; i < maxDeadline; i++)
    {
        timeSlots[i] = -1;
    }

    int totalProfit = 0;
    printf("\nSelected Jobs:\nID\tDeadline\tProfit\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i].deadline - 1; j >= 0; j--)
        {
            if (timeSlots[j] == -1)
            {
                timeSlots[j] = i;
                totalProfit += jobs[i].profit;
                printf("%d\t%d\t\t%d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
                break;
            }
        }
    }

    printf("\nTotal Profit: %d\n", totalProfit);

    free(timeSlots);
}

int main()
{
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    Job *jobs = (Job *)malloc(n * sizeof(Job));

    printf("Enter job details (ID Deadline Profit):\n");
    for (int i = 0; i < n; i++)
    {
        printf("Job %d: ", i + 1);
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    jobSequencing(jobs, n);

    free(jobs);
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int deadline;
    float profit;
} Job;

int compare(const void *a, const void *b)
{
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    if (jobA->deadline > jobB->deadline)
        return 1;
    else if (jobA->deadline < jobB->deadline)
        return -1;
    else
        return 0;
}

float jobSequence(Job *jobs, int n)
{
    float maxProfit, totalProfit = 0;
    int maxDeadline;
    qsort(jobs, n, sizeof(Job), compare);
    maxDeadline = jobs[n - 1].deadline;
    float *profits = (float *)calloc(maxDeadline, sizeof(float));


    for (int i = 0, k = 0; i < n-1 && k < maxDeadline; k++)
    {
        int j;
        maxProfit = jobs[i].profit;
        for (j = i + 1; jobs[i].deadline == jobs[j].deadline && j < n; j++)
        {
            if (jobs[j].profit > maxProfit)
            {
                maxProfit = jobs[j].profit;
            }
        }
        i = j;
        profits[k] = maxProfit;
    }
    for (int i = 0; i < maxDeadline; i++)
    {
        totalProfit += profits[i];
    }
    free(profits);
    return totalProfit;
}

void main()
{

    int n;
    float maxProfit;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    Job *jobs = (Job *)malloc(n * sizeof(Job));

    printf("Enter the job details (Deadline Profit)\n");
    for (int i = 0; i < n; i++)
    {
        printf("Job %d -> ", i + 1);
        scanf("%d %f", &jobs[i].deadline, &jobs[i].profit);
    }

    maxProfit = jobSequence(jobs, n);
    printf("Max Profit: %.2f\n", maxProfit);
}
*/
