class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        
        // Loop through each character in the string
        for (int i = 0; s[i] != '\0'; ++i) {
            
            // If the stack is not empty and the top of the stack forms a valid pair with the current character
            if (!st.empty() && (st.top() == 'A' || st.top() == 'C') && st.top() == s[i] - 1) {
                // Pop the stack if we find a valid pair (A-B or C-D)
                st.pop();
            } else {
                // Push the current character onto the stack if no pair is found
                st.push(s[i]);
            }
        }
        
        // The remaining characters in the stack represent the minimum length of the modified string
        return st.size();
    }
};
