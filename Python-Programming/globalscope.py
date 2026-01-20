a = "I am Global"

def f():
    global Aa = "Modified GLobally"
    print(a)

f()
print(a)
