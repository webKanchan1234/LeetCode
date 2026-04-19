class Solution {
    public String reverseWords(String s) {
        List<String> words = Arrays.asList(s.trim().split("\\s+"));
        return IntStream.range(0, words.size())
                        .mapToObj(i -> words.get(words.size() - 1 - i))
                        .collect(Collectors.joining(" "));
    }
}