for i in range(10):
    print(i)
print('============')

for i in range(5, 10):
    print(i)
print('============Odd Numbers===========')

for i in range(1, 10, 2):
    print(i)
print('============Even Numbers===========')

for i in range(2, 10, 2):
    print(i)
else:
    print('Default')

for i in range(10):
    if i == 5:
        break
    print(i)
else:
    print('Default')



for i in range(10):
    if i == 5:
        continue
    print(i)
else:
    print('Default')


list1 = [10, 100, 1000]
for x in list1:
    print(x)
else:
    print('Default')
    
name = input("Enter the full name: ")
list2 = name.split()
for x in list2:
    print(x)
else:
    print('Default')

