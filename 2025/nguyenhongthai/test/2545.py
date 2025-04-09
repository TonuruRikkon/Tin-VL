import math

def is_square(x):
    root = int(math.sqrt(x))
    return root * root == x

def chia_mang(arr):
    n = len(arr)
    segments = 0
    current_set = set()
    
    for num in arr:
        valid = True
        for existing in current_set:
            if is_square(num * existing):
                valid = False
                break
        if not valid:
            segments += 1
            current_set = set()
        current_set.add(num)
    
    return segments + (1 if current_set else 0)

# Thử với dữ liệu lớn
n = input()
data = list(map(int, input().split()))
print(chia_mang(data))
