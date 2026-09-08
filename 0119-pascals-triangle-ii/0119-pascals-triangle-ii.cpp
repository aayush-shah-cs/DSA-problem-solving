class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Initialize the vector with 1s of size (rowIndex + 1)
        vector<int> row(rowIndex + 1, 1);
        
        // Update values in-place from row 2 up to rowIndex
        for (int i = 2; i <= rowIndex; ++i) {
            for (int j = i - 1; j > 0; --j) {
                row[j] += row[j - 1];
            }
        }
        
        return row;
    }
};