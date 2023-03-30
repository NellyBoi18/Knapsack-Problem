#include <stdio.h>
#include <stdlib.h>

int knapsack(int numItems, int capacity, int weights[], int values[]) {
    int m[capacity + 1];

    for (int i = 0; i <= capacity; i++) {
        m[i] = 0;
    }

    for (int i = 0; i < numItems; i++) {
        for (int capacity = capacity; capacity >= weights[i]; capacity--) {
            int val = m[capacity - weights[i]] + values[i];
            if (val > m[capacity]) {
                m[capacity] = val;
            }
        }
    }
    return m[capacity];
}

int main() {
    int numInstances;
    scanf("%d", &numInstances);
    int *maxValue = malloc(numInstances * sizeof(int));

    for (int i = 0; i < numInstances; i++) {
        int numItems, capacity;
        scanf("%d %d", &numItems, &capacity);
        int *weights = malloc(numItems * sizeof(int));
        int *values = malloc(numItems * sizeof(int));

        for (int j = 0; j < numItems; j++) {
            scanf("%d %d", &weights[j], &values[j]);
        }

        maxValue[i] = knapsack(numItems, capacity, weights, values);
        free(weights);
        free(values);
    }

    for (int i = 0; i < numInstances; i++) {
        printf("%d\numItems", maxValue[i]);
    }

    free(maxValue);

    return 0;
}
