#include <stdio.h>

struct Item {
    int weight;
    int profit;
    float ratio;
};

int main() {
    int n, capacity;
    
    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    for(int i = 0; i < n; i++) {
        printf("Enter weight and profit of item %d: ", i+1);
        scanf("%d %d", &items[i].weight, &items[i].profit);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort items by profit/weight ratio (descending)
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(items[i].ratio < items[j].ratio) {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    float totalProfit = 0.0;
    int remaining = capacity;

    for(int i = 0; i < n; i++) {
        if(items[i].weight <= remaining) {
            remaining -= items[i].weight;
            totalProfit += items[i].profit;
        }
        else {
            totalProfit += items[i].ratio * remaining;
            break;
        }
    }

    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}

