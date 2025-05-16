
def bubblesort(array):
    n = len(array)
    for i in range(n):

        for j in range(0,n - i - 1):

            if array[j] > array[j+1]:

                temp = array[j]
                array[j] = array[j+1]
                array[j+1] = temp

def main():
    numbers = [2,1,3,5,4]
    print("Before sort:",numbers)
    bubblesort(numbers)
    print("After sort:",numbers)

if __name__ == "__main__":
    main()


