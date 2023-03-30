#include <stdio.h>
#include <stdlib.h>

// Takes the number of items, capacity, weights, and values and returns the maximum value 
// that can be obtained from items whose combined weight is no more than the capacity
int knapsack(int numItems, int capacity, int weights[], int values[]) {
    // Array of size capacity + 1 to store the maximum value for each capacity from 0 to capacity
    int m[capacity + 1];

    // Initialize all elements of the array to 0
    for (int i = 0; i <= capacity; i++) {
        m[i] = 0;
    }

    // Loop through each item and compute the maximum value that can be obtained for each capacity
    for (int i = 0; i < numItems; i++) {
        // Loop backwards through the array starting from the maximum capacity and going down to the weight of the current item
        for (int w = capacity; w >= weights[i]; w--) {
            // Compute the value of adding the current item to the knapsack and store it in val
            int val = m[w - weights[i]] + values[i];
            // If val is greater than the current maximum value for capacity w, update the maximum value to val
            if (val > m[w]) {
                m[w] = val;
            }
        }
    }

    // Return the maximum value that can be obtained
    return m[capacity];

}

int main() {
    // Read in number of instances
    int numInstances;
    scanf("%d", &numInstances);

    // Array to store the maximum value for each instance
    int *maxValue = malloc(numInstances * sizeof(int));

    // Loop through each instance
    for (int i = 0; i < numInstances; i++) {
        int numItems, capacity;

        // Read in number of items and capacity for the current instance
        scanf("%d %d", &numItems, &capacity);

        // Arrays to store the weights and values of each item
        int *weights = malloc(numItems * sizeof(int));
        int *values = malloc(numItems * sizeof(int));

        // Loop through each item and read in its weight and value
        for (int j = 0; j < numItems; j++) {
            scanf("%d %d", &weights[j], &values[j]);
        }

        // Compute the maximum value that can be obtained for the current instance and store it in maxValue to be printed after
        maxValue[i] = knapsack(numItems, capacity, weights, values);

        free(weights);
        free(values);
    }

    // Print out the maximum value for each instance
    for (int i = 0; i < numInstances; i++) {
        printf("%d\n", maxValue[i]);
    }

    free(maxValue);

    return 0;

}
