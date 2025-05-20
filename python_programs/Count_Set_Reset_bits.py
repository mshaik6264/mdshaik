def print_bin(num):
    if num <= 0: return 0
    for i in range(31,-1,-1):
        print((num>>i)&1 ,end='')
        if i%8==0 and i!=0:
            print(" ",end='')
    print()

def count_set_bit(num):
    if num <= 0: return 0
    cnt = 0
    while num > 0:
        if num & 1:
            cnt +=1
        num >>=1
    return cnt

def count_rset_bit(num):
    if num <=0: return 0
    cnt = 0
    for i in range(31,-1,-1):
        if (num>>i)&1==0:
            cnt +=1
    return cnt

x = int(input("Enter the intger number : "))
print_bin(x)
print(f"Reset bits are:{count_rset_bit(x)}")
print(f"Set bits are:{count_set_bit(x)}")

