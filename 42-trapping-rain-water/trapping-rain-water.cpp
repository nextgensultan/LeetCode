class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        vector<int> dp(height.size(), 0);
        vector<int> psum(height.size(), 0);
        st.push(0);
        psum[0] = height[0];

        for (int i = 1; i < height.size(); i++)
            psum[i] = psum[i - 1] + height[i];

        for (int i = 1; i < height.size(); i++) {
            while (st.size() && height[st.top()] <= height[i]) {
                dp[i] = max(dp[i], dp[st.top()] +
                                       min(height[i], height[st.top()]) *
                                           (i - st.top() - 1) -
                                       (psum[i - 1] - psum[st.top()]));
                // cout << dp[i] << " - " << i << " - " << st.top() << endl;
                st.pop();
            }
            if (st.size()) {
                dp[i] = max(dp[i], dp[st.top()] +
                                       min(height[i], height[st.top()]) *
                                           (i - st.top() - 1) -
                                       (psum[i - 1] - psum[st.top()]));
                // cout << height[st.top()] << " ------ " <<  dp[i] << endl;
            }

            dp[i] = max(dp[i], dp[i - 1]);
            st.push(i);
        }
        return *max_element(dp.begin(), dp.end());
    }
};