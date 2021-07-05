def sqrt(n):
    # 3 iterations of newton's method, hard-coded
    # normalize

    # find highest bit
    highest = 1
    sqrt_highest = 1
    while highest < n:
        highest <<= 2
        sqrt_highest <<= 1

    n /= highest+0.0

    result = (n/4) + 1
    result = (result/2) + (n/(result*2))
    result = (result/2) + (n/(result*2))
    result = (result/2) + (n/(result*2))
    result = (result/2) + (n/(result*2))
    result = (result/2) + (n/(result*2))
    result = (result/2) + (n/(result*2))

    return result*sqrt_highest

print(sqrt(81))