def my_convertor(x):
    return x * 0.3048   # (0.3048) is the value if multiply any number we will get feet to meter conversion

txt = f"the plane is flying at a {my_convertor(300000):,} meter altitude"
print(txt)
