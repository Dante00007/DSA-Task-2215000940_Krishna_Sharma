class Solution {
    public String reverseWords(String s) {
        int i = s.length() - 1;
        int j = s.length();
        StringBuilder ans = new StringBuilder();

        while (i >= 0) {
            if (s.charAt(i) == ' ') {
                int k = i + 1;
                while (k < j) {
                    ans.append(s.charAt(k++));
                }
                if (i + 1 != j) ans.append(' ');
                j = i;
            }
            i--;
        }

        i++;
        while (i < j) {
            ans.append(s.charAt(i));
            i++;
        }

        i = ans.length() - 1;
        while (i >= 0 && ans.charAt(i) == ' ') {
            i--;
        }

        return ans.substring(0, i + 1);
    }
}
