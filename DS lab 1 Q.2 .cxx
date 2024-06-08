#include <stdio.h>
#include <stdlib.h>


void cartesianProduct(int* setA, int sizeA, int* setB, int sizeB) {
    printf("Cartesian Product:\n");
    for(int i = 0; i < sizeA; i++) {
        for(int j = 0; j < sizeB; j++) {
            printf("(%d, %d)\n", setA[i], setB[j]);
        }
    }
}


void cartesianProductMultiple(int** sets, int* sizes, int numSets) {
    int totalCombinations = 1;
    for(int i = 0; i < numSets; i++) {
        totalCombinations *= sizes[i];
    }

    int* indices = (int*)calloc(numSets, sizeof(int));
    for(int i = 0; i < totalCombinations; i++) {
        printf("(");
        for(int j = 0; j < numSets; j++) {
            printf("%d", sets[j][indices[j]]);
            if (j < numSets - 1) printf(", ");
        }
        printf(")\n");

        for(int j = numSets - 1; j >= 0; j--) {
            if(++indices[j] < sizes[j]) break;
            indices[j] = 0;
        }
    }
    free(indices);
}

int main() {
   
    int setA[] = {1, 2};
    int setB[] = {3, 4, 5};

    int sizeA = sizeof(setA) / sizeof(setA[0]);
    int sizeB = sizeof(setB) / sizeof(setB[0]);

    cartesianProduct(setA, sizeA, setB, sizeB);

    
    int set1[] = {1, 2};
    int set2[] = {3, 4};
    int set3[] = {5, 6};

    int* sets[] = {set1, set2, set3};
    int sizes[] = {2, 2, 2};

    cartesianProductMultiple(sets, sizes, 3);

    return 0;
}