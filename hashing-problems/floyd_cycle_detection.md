
# Floyd’s Tortoise and Hare (Cycle Detection)

## Principle

Floyd’s Tortoise and Hare algorithm (also called the cycle detection algorithm) is a **pointer-based technique** to detect cycles in a sequence.  
It uses two pointers moving at different speeds through the sequence:

- **Tortoise (slow pointer)**: moves one step at a time.  
- **Hare (fast pointer)**: moves two steps at a time.  

If there is a cycle, the fast pointer will eventually meet the slow pointer.  
If there is no cycle, the fast pointer will reach the end.  

---

## Application in Finding Duplicate Numbers

In the problem:

- We are given an array of size `n+1` where numbers are in the range `[1, n]`.  
- This guarantees **at least one duplicate** (Pigeonhole Principle).  
- The array can be interpreted as a **linked list**, where the index points to the next value:
  - From index `i`, the "next node" is `nums[i]`.  
- A duplicate number creates a **cycle** in this linked structure.  

Thus, finding the duplicate = detecting the start of the cycle.

---

## How it Works

1. **Phase 1: Detect Intersection**
   - Move slow (`+1 step`) and fast (`+2 steps`) until they meet inside the cycle.

2. **Phase 2: Find Entry Point**
   - Reset slow to the beginning (`nums[0]`).  
   - Move both slow and fast one step at a time.  
   - The node where they meet is the duplicate number.

---

## Dry Run Example

Input:  
```
nums = [1, 3, 4, 2, 2]
```

Step-by-step:

### Phase 1: Detect Intersection
- slow = nums[0] = 1  
- fast = nums[0] = 1  

Iteration 1:  
- slow = nums[1] = 3  
- fast = nums[nums[1]] = nums[3] = 2  

Iteration 2:  
- slow = nums[3] = 2  
- fast = nums[nums[2]] = nums[4] = 2  

✅ slow == fast at value `2` (intersection found).

### Phase 2: Find Entry Point
- Reset slow = nums[0] = 1  
- fast remains at 2  

Iteration 1:  
- slow = nums[1] = 3  
- fast = nums[2] = 4  

Iteration 2:  
- slow = nums[3] = 2  
- fast = nums[4] = 2  

✅ They meet at value `2`, which is the duplicate.

---

## Complexity Analysis

- **Time Complexity:** O(n)  
  - Both pointers traverse at most `2n` steps.  
- **Space Complexity:** O(1)  
  - Only two pointers are used, no extra data structures.  

---

## Summary

Floyd’s Tortoise and Hare algorithm efficiently detects cycles using two pointers.  
In the duplicate number problem, it maps naturally because the duplicate creates a cycle in the array’s index-to-value mapping.  
This approach avoids extra memory and is optimal in terms of space.
