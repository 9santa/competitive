/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function (nums) {
  const n = nums.length;
  const arr = [];
  nums.sort((a, b) => a - b);

  for (let i = 0; i < n - 2; i++) {
    if (i > 0 && nums[i] === nums[i - 1]) continue;
    for (let l = i + 1, r = n - 1; l < r; ) {
      let sum3 = nums[i] + nums[l] + nums[r];
      if (sum3 === 0) {
        arr.push([nums[i], nums[l], nums[r]]);

        while (l < r && nums[l] === nums[l + 1]) l++;
        while (r > l && nums[r] === nums[r - 1]) r--;

        l++;
        r--;
      } else if (sum3 < 0) l++;
      else if (sum3 > 0) r--;
    }
  }
  return arr;
};
