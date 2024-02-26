#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

void disp(int *top, int count)  /* call by reference */
{
    int i = 0;
    int *ptr =top;
    sort(ptr, ptr + count); //Sort is an in-built function in a C++ STL 
    //The function can also be used for custom sorting by passing in a comparator function that returns a boolean
   //sort(ptr, ptr + count, greater<int>()); // reverse

    for (i = 0; i < count; i++)
    {
        printf(" [%u] ", *ptr);
        ptr++;
    }



    printf("\n\n");
}

int main()
{
    /* an int array with 5 elements */
    int balance[] = {1000, 2, 3, 17, 50, 3, 19, 17, 14, 34};
    int i = 0;
    int *ptr = balance;
    int count  = sizeof(balance) / sizeof(balance[0]);
    printf("val =%d \n", count);
    
    for (i = 0; i < count; i++)
    {
        printf(" [%u] ", *ptr);
        ptr++;
    }


    disp(balance, count);
    ptr = balance;
    
    for (i = 0; i < count; i++)
    {
        printf(" [%u] ", *ptr);
        ptr++;
    }

    return 0;
}
