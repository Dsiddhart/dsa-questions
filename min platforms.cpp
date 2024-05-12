//**********Minimum Number of Platforms Required for a Railway/Bus Station/////*********

// first method
// C++ program to implement the above approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find the minimum number of platforms 
// required 
int findPlatformOptimized(int arr[], int dep[], int n) 
{ 
	int count = 0, maxPlatforms = 0; 
	// Find the maximum departure time 
	int maxDepartureTime = dep[0]; 
	for (int i = 1; i < n; i++) { 
		maxDepartureTime = max(maxDepartureTime, dep[i]); 
	} 

	// Create a vector to store the count of trains at each 
	// time 
	vector<int> v(maxDepartureTime + 2, 0); 

	// Increment the count at the arrival time and decrement 
	// at the departure time 
	for (int i = 0; i < n; i++) { 
		v[arr[i]]++; 
		v[dep[i] + 1]--; 
	} 

	// Iterate over the vector and keep track of the maximum 
	// sum seen so far 
	for (int i = 0; i <= maxDepartureTime + 1; i++) { 
		count += v[i]; 
		maxPlatforms = max(maxPlatforms, count); 
	} 

	return maxPlatforms; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = { 100, 300, 600 }; 
	int dep[] = { 900, 400, 500 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << findPlatformOptimized(arr, dep, n); 
	return 0; 
}
// Time Complexity: O(n), where n is the number of trains. The algorithm iterates over the input arrays once to update the vector, and then iterates over the vector once to calculate the cumulative sum. Both iterations take O(n) time. The space complexity of the algorithm is O(1) as the vector used has a fixed size.
// Auxiliary space: O(maxDepartureTime), as we create a vector of size maxDepartureTime+2 to store the count of trains at each time.


//*****second method******//
// Program to find minimum number of platforms 
// required on a railway station 
#include <algorithm> 
#include <iostream> 

using namespace std; 

// Returns minimum number of platforms required 
int findPlatform(int arr[], int dep[], int n) 
{ 
	// Sort arrival and departure arrays 
	sort(arr, arr + n); 
	sort(dep, dep + n); 

	// plat_needed indicates number of platforms 
	// needed at a time 
	int plat_needed = 1, result = 1; 
	int i = 1, j = 0; 

	// Similar to merge in merge sort to process 
	// all events in sorted order 
	while (i < n && j < n) { 
		// If next event in sorted order is arrival, 
		// increment count of platforms needed 
		if (arr[i] <= dep[j]) { 
			plat_needed++; 
			i++; 
		} 

		// Else decrement count of platforms needed 
		else if (arr[i] > dep[j]) { 
			plat_needed--; 
			j++; 
		} 

		// Update result if needed 
		if (plat_needed > result) 
			result = plat_needed; 
	} 

	return result; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 900, 940, 950, 1100, 1500, 1800 }; 
	int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << findPlatform(arr, dep, n); 
	return 0; 
}
//Time Complexity: O(N * log N), One traversal O(n) of both the array is needed after sorting O(N * log N).


// 3rd method using heap//

// C++ program to implement the above approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find the minimum number 
// of platforms required 
int findPlatform(int arr[], int dep[], int n) 
{ 
	// Store the arrival and departure time 
	vector<pair<int, int> > arr2(n); 

	for (int i = 0; i < n; i++) { 
		arr2[i] = { arr[i], dep[i] }; 
	} 

	// Sort arr2 based on arrival time 
	sort(arr2.begin(), arr2.end()); 

	priority_queue<int, vector<int>, greater<int> > p; 
	int count = 1; 
	p.push(arr2[0].second); 

	for (int i = 1; i < n; i++) { 

		// Check if arrival time of current train 
		// is less than or equals to departure time 
		// of previous train 
		if (p.top() >= arr2[i].first) { 
			count++; 
		} 
		else { 
			p.pop(); 
		} 
		p.push(arr2[i].second); 
	} 

	// Return the number of trains required 
	return count; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = { 900, 940, 950, 1100, 1500, 1800 }; 
	int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << findPlatform(arr, dep, n); 
	return 0; 
}
// //Time Complexity: O(N*log(N)), Heaps take log(n) time for pushing element and there are n elements.
// Auxiliary Space: O(N), Space required by heap to store the element.

