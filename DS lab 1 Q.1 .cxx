#include <stdio.h>


#define MAX_SIZE 100


void unionSets(int set1[], int size1, int set2[], int size2);
void intersectionSets(int set1[], int size1, int set2[], int size2);
void differenceSets(int set1[], int size1, int set2[], int size2);
void symmetricDifferenceSets(int set1[], int size1, int set2[], int size2);

// Function to check if an element is present in a set
int isElementInSet(int element, int set[], int size) {
    for (int i = 0; i < size; i++) {
        if (set[i] == element) {
            return 1;
        }
    }
    return 0;
}

// Function to print a set
void printSet(int set[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", set[i]);
    }
    printf("}\n");
}

// Function to perform union of two sets
void unionSets(int set1[], int size1, int set2[], int size2) {
    int unionSet[MAX_SIZE];
    int unionSize = 0;

    for (int i = 0; i < size1; i++) {
        unionSet[unionSize++] = set1[i];
    }
    
    for (int i = 0; i < size2; i++) {
        if (!isElementInSet(set2[i], set1, size1)) {
            unionSet[unionSize++] = set2[i];
        }
    }

    printf("Union: ");
    printSet(unionSet, unionSize);
}

// Function to perform intersection of two sets
void intersectionSets(int set1[], int size1, int set2[], int size2) {
    int intersectionSet[MAX_SIZE];
    int intersectionSize = 0;

    for (int i = 0; i < size1; i++) {
        if (isElementInSet(set1[i], set2, size2)) {
            intersectionSet[intersectionSize++] = set1[i];
        }
    }

    printf("Intersection: ");
    printSet(intersectionSet, intersectionSize);
}

// Function to perform difference of set1 - set2
void differenceSets(int set1[], int size1, int set2[], int size2) {
    int differenceSet[MAX_SIZE];
    int differenceSize = 0;

    for (int i = 0; i < size1; i++) {
        if (!isElementInSet(set1[i], set2, size2)) {
            differenceSet[differenceSize++] = set1[i];
        }
    }

    printf("Difference (set1 - set2): ");
    printSet(differenceSet, differenceSize);
}

// Function to perform symmetric difference of two sets
void symmetricDifferenceSets(int set1[], int size1, int set2[], int size2) {
    int symmetricDifferenceSet[MAX_SIZE];
    int symmetricDifferenceSize = 0;

    for (int i = 0; i < size1; i++) {
        if (!isElementInSet(set1[i], set2, size2)) {
            symmetricDifferenceSet[symmetricDifferenceSize++] = set1[i];
        }
    }

    for (int i = 0; i < size2; i++) {
        if (!isElementInSet(set2[i], set1, size1)) {
            symmetricDifferenceSet[symmetricDifferenceSize++] = set2[i];
        }
    }

    printf("Symmetric Difference: ");
    printSet(symmetricDifferenceSet, symmetricDifferenceSize);
}

int main() {
    int size1, size2;
    int set1[MAX_SIZE], set2[MAX_SIZE];
    
    // Input first set
    printf("Enter the size of the first set (max %d): ", MAX_SIZE);
    scanf("%d", &size1);
    if (size1 > MAX_SIZE) {
        printf("Size exceeds the maximum limit.\n");
        return 1;
    }
    printf("Enter the elements of the first set: ");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &set1[i]);
    }

    // Input second set
    printf("Enter the size of the second set (max %d): ", MAX_SIZE);
    scanf("%d", &size2);
    if (size2 > MAX_SIZE) {
        printf("Size exceeds the maximum limit.\n");
        return 1;
    }
    printf("Enter the elements of the second set: ");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &set2[i]);
    }

    // Perform set operations
    unionSets(set1, size1, set2, size2);
    intersectionSets(set1, size1, set2, size2);
    differenceSets(set1, size1, set2, size2);
    symmetricDifferenceSets(set1, size1, set2, size2);

    return 0;
}