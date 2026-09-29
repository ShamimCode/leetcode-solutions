class Solution {
    public String removeKdigits(String num, int k) {
        Stack<Character> st = new Stack<>();

        for (char ch : num.toCharArray()) {
            
            while (!st.isEmpty() && 
                    (st.peek() - '0') > (ch - '0') &&
                    k > 0
            ) {
                st.pop();
                k -= 1;
            }

            st.push(ch);
        }

        while (k > 0) {
            st.pop();
            k -= 1;
        }

        // if (st.isEmpty()) {
        //     return "0";
        // }

        StringBuilder ans = new StringBuilder();
        for (char ch : st) {
            ans.append(ch);
        }

        int i = 0;
        while (i < ans.length() && ans.charAt(i) == '0') {
            i++;
        }

        if (i == ans.length()) {
            return "0";
        }

        return ans.substring(i);
    }
}