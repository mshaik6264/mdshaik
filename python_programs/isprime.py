
def checkprime(n):
    if n<=1:
        return False
    for i in range(2,int(n**0.5) + 1):
        if n % i == 0:
            return False

    return True

def main():
    val = int(input("Enter any digit\n"))
    res = checkprime(val)
    if res == True :
        print("Prime Number\n")
    else :
        print("Not a Prime Number\n")

if __name__ == "__main__":
    main()
