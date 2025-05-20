""" class polomorphism """

class car:
    def __init__(self,fname):
        self.fname = fname

    def move(self):
        print(f"{self.fname} is start")

class boat:
    def __init__(self,fname):
        self.fname = fname

    def move(self):
        print(f"{self.fname} is start")

class bike:
    def __init__(self,fname):
        self.fname = fname

    def move(self):
        print(f"{self.fname} is start")

mycar = car("BMW")
myboat = boat("titanic")
mybike = bike("unicorn")

for x in (mycar,myboat,mybike):
    x.move()
    

