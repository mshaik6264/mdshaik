# explain all oops conecpt in one program

from abc import ABC , abstractmethod

#1. Abstraction: using abstract base class
class Account(ABC):
    def __init__(self,owner,balance):
        self._owner = owner   #Encapsulation us _ for protect variable
        self._balance = balance

    @abstractmethod

    def account_type(self):
        pass

    def deposit(self,amount):
        self._balance += amount
        print(f"{amount} is deposited, New balance is : {self._balance}")

    def get_balance(self):
        return self._balance

#2. Inhertance : savings and current inherits from Account
class SavingsAccount(Account):
    def account_type(self):
        return "Saving_Account"
    
    #3. Polymorphism : method overriding
    def deposite(self,amount):
        bonus = 10
        self._balance += amount + bonus
        print(f"{amount} is deposited with Bonus, New balance is : {self._balance}")

class CurrentAccount(Account):
    def account_type(self):
        return "Current Account"

#4. Polymorphism: method overloading using default argument
def show_account_details(account, show_balance = True):
    print(f"owner : {account._owner}")
    print(f"account Type : {account.account_type()}")
    if show_balance:
        print(f"Balance : {account.get_balance()}")
    print("-" * 32)

#5. Object creation (object and clss)
savings = SavingsAccount("mdshaik",4000)
current = CurrentAccount("mdtalha",3000)

# function calls
savings.deposit(1000)   #overriden method with bonus
current.deposit(500)    #Base method

#show details
show_account_details(savings)
show_account_details(current, show_balance = True)

