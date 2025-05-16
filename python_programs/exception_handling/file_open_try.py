
try:
    f = open("abcd.txt","w")
    try:
        f.write("MohammadShaik")
    except:
        print("writing failed\n")
    finally:
        f.close()
except:
    print("file is not open successfully\n")
