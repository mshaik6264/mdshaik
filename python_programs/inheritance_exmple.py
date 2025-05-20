
class parent:
    def __init__(self,fname,lname):
        self.fname = fname
        self.lname = lname

    def printname(self):
        print(f"Name is : {self.fname} {self.lname}")

class child(parent):
    pass

c1 = child("Mohammads","Shaik")
c1.printname()
