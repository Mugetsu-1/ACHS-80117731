#include <stdio.h>

int main() {
    double number;
    int floorValue, ceilingValue;

   
    printf("Enter a real number: ");
    scanf("%lf", &number);

    // Calculate the floor value
    floorValue = (int)number;
    if (number < 0 && number != floorValue) {
        floorValue--;
    }

    // Calculate the ceiling value
    if (number == (int)number) {
        ceilingValue = (int)number;
    } else {
        ceilingValue = (int)number + 1;
    }

    
    printf("Floor: %d\n", floorValue);
    printf("Ceiling: %d\n", ceilingValue);

    return 0;
}