class Solution {
    // This method modifies the array by multiplying the smallest elements k times with a given multiplier
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        int n = nums.length;

        // Priority queue to maintain elements in ascending order based on value,
        // with a tie-breaker based on their original index
        PriorityQueue<int[]> pq = new PriorityQueue<>(
            (a, b) -> {
                if (a[0] == b[0]) return a[1] - b[1]; // Compare indices if values are equal
                return a[0] - b[0]; // Otherwise, compare based on values
            }
        );

        // Add all elements of nums along with their indices into the priority queue
        for (int i = 0; i < n; i++) {
            pq.offer(new int[]{nums[i], i});
        }

        // Perform the operation k times
        while (k-- > 0) {
            // Poll the smallest element from the queue
            int[] t = pq.poll();
            int v = t[0]; // Value of the smallest element
            int i = t[1]; // Index of the smallest element

            // Update the value in the original array by multiplying with the multiplier
            nums[i] = v * multiplier;

            // Push the updated value back into the priority queue
            pq.offer(new int[]{nums[i], i});
        }

        // Return the modified array
        return nums;
    }
}