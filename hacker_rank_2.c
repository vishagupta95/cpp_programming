/** Minimum unique array sum
Question: Given a sorted integer array, return sum of array so that each element is unique by adding some numbers 
to duplicate elements so that sum of unique elements is minimum.

I.e., if all elements in the array are unique, return the sum. If some elements are duplicates, then increment them to make sure all 
elements are unique so that the sum of these unique elements is minimum.

Some examples:

input1[] = { 2, 3, 4, 5 } => return 19 = 2+3+4+5 (all elements are unique, so just add them up)
input2[] = { 1, 2, 2 } => return 6 = 1+2+3 (index 2 is duplicate, so increment it)
input3[] = { 2, 2, 4, 5 } => return 14 = 2+3+4+5 (index 1 is duplicate, so increment it)
These three are examples in the question, my simple algorithm is as follows and passed the given three examples, but didn't pass other cases where I couldn't see the inputs.
*/

// CPP program to make sorted array elements
// distinct by incrementing elements and keeping
// sum to minimum.
#include <iostream>
using namespace std;

// Efficient CPP program to make sorted array
// elements distinct by incrementing elements
// and keeping sum to minimum.
#include <iostream>
using namespace std;

// To find minimum sum of unique elements.
int minSum(int arr[], int n)
{
    int sum = arr[0], prev = arr[0];

    for (int i = 1; i < n; i++) {

        // If violation happens, make current
        // value as 1 plus previous value and
        // add to sum.
        if (arr[i] <= prev) {
            prev = prev + 1;
            sum = sum + prev;
        }

        // No violation.
        else {
            sum = sum + arr[i];
            prev = arr[i];
        }
    }

    return sum;
}

// Drivers code
int main()
{
    int arr[] = { 2, 2, 3, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minSum(arr, n) << endl;
    return 0;
}


tatic int minUniqueSum(int[] A) {
    int n = A.length;


    int sum = A[0];
    int prev = A[0];

    for( int i = 1; i < n; i++ ) {
        int curr = A[i];

        if( prev == curr ) {
            curr = curr+1;
            sum += curr;
        }
        else {
            sum += curr;
        }
        prev = curr;
    }

    return sum;
}
