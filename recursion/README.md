# Subsets Backtracking — Deep Step‑by‑Step Walkthrough (nums = [1,2,3])

This document contains:
1. The corrected C++ code (one small fix).  
2. A line‑by‑line explanation of *what each line does*.  
3. A **no‑code, full execution trace**: every push/pop/recursive call for `nums = [1,2,3]`, showing the working `ans`, the call stack behavior, and exactly when `allSubsets` gets a new subset.

---

## 1) Corrected code (one tiny fix)
```cpp
class Solution {
public:
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets) {
        if (i == nums.size()) {
            allSubsets.push_back(ans); // <<-- push the current subset (copy of ans)
            return;
        }

        // 1) CHOICE: include nums[i]
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, allSubsets);

        // 2) BACKTRACK: undo the include
        ans.pop_back();

        // 3) CHOICE: exclude nums[i]
        getAllSubsets(nums, ans, i + 1, allSubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> ans;
        getAllSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};
```

**Why the small fix?** In your original snippet `allSubsets.push_back({ans});` creates a `vector<vector<int>>` containing `ans` as one element — that compiles oddly and may be wrong depending on types; the canonical and intended call is `allSubsets.push_back(ans);` which copies the `vector<int> ans` into the list of subsets.

---

## 2) Line‑by‑line: what the code does (short & exact)
- `getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets)`
  - `nums` is the input array shared across calls.
  - `ans` is the *current partial subset* (a single vector passed by reference and mutated).
  - `i` is the current index we're deciding about (we must decide whether to include `nums[i]` or not).
  - `allSubsets` collects the final subsets (copied at base cases).

- `if (i == nums.size())` → **base case**: we've made a decision for every index (there are no more elements). At this leaf we record the current subset `ans` into `allSubsets` and return to the caller.

- `ans.push_back(nums[i]);` → **choose to include** the element at index `i`. This mutates `ans` so that it now reflects that choice.

- `getAllSubsets(nums, ans, i + 1, allSubsets);` → **recurse** to decide about the next index with the current choice included.

- `ans.pop_back();` → **backtrack**: undo the previous include so the `ans` vector returns to the exact state it had before the include. This is crucial — it preserves the invariant that `ans` contains selected elements only from indices `< i` when we move on to the exclude choice.

- `getAllSubsets(nums, ans, i + 1, allSubsets);` → **exclude** branch: now we recurse without `nums[i]` in `ans` and decide for the next indices.

- `subsets(...)` initializes `ans` empty, `allSubsets` empty, and calls `getAllSubsets(..., i=0)` to start the decisions from the first element.

**Invariant at every call:** At the moment you call `getAllSubsets(..., i = k, ans = X)`, the vector `X` contains exactly those elements chosen from indices `0..k-1`.

---

## 3) No‑code, full execution trace for `nums = [1,2,3]`
Below is a **chronological** list of every important action in the program. For brevity we label the function call as `G(i, ans)` meaning `getAllSubsets(..., i, ans, ...)`.

- **Start**: `Call G(0, [])` where `ans = []`, `allSubsets = []`.

1. At `G(0, [])`: `i=0 < 3` → do `ans.push_back(nums[0])` → `ans = [1]`.
2. Recurse: `Call G(1, [1])`.

3. At `G(1, [1])`: `i=1 < 3` → `ans.push_back(nums[1])` → `ans = [1,2]`.
4. Recurse: `Call G(2, [1,2])`.

5. At `G(2, [1,2])`: `i=2 < 3` → `ans.push_back(nums[2])` → `ans = [1,2,3]`.
6. Recurse: `Call G(3, [1,2,3])`.

7. At `G(3, [1,2,3])`: `i==3` → **base case** → `allSubsets.push_back([1,2,3])`.  
   Now `allSubsets = [[1,2,3]]`.
8. Return from `G(3)` to the caller (which is `G(2, [1,2,3])`).

9. Back in `G(2, [1,2,3])`: execute `ans.pop_back()` → `ans` becomes `[1,2]` (undo include of `3`).
10. Now call the exclude branch: `Call G(3, [1,2])`.

11. At `G(3, [1,2])`: base case → `allSubsets.push_back([1,2])`.  
    Now `allSubsets = [[1,2,3], [1,2]]`.
12. Return from `G(3)` to `G(2)`; `G(2)` finishes and returns to `G(1, [1,2])`.

13. Back in `G(1, [1,2])`: after returning from include/exclude at index 2, we do `ans.pop_back()` to undo the include of `2` → `ans` becomes `[1]`.
14. Now call the exclude branch for index 1: `Call G(2, [1])`.

15. At `G(2, [1])`: `i=2 < 3` → `ans.push_back(nums[2])` → `ans = [1,3]`.
16. Recurse: `Call G(3, [1,3])`.

17. At `G(3, [1,3])`: base case → `allSubsets.push_back([1,3])`.  
    Now `allSubsets = [[1,2,3], [1,2], [1,3]]`.
18. Return to `G(2, [1,3])` and execute `ans.pop_back()` → `ans = [1]`.
19. Call exclude branch: `Call G(3, [1])`.

20. At `G(3, [1])`: base case → `allSubsets.push_back([1])`.  
    Now `allSubsets = [[1,2,3], [1,2], [1,3], [1]]`.
21. Return to `G(3)` caller; that returns up to `G(1)`, which then returns to `G(0, [1])`.

22. Back in `G(0, [1])` final step for index 0: execute `ans.pop_back()` to undo include of `1` → `ans = []`.
23. Now do the exclude branch for index 0: `Call G(1, [])`.

24. At `G(1, [])`: `i=1 < 3` → `ans.push_back(nums[1])` → `ans = [2]`.
25. Recurse: `Call G(2, [2])`.

26. At `G(2, [2])`: `i=2 < 3` → `ans.push_back(nums[2])` → `ans = [2,3]`.
27. Recurse: `Call G(3, [2,3])`.

28. At `G(3, [2,3])`: base case → `allSubsets.push_back([2,3])`.  
    Now `allSubsets = [[1,2,3], [1,2], [1,3], [1], [2,3]]`.
29. Return; `ans.pop_back()` in `G(2)` → `ans = [2]`.
30. Call exclude branch: `Call G(3, [2])`.

31. At `G(3, [2])`: base case → `allSubsets.push_back([2])`.  
    Now `allSubsets = [[1,2,3], [1,2], [1,3], [1], [2,3], [2]]`.
32. Return to `G(1)`, then `G(1)` does `ans.pop_back()` → `ans = []`.
33. Now `G(1)` exclude branch -> `Call G(2, [])`.

34. At `G(2, [])`: `i=2 < 3` → `ans.push_back(nums[2])` → `ans = [3]`.
35. Recurse: `Call G(3, [3])`.

36. At `G(3, [3])`: base case → `allSubsets.push_back([3])`.  
    Now `allSubsets = [[1,2,3], [1,2], [1,3], [1], [2,3], [2], [3]]`.
37. Return; `ans.pop_back()` → `ans = []`.
38. Call exclude branch: `Call G(3, [])`.

39. At `G(3, [])`: base case → `allSubsets.push_back([])`.  
    Final `allSubsets = [[1,2,3], [1,2], [1,3], [1], [2,3], [2], [3], []]`.
40. All recursion unwinds and `subsets()` returns `allSubsets` to the caller.

**Notice the order:** Because this implementation always recurses the *include* branch before the *exclude* branch, subsets appear in the order shown above. Different traversal orders (exclude-first or index ordering) produce different but equally correct orders.

---

## Key invariants & why backtracking works (short & precise)
- At `G(i, ans)`, `ans` represents the chosen elements from indices `0..i-1` (no more, no less).
- `ans.push_back(nums[i])` temporarily expands that chosen-set to include `nums[i]` for the include branch.
- `ans.pop_back()` restores `ans` to the exact state it had when the function was entered — that allows the exclude branch to start from the correct prefix.
- Each **leaf** (when `i == nums.size()`) corresponds to a unique sequence of include/exclude choices producing one distinct subset. There are `2^n` leaves for `n` elements — that matches the number of subsets.

---

## Quick debugging tips (if you get confused)
- Print `i`, `ans` on every entry of `getAllSubsets` and print `allSubsets` on base case. That shows the exact recursion path.
- If `allSubsets` has duplicates unexpectedly, check whether your input `nums` contains duplicates — this algorithm treats equal numbers as distinct positions. To avoid duplicate subset *values*, sort and skip duplicates at the same recursion level.
- If the order matters, change the order of include/exclude or reorder `nums`.

---