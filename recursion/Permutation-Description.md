# Permutations — Detailed No‑code Step‑by‑Step Trace for `nums = [1,2,3]`

## 1) Code

```cpp
class Solution {
public:
    void getPermutations (vector<int>& nums, int index, vector<vector<int>>& ans){
        if (index == nums.size()){
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++){
            swap (nums[index], nums[i]);
            getPermutations (nums, index+1, ans);
            swap (nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPermutations (nums, 0, ans);
        return ans;
    }
};
```

---

## 2) What the code does (plain English, no code)

* The function builds all permutations by **fixing** one position at a time.
* At recursion level `index`, positions `0..index-1` are already fixed for the current branch.
* The `for` loop tries every candidate element that can go into position `index` by swapping it in.
* After swapping, it recurses to fix the next position (`index+1`).
* After recursion returns, it **swaps back** to restore the original array so the next candidate can be tried.
* When `index == nums.size()`, the current ordering of `nums` is a complete permutation — the code copies it into the results.

**Invariant:** On entry to `getPermutations(nums, index, ans)`, `nums[0..index-1]` are fixed and will not change within this call.

---

## 3) Detailed chronological trace (calls, swaps, pushes)

Start: `Call getPermutations([1,2,3], index=0, ans=[])`.

1. `G(0,[1,2,3])` — `index=0`, loop `i=0..2`.

2. `i=0`: `swap(nums[0], nums[0])` → `nums = [1,2,3]` (no visible change).

   * Call `G(1,[1,2,3])`.

3. `G(1,[1,2,3])` — `index=1`, loop `i=1..2`.

4. `i=1`: `swap(nums[1], nums[1])` → `nums = [1,2,3]`.

   * Call `G(2,[1,2,3])`.

5. `G(2,[1,2,3])` — `index=2`, loop `i=2..2`.

6. `i=2`: `swap(nums[2], nums[2])` → `nums = [1,2,3]`.

   * Call `G(3,[1,2,3])`.

7. `G(3,[1,2,3])` — `index==n` → **push `[1,2,3]` into `ans`.**

   * `ans = [[1,2,3]]`. Return to `G(2)`.

8. Back in `G(2)`: `swap(nums[2], nums[2])` (undo) → `nums = [1,2,3]`. `G(2)` loop ends, return to `G(1)`.

9. Back in `G(1)`: continue loop, `i=2`: `swap(nums[1], nums[2])` → `nums = [1,3,2]`.

   * Call `G(2,[1,3,2])`.

10. `G(2,[1,3,2])`: `i=2`: `swap(nums[2], nums[2])` → `nums = [1,3,2]`.

    * Call `G(3,[1,3,2])`.

11. `G(3,[1,3,2])`: `index==n` → **push `[1,3,2]`.**

    * `ans = [[1,2,3],[1,3,2]]`. Return to `G(2)`.

12. Back in `G(2)`: undo `swap(nums[2],nums[2])` → `nums = [1,3,2]`. `G(2)` ends, return to `G(1)`.

13. Back in `G(1)`: undo `swap(nums[1],nums[2])` → `nums = [1,2,3]`. `G(1)` loop ends, return to `G(0)`.

14. Back in `G(0)`: continue loop, `i=1`: `swap(nums[0], nums[1])` → `nums = [2,1,3]`.

    * Call `G(1,[2,1,3])`.

15. `G(1,[2,1,3])`: `i=1`: `swap(nums[1],nums[1])` → `nums = [2,1,3]`.

    * Call `G(2,[2,1,3])`.

16. `G(2,[2,1,3])`: `i=2`: `swap(nums[2],nums[2])` → `nums = [2,1,3]`.

    * Call `G(3,[2,1,3])`.

17. `G(3,[2,1,3])`: **push `[2,1,3]`.**

    * `ans = [[1,2,3],[1,3,2],[2,1,3]]`. Return to `G(2)`.

18. Back in `G(2)`: undo (no change). Return to `G(1)`.

19. `G(1)`: next `i=2`: `swap(nums[1],nums[2])` → `nums = [2,3,1]`.

    * Call `G(2,[2,3,1])`.

20. `G(2)`: `i=2`: **push `[2,3,1]` at `G(3)`.**

    * `ans = [[1,2,3],[1,3,2],[2,1,3],[2,3,1]]`. Return and undo swap → `nums = [2,1,3]`.

21. Back in `G(1)`: undo `swap(nums[1],nums[2])` (restores `[2,1,3]`). `G(1)` ends. Return to `G(0)`.

22. Back in `G(0)`: undo `swap(nums[0],nums[1])` → `nums = [1,2,3]`.

23. `G(0)`: next `i=2`: `swap(nums[0],nums[2])` → `nums = [3,2,1]`.

    * Call `G(1,[3,2,1])`.

24. `G(1,[3,2,1])`: `i=1`: `swap(nums[1],nums[1])` → `nums=[3,2,1]`.

    * Call `G(2)`, then push `[3,2,1]`.
    * `ans` now has `[3,2,1]` appended.

25. `G(1)`: next `i=2`: `swap(nums[1],nums[2])` → `nums=[3,1,2]`.

    * Call `G(2)`, then push `[3,1,2]`.
    * `ans` appended `[3,1,2]`.

26. Undo swaps up the stack to restore original `nums=[1,2,3]`. `G(0)` loop ends.

---

### Final `ans` (order produced)

```
[ [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,2,1],
  [3,1,2] ]
```