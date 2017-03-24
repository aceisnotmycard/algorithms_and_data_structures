# Task: find sum of pairwise products

def naive(A):
    sum = 0
    for i in range(len(A)-1):
        for j in range(i+1, len(A)):
            sum += A[i]*A[j]
    return sum

def fast(A):
    sum = 0
    pairwise_sum = 0
    for i in range(len(A)):
        pairwise_sum += A[i]*sum
        sum += A[i]
    return pairwise_sum

array = list(range(1, 10000000))

print(fast(array))