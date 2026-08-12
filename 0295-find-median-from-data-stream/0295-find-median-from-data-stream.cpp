class MedianFinder {
public:
    multiset<int> mt1, mt2;

    MedianFinder() {}

    void addNum(int num) {
        // Initially put the number into mt2
        mt2.insert(num);

        // If mt2 has an element smaller than the largest
        // element of mt1, swap them
        if (!mt1.empty() && !mt2.empty()) {
            int first = *mt2.begin();
            int last = *mt1.rbegin();

            if (first < last) {
                mt2.erase(mt2.find(first));
                mt1.erase(mt1.find(last));

                mt1.insert(first);
                mt2.insert(last);
            }
        }

        // Keep mt1 size >= mt2 size
        if (mt2.size() > mt1.size()) {
            int curr = *mt2.begin();

            mt2.erase(mt2.find(curr));
            mt1.insert(curr);
        }
    }

    double findMedian() {
        if (mt1.size() > mt2.size()) {
            return *mt1.rbegin();
        }

        double left = *mt1.rbegin();
        double right = *mt2.begin();

        return (left + right) / 2.0;
    }
};