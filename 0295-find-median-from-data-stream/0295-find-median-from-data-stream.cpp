class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || num < maxHeap.top()) {
            maxHeap.push(num);

            if(maxHeap.size() - minHeap.size() >= 2) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
        else{
            minHeap.push(num);

            if(minHeap.size() - maxHeap.size() >= 2) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }

    
    double findMedian() {
        int total = maxHeap.size() + minHeap.size();

        if(total%2) {
            if(maxHeap.size() > minHeap.size()) {
                return maxHeap.top();
            }
            else return minHeap.top();
        }    
        double sum = maxHeap.top() + minHeap.top();

        return sum/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */