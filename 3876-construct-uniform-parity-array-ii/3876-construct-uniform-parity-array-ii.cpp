
class Solution {
public:
    bool uniformArray(std::vector<int>& nums1) {
        int min_odd = INT_MAX;
        bool has_odd = false;

        for (int x : nums1) {
            if (x % 2 != 0) {
                has_odd = true;
                min_odd = std::min(min_odd, x);
            }
        }

        // If there are no odd numbers, all elements are already even.
        if (!has_odd) {
            return true;
        }

        // Check if we can make all elements odd:
        // Every even number must be strictly greater than min_odd to be able to subtract min_odd.
        bool can_all_odd = true;
        for (int x : nums1) {
            if (x % 2 == 0 && x < min_odd) {
                can_all_odd = false;
                break;
            }
        }

        return can_all_odd;
    }
};