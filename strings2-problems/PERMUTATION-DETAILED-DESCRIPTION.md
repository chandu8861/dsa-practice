# Permutation in String

This repository contains the solution to the classic **Permutation in String** problem:

> Given two strings `s1` and `s2`, return `true` if `s2` contains a permutation of `s1`, or `false` otherwise.

---

## 1. Logic

The idea is based on the **sliding window** technique with frequency counting:

1. Count the frequency of characters in `s1` (call this `count1`).
2. Take the first window of size `s1.length()` in `s2` and count its characters (`count2`).
3. Slide the window across `s2`:

   * At each step, compare `count1` and `count2`.
   * If they match, it means this window is a permutation of `s1` → return `true`.
   * Otherwise, slide the window:

     * Remove the character going out (leftmost).
     * Add the new character coming in (rightmost).
4. If no window matches, return `false`.

This way, we check **all substrings of length |s1|** in `s2` efficiently.

---

## 2. Detailed Description

* **Why sliding window?**
  Because we only care about substrings of length `|s1|`. Instead of recalculating frequencies for every substring (which would be slow), we reuse the previous window’s frequencies and only update two characters: one removed and one added.

* **Why frequency arrays of size 26?**
  Since the strings consist of lowercase English letters (`a-z`), we use a fixed array of size 26 to store counts. This makes comparison very fast.

* **Time Complexity:**

  * Each character is processed at most twice (once added, once removed).
  * Comparing two arrays takes O(26) = O(1).
  * Total = **O(n)**, where n = `s2.length()`.

* **Space Complexity:**

  * We only use two arrays of fixed size 26.
  * Total = **O(1)**.

---

## 3. Detailed Dry Run with Example

### Example:

```
s1 = "ab"
s2 = "eidbaooo"
```

### Step 1: Initialize frequencies

* `count1` for `s1 = "ab"` → `{a:1, b:1, rest=0}`
* First window in `s2` = "ei" → `count2 = {e:1, i:1}`

Compare → not equal.

---

### Step 2: Slide window

* Window size = 2 (same as `s1.length()`).
* We move one character at a time.

#### Window 1 → "ei"

* `count2 = {e:1, i:1}`
* Compare with `count1 = {a:1, b:1}` → ❌ Not equal.

Slide → remove `e`, add `d` → `count2 = {i:1, d:1}`

---

#### Window 2 → "id"

* `count2 = {i:1, d:1}`
* Compare → ❌ Not equal.

Slide → remove `i`, add `b` → `count2 = {d:1, b:1}`

---

#### Window 3 → "db"

* `count2 = {d:1, b:1}`
* Compare → ❌ Not equal.

Slide → remove `d`, add `a` → `count2 = {b:1, a:1}`

---

#### Window 4 → "ba"

* `count2 = {b:1, a:1}`
* Compare with `count1 = {a:1, b:1}` → ✅ Equal!

Return **true**.

---

### Output

```
true
```

This shows that `s2` contains a permutation ("ba") of `s1` ("ab").