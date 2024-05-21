import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

for _ in range(int(input())):
    N = int(input())
    nums = [input().strip() for _ in range(N)]
    nums.sort()

    for i in range(N-1):
        if len(nums[i]) < len(nums[i+1]) and nums[i+1][:len(nums[i])] == nums[i]:
            print('NO')
            break
    else:
        print('YES')
