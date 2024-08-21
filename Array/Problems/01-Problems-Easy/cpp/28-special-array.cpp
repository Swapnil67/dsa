
bool checkXGreater(int x, std::vector<int> nums) {
  int c = 0;
  int n = nums.size();
  for (int i = 0; i < n; ++i) {
    if (nums[i] >= x)
      c++;
  }
  return c == x;
}

int specialArray(vector<int> &nums) {
  int c = 0;
  int n = nums.size();
  for (int i = 0; i <= n; ++i) {
    int x = i;
    bool ans = checkXGreater(x, nums);
    // std::cout << x << " " << ans << std::endl;
    if (ans)
      return i;
    else
      c = -1;
  }
  return c;
}