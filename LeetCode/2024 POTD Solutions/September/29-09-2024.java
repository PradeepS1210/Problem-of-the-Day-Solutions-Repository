/*
 * Problem of the Day: 432. All O`one Data Structure
 * Problem Description:
 * https://medium.com/@pradeepsooryavanshee1210/432-all-o-one-data-structure-leetcode-solution-ebd69c5225c4
 */

class AllOne {

    private Map<String, Integer> key_count;

    private TreeMap<Integer, LinkedHashSet<String>> count_keys;

    public AllOne() {
        key_count = new HashMap<>();
        count_keys = new TreeMap<>();
    }

    public void inc(String key) {
        int count = key_count.getOrDefault(key, 0);
        key_count.put(key, count + 1);

        if (count > 0) {
            count_keys.get(count).remove(key);
            if (count_keys.get(count).isEmpty()) {
                count_keys.remove(count);
            }
        }

        count_keys.computeIfAbsent(count + 1, k -> new LinkedHashSet<>()).add(key);
    }

    public void dec(String key) {
        if (!key_count.containsKey(key)) {
            return;
        }

        int count = key_count.get(key);
        key_count.put(key, count - 1);

        count_keys.get(count).remove(key);
        if (count_keys.get(count).isEmpty()) {
            count_keys.remove(count);
        }

        if (count == 1) {
            key_count.remove(key);
        } else {
            count_keys.computeIfAbsent(count - 1, k -> new LinkedHashSet<>()).add(key);
        }
    }

    public String getMaxKey() {
        if (count_keys.isEmpty()) {
            return "";
        }
        return count_keys.lastEntry().getValue().iterator().next();
    }

    public String getMinKey() {
        if (count_keys.isEmpty()) {
            return "";
        }
        return count_keys.firstEntry().getValue().iterator().next();
    }
}