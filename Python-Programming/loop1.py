if __name__ == "__main__":
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

if __name__ == "__main__":

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


'''

Output:

0

1

2

3

4

5

6

7

8

9

============

5

6

7

8

9

============Odd Numbers===========

1

3

5

7

9

============Even Numbers===========

2

4

6

8

Default

0

1

2

3

4

0

1

2

3

4

6

7

8

9

Default

10

100

1000

Default

Enter the full name: Default

'''
