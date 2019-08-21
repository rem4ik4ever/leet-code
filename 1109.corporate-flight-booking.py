
def corpFlightBookings(bookings, n):
  # Create list of emtpy values with buffer + 1
  nums = [0] * (n + 1)
  for i, j, k in bookings:
    nums[i - 1] += k
    nums[j] += -k
  for i in range(1, n):
    nums[i] += nums[i - 1]
  return nums[:-1]
  


data = [[1,2,10],[2,3,20],[2,5,25]]
res = corpFlightBookings(data, 5)
print(res)