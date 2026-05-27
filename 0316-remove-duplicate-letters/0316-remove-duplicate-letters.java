class Solution {
    public String removeDuplicateLetters(String s) {
        int[] vis = new int[26];
        int[] freq = new int[26];

        for(char ch: s.toCharArray()){
            freq[ch-'a']++;
        }

        Stack<Character> st = new Stack<>();

        for(char ch : s.toCharArray()){
            freq[ch - 'a']--;
            if(vis[ch - 'a'] == 1){
                continue;
            }
            while(!st.empty() && st.peek() > ch && freq[st.peek() - 'a'] > 0){
                vis[st.pop() - 'a'] = 0;
            }
            st.push(ch);
            vis[ch - 'a'] = 1;
        }

        StringBuilder ans = new StringBuilder();
        for(char c : st){
            ans.append(c);
        }

        return ans.toString();
    }
}