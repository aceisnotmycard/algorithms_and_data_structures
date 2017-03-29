def next_combination(combination, n):
    """
    Based on http://e-maxx.ru/algo/generating_combinations
    """
    k = len(combination)
    for i in range(k-1, -1, -1):
        if combination[i] < n - k + i:
            combination[i] += 1
            for j in range(i+1, k):
                combination[j] = combination[j-1] + 1
            return True
    return False

k, n = map(int, input().split(' '))
combination = [i for i in range(k)]
print(' '.join(map(str, combination)))
while next_combination(combination, n):
    print(' '.join(map(str, combination)))
