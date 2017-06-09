
lower = int(input("input lower: "))
upper = int(input("input upper: "))

for num in range(lower, upper + 1):
    if num > 1:
        for i in range(2, num):
            if num % i == 0:
                break
        # `else` will be invoked after `for` completed without `break|return|exception`
        else:
            print(num)
