a = "I am Global"

def f():
    global a
    a = "Modified GLobally"
    print(a)

f()
print(a)


'''
Output:
Modified GLobally
Modified GLobally
'''
