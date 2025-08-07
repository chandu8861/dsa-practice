Approach
Simply, we calculate max area of rectangle then return it. Formula is

width * height
Let's think about width and height with this example.

Input: height = [1,8,6,2,5,4,8,3,7]
Each number is height, so we can easily get height. But how about width?

width is also simple. It's just distance between two heights. That's why it's good idea to have two pointers left and right.

 0,1,2,3,4,5,6,7,8 (= index)
[1,8,6,2,5,4,8,3,7]
 L               R

Left pointer starts from index 0
Right pointer starts from the last index
Let's see how it works!

width = right - left = 8 - 0 = 8
For height, we take smaller height between left and right, because if we calculate based on the taller height, the water would overflow from the container.

height = min(height[left], height[right]) = min(1, 7) = 1
Current max area should be

8 * 1 = 8
After that, we want to move one of the pointers. How can we judge it? 
It's simple. We want to keep taller height between left and right because there is a possibility that we will get max area with the taller height.

In this case,

left vs right = 1 vs 7
So we move the left pointer to next.

 0,1,2,3,4,5,6,7,8 (= index)
[1,8,6,2,5,4,8,3,7]
   L             R

max_area = 8
We will repeat the same process until we break left < right condition. I'll speed up.

 0,1,2,3,4,5,6,7,8 (= index)
[1,8,6,2,5,4,8,3,7]
   L             R

max_area = 8
current_area = 7 * 7 = 49
max_area = max(8, 49) = 49
Move R to next
 0,1,2,3,4,5,6,7,8 (= index)
[1,8,6,2,5,4,8,3,7]
   L           R

max_area = 49
current_area = 6 * 3 = 18
max_area = max(49, 18) = 49
Move R to next
 0,1,2,3,4,5,6,7,8 (= index)
[1,8,6,2,5,4,8,3,7]
   L         R

max_area = 49
current_area = 5 * 8 = 40
max_area = max(49, 40) = 49
Move L to next 
In the above case, we can also move R instead of L because L and Rare the same(= 8).

 0,1,2,3,4,5,6,7,8 (= index)
[1,8,6,2,5,4,8,3,7]
     L       R

max_area = 49
current_area = 4 * 6 = 14
max_area = max(49, 24) = 49
Move L to next 
 0,1,2,3,4,5,6,7,8 (= index)
[1,8,6,2,5,4,8,3,7]
       L     R

max_area = 49
current_area = 3 * 2 = 6
max_area = max(49, 6) = 49
Move L to next 
 0,1,2,3,4,5,6,7,8 (= index)
[1,8,6,2,5,4,8,3,7]
         L   R

max_area = 49
current_area = 2 * 5 = 10
max_area = max(49, 10) = 49
Move L to next 
 0,1,2,3,4,5,6,7,8 (= index)
[1,8,6,2,5,4,8,3,7]
           L R

max_area = 49
current_area = 1 * 4 = 4
max_area = max(49, 4) = 49
Move L to next 
Now L and R are the same index. We shop iteration.

 0,1,2,3,4,5,6,7,8 (= index)
[1,8,6,2,5,4,8,3,7]
             L
             R 
return 49
