// C++ program to find triplets in a given
// array whose sum is zero
/*
Time Complexity: O(n2), Only two nested loops are required, so the time complexity is O(n2).
Auxiliary Space: O(1), no extra space is required, so the time complexity is constant

*/
#include <bits/stdc++.h>
using namespace std;

// function to print triplets with 0 sum
void findTriplets(int arr[], int n)
{
	bool found = false;

	// sort array elements
	sort(arr, arr + n);

	for (int i = 0; i < n - 1; i++) {
		// initialize left and right
		int l = i + 1;
		int r = n - 1;
		int x = arr[i];
		while (l < r) {
			if (x + arr[l] + arr[r] == 0) {
				// print elements if it's sum is zero
				printf("%d %d %d\n", x, arr[l], arr[r]);
				l++;
				r--;
				found = true;
				// break;
			}

			// If sum of three elements is less
			// than zero then increment in left
			else if (x + arr[l] + arr[r] < 0)
				l++;

			// if sum is greater than zero then
			// decrement in right side
			else
				r--;
		}
	}

	if (found == false)
		cout << " No Triplet Found" << endl;
}

// Driven source
int main()
{
	int arr[] = { 0, -1, 2, -3, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	findTriplets(arr, n);
	return 0;
}

// 2nd brute force
i//
Time Complexity: O(n3), As three nested loops are required, so the time complexity is O(n3).
Auxiliary Space: O(1), Since no extra space is required, so the space complexity is constant.
// A simple C program to find three elements
// whose sum is equal to zero
#include <stdbool.h>
#include <stdio.h>

// Prints all triplets in arr[] with 0 sum
void findTriplets(int arr[], int n)
{
	bool found = false;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (arr[i] + arr[j] + arr[k] == 0) {
					printf("%d %d %d\n", arr[i], arr[j],
						arr[k]);
					found = true;
				}
			}
		}
	}

	// If no triplet with 0 sum found in array
	if (found == false)
		printf(" not exist \n");
}

// Driver code
int main()
{
	int arr[] = { 0, -1, 2, -3, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	findTriplets(arr, n);
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)


