class Solution {
public:

    vector<int> prevSmallerIndex(vector<int>& arr) {

        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> nextSmallerIndex(vector<int>& arr) {

        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        int mod = 1e9 + 7;

        vector<int> left = prevSmallerIndex(arr);
        vector<int> right = nextSmallerIndex(arr);

        long long ans = 0;

        for(int i = 0; i < n; i++) {

            long long leftCount = i - left[i];
            long long rightCount = right[i] - i;

            ans = (ans + arr[i] * leftCount * rightCount) % mod;
        }

        return ans;
    }
};
