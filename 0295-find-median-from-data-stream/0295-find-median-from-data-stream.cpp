class MedianFinder {
public:
    multiset<int> st;
    multiset<int>::iterator mid;
    int n = 0;
    MedianFinder() {}
    
    void addNum(int num) {
        if(st.empty()){
            st.insert(num);
            mid = st.begin();
            n++;
        }
        else{
            st.insert(num);
            if(n%2 == 0 && num >= (*mid)){
                mid++;
            }
            if(n%2 != 0 && num < (*mid)){
                mid--;
            }
            n++;
        }
    }
    
    double findMedian() {
        if(n%2 == 0){
            auto it = mid;
            it++;
            return ((*mid)+ (*it))/2.0;
        }
        return *(mid);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */