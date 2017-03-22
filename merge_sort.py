def merge_sort(array, ascending=True):

    def _merge(left, right):
        result = []
        cur = left
        another = right
        cur_idx = 0
        another_idx = 0
        while True:
            if len(cur) == cur_idx:
                result += another[another_idx:]
                break
            if (ascending and cur[cur_idx] > another[another_idx]) or (not ascending and cur[cur_idx] < another[another_idx]):
                cur, another = another, cur
                cur_idx, another_idx = another_idx, cur_idx
            result.append(cur[cur_idx])
            cur_idx += 1
        return result

    if len(array) == 1:
        return array
    else:
        sorted_left = merge_sort(array[:(len(array) // 2)], ascending)
        sorted_right = merge_sort(array[(len(array) // 2):], ascending)
        return _merge(sorted_left, sorted_right)


print(merge_sort([1, 3, 2, 4, 5, -1], True))
