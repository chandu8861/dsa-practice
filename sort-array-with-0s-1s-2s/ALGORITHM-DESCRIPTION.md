# Dutch National Flag Algorithm — Sorting Colors

This repository contains an **O(n)** time, **O(1)** space solution to the "Sort Colors" problem using the **Dutch National Flag Algorithm**.

We sort an array containing only `0`, `1`, and `2` (representing Red, White, and Blue) **in-place** without using extra space.

---

## 🧠 Algorithm Principle 
Imagine you have a pile of balls:

* **Red** balls = `0`
* **White** balls = `1`
* **Blue** balls = `2`

You want all reds first, then whites, then blues — **and you want to do it without picking up all balls at once and sorting**.

So you have three “zones” in your array:

1. **\[0 ... low-1]** → All Reds (`0`)
2. **\[low ... mid-1]** → All Whites (`1`)
3. **\[high+1 ... n-1]** → All Blues (`2`)
4. **\[mid ... high]** → Stuff we haven’t looked at yet (unsorted)

We will:

* Start with `low = 0`, `mid = 0`, `high = n-1`
* Look at `nums[mid]`:

  * If it's `0` → swap with `nums[low]`, move both `low` and `mid` forward.
  * If it's `1` → just move `mid` forward.
  * If it's `2` → swap with `nums[high]`, move `high` backward **(but do NOT move `mid` yet!)**.

Keep doing this until `mid > high`.

---

## ⏳ Dry Run Example

**Input:**

```
[1, 0, 0, 2, 1, 2, 1, 2, 0, 0]
```

`low = 0, mid = 0, high = 9`

| Step | nums                            | low | mid | high | Action                                       |
| ---- | ------------------------------- | --- | --- | ---- | -------------------------------------------- |
| 0    | \[1, 0, 0, 2, 1, 2, 1, 2, 0, 0] | 0   | 0   | 9    | nums\[mid] = 1 → mid++                       |
| 1    | \[1, 0, 0, 2, 1, 2, 1, 2, 0, 0] | 0   | 1   | 9    | nums\[mid] = 0 → swap(mid,low), low++, mid++ |
| 2    | \[0, 1, 0, 2, 1, 2, 1, 2, 0, 0] | 1   | 2   | 9    | nums\[mid] = 0 → swap(mid,low), low++, mid++ |
| 3    | \[0, 0, 1, 2, 1, 2, 1, 2, 0, 0] | 2   | 3   | 9    | nums\[mid] = 2 → swap(mid,high), high--      |
| 4    | \[0, 0, 1, 0, 1, 2, 1, 2, 0, 2] | 2   | 3   | 8    | nums\[mid] = 0 → swap(mid,low), low++, mid++ |
| 5    | \[0, 0, 0, 1, 1, 2, 1, 2, 0, 2] | 3   | 4   | 8    | nums\[mid] = 1 → mid++                       |
| 6    | \[0, 0, 0, 1, 1, 2, 1, 2, 0, 2] | 3   | 5   | 8    | nums\[mid] = 2 → swap(mid,high), high--      |
| 7    | \[0, 0, 0, 1, 1, 0, 1, 2, 2, 2] | 3   | 5   | 7    | nums\[mid] = 0 → swap(mid,low), low++, mid++ |
| 8    | \[0, 0, 0, 0, 1, 1, 1, 2, 2, 2] | 4   | 6   | 7    | nums\[mid] = 1 → mid++                       |
| 9    | \[0, 0, 0, 0, 1, 1, 1, 2, 2, 2] | 4   | 7   | 7    | nums\[mid] = 2 → swap(mid,high), high--      |

**Final Output:**

```
[0, 0, 0, 0, 1, 1, 1, 2, 2, 2]
```

---

## 📜 Pseudocode

```
low = 0
mid = 0
high = n - 1

while mid <= high:
    if nums[mid] == 0:
        swap(nums[mid], nums[low])
        low++
        mid++
    else if nums[mid] == 1:
        mid++
    else: # nums[mid] == 2
        swap(nums[mid], nums[high])
        high--
```

---

## 💻 Complexity Analysis

* **Time Complexity:** O(n) — we scan the array only once.
* **Space Complexity:** O(1) — sorting is done in-place.

---
