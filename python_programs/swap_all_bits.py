def print_binary(num):
    for i in range(31,-1,-1):
        print((num>>i)&1, end='')
        if i%8==0 and i!=0:
            print(" ", end='')
    print()

def swap_bits(num):
    res = 0
    for i in range(0,32):
        res <<= 1
        res |= (num & 1)
        num >>= 1
    return res

def swap_bits_2(num):
    for i in range(16):
        j = 31 - i
        right = (num >> i ) & 1
        left = (num >> j) & 1

        if (right != left):           
            num ^= (1<<i)
            num ^= (1<<j)

    return num

x = int(input("Enter the number to swap : "))

print_binary(x)
x = swap_bits_2(x)
print_binary(x)
