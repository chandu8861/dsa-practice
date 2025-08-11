# Explanation

Imagine:

* You have **N books**.
* Each book has some pages (given in the array).
* You have **M students**.
* You must give **contiguous books** to each student.
* **Goal:** Distribute so that the student who reads the most pages has the least possible pages.

---

## Step 1 — Understanding the Problem

Example:
Books = `{2, 1, 3, 4}`, M = `2`

**One way:**

* Student 1 → `{2, 1, 3}` → 6 pages
* Student 2 → `{4}` → 4 pages
  Max pages any student gets = **6**

**Another way:**

* Student 1 → `{2, 1}` → 3 pages
* Student 2 → `{3, 4}` → 7 pages
  Max pages = **7**

We want the **minimum possible** of these maximums → *might think 5, but actually 6 is correct*:

* `{2, 1, 3}` = 6 ❌ too high for 5 target
* `{2, 1}` = 3 and `{3, 4}` = 7 ❌ too high for 5 target

Binary search will find **6** as the minimal maximum.

---

## Step 2 — Search Range

The answer must be between:

* **Minimum possible pages** → the largest single book (because no student can be given less than that)
* **Maximum possible pages** → sum of all book pages (if only one student reads everything)

Example: `{2, 1, 3, 4}` → Start = 4, End = 10.

---

## Step 3 — Binary Search

We try a middle value (**mid**) as a guess for "maximum pages a student can have".

* If **possible** to allocate books without exceeding mid → try smaller (end = mid - 1)
* If **not possible** → allow more pages (start = mid + 1)

---

## Step 4 — The isValid Function

This function checks: If we allow `maxPages` as the limit per student, can we give all books to M students?

Logic:

* Go through each book.
* If adding book ≤ maxPages → give to current student.
* If it exceeds → start with next student.
* If students used > M → invalid.

---

## Step 5 — Why Binary Search Works

Because:

* If allocation is **possible** for a given maxPages → also possible for any **larger** number.
* If allocation is **impossible** for a given maxPages → impossible for any **smaller** number.

This sorted yes/no behavior makes binary search perfect here.

---

# Walkthrough Example

Books = `{2, 1, 3, 4}`, Students = `2`

**Step 1 — Search Range**

* Start = max book = 4
* End = sum of books = 10

Possible answers: 4 to 10

---

### Iteration 1

mid = (4 + 10) / 2 = **7**

Check maxPages = 7:

* Student 1 → `{2, 1, 3}` = 6 ✅
* Student 2 → `{4}` = 4 ✅

✅ Possible → ans = 7, end = 6

---

### Iteration 2

mid = (4 + 6) / 2 = **5**

Check maxPages = 5:

* Student 1 → `{2, 1}` = 3 ✅
* Student 2 → `{3, 4}` = 7 ❌ → needs extra student → invalid

❌ Not possible → start = 6

---

### Iteration 3

mid = (6 + 6) / 2 = **6**

Check maxPages = 6:

* Student 1 → `{2, 1, 3}` = 6 ✅
* Student 2 → `{4}` = 4 ✅

✅ Possible → ans = 6, end = 5

---

## Binary Search Ends

Loop stops when start > end.
Final answer = **6** (minimum possible maximum pages).

---

## Visual Diagram

```
Step 1:   [4, 10] → mid = 7 → ✅ possible → move end to 6
Step 2:   [4, 6]  → mid = 5 → ❌ not possible → move start to 6
Step 3:   [6, 6]  → mid = 6 → ✅ possible → move end to 5

Result: Minimum possible maximum pages = 6
```