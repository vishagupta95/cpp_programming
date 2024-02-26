/*
Qs 5. Reductor Array
For two integer arrays, the comparator value is the total number of elements in the first array such that there exists no integer in the second array with an absolute difference less than or equal to d. Find the comparator value. For example there are two arrays a = [7, 5, 9], b = [1, 13, 14], and the integer d = 3. The absolute difference of a[0] to b[0] = |7 – 13| = 6, b[1] = |17-1| = 6, and b[2] = |17-14| = 3, to recap, the values are 6,6, 3. In this case, the absolute difference with b[2] is equal to d = 3, so this element does not meet the criterion. A similar analysis of a[1] = 5 yields absolute differences of 8, 4, 1 and of a[2] 9 yields 4, 8, 5. The only element of a that has an absolute difference with each element of b that is always greater than dis element a[2], thus the comparator value is 1.

Function Description: Complete the function comparatorValue in the editor below.
The function must return an integer that denotes the comparator value of the arrays.

ComparatorValue has the following parameter(s): a[a[O],..a[n – 1]]: an array of integers b[b[0],..b[m – 1]]: an array of integers d: an integer

int comparatorValue(vector <int> a, vector<int> b, int d) {
	int count = 0, test = 0;
	for (auto i : a) {
		for (auto j : b) {
			if (abs(i - j) <= d) {
				test += 1;
			}
		}
		if (test == 0) {
			count += 1;
		}
		test = 0;
	}
	return count;
}
