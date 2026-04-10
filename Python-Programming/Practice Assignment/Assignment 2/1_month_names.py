# Program to create a dictionary with month names as keys and number of days as values

def create_month_dict():
    # Dictionary with months and their respective days
    months_days = {
        "January": 31,
        "February": 28,  # Assuming a non-leap year
        "March": 31,
        "April": 30,
        "May": 31,
        "June": 30,
        "July": 31,
        "August": 31,
        "September": 30,
        "October": 31,
        "November": 30,
        "December": 31
    }
    
    print("Dictionary of Months and Days:")
    print(months_days)

if __name__ == "__main__":
    create_month_dict()

"""
EXPECTED OUTPUT:
Dictionary of Months and Days:
{'January': 31, 'February': 28, 'March': 31, 'April': 30, 'May': 31, 'June': 30, 'July': 31, 'August': 31, 'September': 30, 'October': 31, 'November': 30, 'December': 31}
"""
