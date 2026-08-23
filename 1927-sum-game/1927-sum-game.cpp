class Solution {
public:
    bool sumGame(string num) {
        int sumL = 0, sumR = 0;
        int qL = 0, qR = 0;
        int n = num.length();

        for (int i = 0; i < n; ++i) {
            if (i < n / 2) {
                if (num[i] == '?') qL++;
                else sumL += num[i] - '0';
            } else {
                if (num[i] == '?') qR++;
                else sumR += num[i] - '0';
            }
        }

        // If total '?' count is odd, Alice makes the last move and can always win
        if ((qL + qR) % 2 != 0) return true;

        // Bob can balance pairs of '?' across halves or force a sum of 9 per pair on the same side
        int diffSum = sumL - sumR;
        int diffQ = qR - qL;

        return diffSum != (diffQ / 2) * 9;
    }
};