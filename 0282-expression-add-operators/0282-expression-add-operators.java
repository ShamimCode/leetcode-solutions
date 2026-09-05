class Solution {
    public List<String> addOperators(String num, int target) {
        List<String> ans = new ArrayList<>();
        solve(num, target, 0, 0, 0, "", ans);
        return ans;
    }

    private void solve(String num,
            int target,
            int idx,
            long curr,
            long prev,
            String expression,
            List<String> ans) {

        if (idx == num.length()) {
            if (curr == target) {
                ans.add(expression);
            }
            return;
        }

        for (int i = idx; i < num.length(); i++) {

            if (i > idx && num.charAt(idx) == '0')
                break;

            String part = num.substring(idx, i + 1);
            long number = Long.parseLong(part);

            if (idx == 0) {
                solve(num,
                        target,
                        i + 1,
                        number,
                        number,
                        part,
                        ans);
            } else {

                // +
                solve(num,
                        target,
                        i + 1,
                        curr + number,
                        number,
                        expression + "+" + part,
                        ans);

                // -
                solve(num,
                        target,
                        i + 1,
                        curr - number,
                        -number,
                        expression + "-" + part,
                        ans);

                // *
                solve(num,
                        target,
                        i + 1,
                        curr - prev + prev * number,
                        prev * number,
                        expression + "*" + part,
                        ans);
            }
        }
    }
}