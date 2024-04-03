import java.util.*;

public class anagramSolution {
    public static List<List<String>> groupAnagram(String[] strings) {
     Map<String,List<String>> map = new HashMap<>();
     for (String str : strings){
         char[] words = str.toCharArray();
         Arrays.sort(words);
         String sortedStr = new String(words);

         if(!map.containsKey(sortedStr))
             map.put(sortedStr,new ArrayList<>());
         map.get(sortedStr).add(str);
     }
    return new ArrayList<>(map.values());
    }

    public static boolean isAnagram(String s, String t) {
        int[] freq = new int[26];
        int index = 0;
        for(int i = 0;i<s.length();i++){
            index = (int) s.charAt(i) - (int) 'a';
            freq[index]+=1;
        }
        for(int i = 0;i<t.length();i++){
            index = (int) t.charAt(i) - (int) 'a';
            if(freq[index]>0)
                freq[index]-=1;
            else if (freq[index]<=0)
                freq[index]+=1;
        }
        return Arrays.stream(freq).sum() == 0;
    }
}
