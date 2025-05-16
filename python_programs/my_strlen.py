
def my_strlen(data):
    cnt = 0

    for char in data:
        cnt +=1
    return cnt

def main():
    name = input("Enter name\n")
    val = my_strlen(name)
    print("strlen is:",int(val))

if __name__ == "__main__":
    main()

