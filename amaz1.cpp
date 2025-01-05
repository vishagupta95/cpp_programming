/*
"Amazon Delivery Centers dispatch parcels every day. There are 
 n delivery centers, each with an array parcel[i] representing the number of parcels to be delivered. On each day, an equal number of parcels are dispatched 
from each delivery center that has at least one parcel remaining. Find the minimum number of days to deliver all the parcels from all delivery centers.

Example: parcels = [2, 3, 4, 3, 3], 
n=5 delivery centers. All parcels will be delivered in 3 days.

Day 1: Deliver 2 parcels from each center.
Day 2: Deliver 1 parcel from the remaining centers.
Day 3: Deliver 1 parcel from the remaining centers
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>  // For INT_MAX
using namespace std;

int min_days_to_deliver(vector<int>& parcels) {
    int days = 0;

    // Continue until all parcels are delivered
    while (true) {
        // Find the minimum number of parcels left in any delivery center
        int min_parcel = INT_MAX;
        for (int parcel : parcels) {
            if (parcel > 0) {
                min_parcel = min(min_parcel, parcel);
            }
        }

        // If all parcels are delivered, break the loop
        if (min_parcel == INT_MAX) {
            break;
        }

        // Deliver 'min_parcel' parcels from each delivery center with parcels left
        for (int& parcel : parcels) {
            if (parcel > 0) {
                parcel -= min_parcel;
            }
        }

        // Increment the day count
        days++;
    }

    return days;
}

int main() {
    vector<int> parcels = {2, 3, 4, 3, 3};  // Example: parcels at each delivery center
    int result = min_days_to_deliver(parcels);
    cout << "Minimum days to deliver all parcels: " << result << endl;
    return 0;
}

