import java.util.*;

class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
       Set<String> one = new HashSet<>();
       Set<String> two = new HashSet<>();

       for (int i = 0;i < s.length() - 9;i++) {
           String s1 = s.substring(i, i + 10);

           if (!one.add(s1))
               two.add(s1);
       }

       return new ArrayList<>(two);
    }
}