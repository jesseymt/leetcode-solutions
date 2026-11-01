/*
 * LeetCode #0853 - Car Fleet
 * https://leetcode.com/problems/car-fleet/
 *
 * Difficulty: Medium
 * Topic: Array, Sorting, Monotonic Stack
 * Time: O(N log N) | Space: O(N)
 *
 * Approach:
 * Calculate each car's time to reach the target using
 * (target - position) / speed.
 * Store each car's position and arrival time as a pair.
 *
 * Sort the cars by position and traverse backward,
 * starting with the car closest to the target.
 *
 * Track the arrival time of the last fleet formed.
 * If the current car's arrival time is greater than
 * lastFleetTime, it cannot catch the fleet ahead,
 * so increment the fleet count and update lastFleetTime.
 *
 * Otherwise, the car joins the existing fleet.
 * Return the total number of fleets.
 */

#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>> cars;
        for(int i = 0; i < n; i++){
            double hours = static_cast<double>(target - position[i]) / speed[i];
            cars.push_back({position[i], hours});
        }
        sort(cars.begin(), cars.end());
        double lastFleetTime = 0;
        int fleets = 0;
        for(int i = n-1; i>=0; i--){
            if(cars[i].second > lastFleetTime){
                lastFleetTime = cars[i].second;
                fleets++;
            }
        }
        return fleets;
    }
};