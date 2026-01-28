#include <stdio.h>

struct Job {
    int id;
    int deadline;
    int profit;
};

int main() {
    int n;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    struct Job jobs[n];

    for(int i = 0; i < n; i++) {
        printf("Enter job id, deadline and profit: ");
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    // Sort jobs in descending order of profit
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(jobs[i].profit < jobs[j].profit) {
                struct Job temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }

    int maxDeadline = 0;
    for(int i = 0; i < n; i++)
        if(jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;

    int slot[maxDeadline];
    for(int i = 0; i < maxDeadline; i++)
        slot[i] = -1;

    int totalProfit = 0;

    for(int i = 0; i < n; i++) {
        for(int j = jobs[i].deadline - 1; j >= 0; j--) {
            if(slot[j] == -1) {
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("\nJob sequence: ");
    for(int i = 0; i < maxDeadline; i++) {
        if(slot[i] != -1)
            printf("J%d ", slot[i]);
    }

    printf("\nTotal Profit = %d\n", totalProfit);

    return 0;
}


