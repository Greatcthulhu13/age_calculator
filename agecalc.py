from datetime import datetime

# Age calculator

def is_leap_year(input_year):
    div_4 = input_year % 4
    div_100 = input_year % 100
    div_400 = input_year % 400
    
    if (div_4 == 0 and div_100 != 0) or div_400 == 0:
        print(f"{input_year} is a leap year")
        return True
    else:
        print(f"{input_year} is not a leap year")
        return False

def calculate_age(dob_day, dob_month, dob_year):
    days_in_mon = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

    # Get current date
    current_date = datetime.now()
    
    # Calculate days remaining in birth month
    days = days_in_mon[dob_month - 1] - dob_day + 1

    # Check for leap year
    if is_leap_year(dob_year):
        days += 1

    # Calculate the age in number of years, months & days
    days += current_date.day
    months = (12 - dob_month) + current_date.month
    years = current_date.year - dob_year - 1

    # Check for leap year in the current year
    if is_leap_year(current_date.year):
        if days >= (days_in_mon[current_date.month - 1] + 1):
            days -= (days_in_mon[current_date.month - 1] + 1)
            months += 1
    elif days >= days_in_mon[current_date.month - 1]:
        days -= days_in_mon[current_date.month - 1]
        months += 1

    if months >= 12:
        years += 1
        months -= 12

    # Print age
    print(f"\n## You are exactly {years} years {months} months and {days} days old. ##")

# User enters DOB
dob_str = input("Enter your date of birth (DD/MM/YYYY): ")
dob_day, dob_month, dob_year = map(int, dob_str.split('/'))

# Calculate age
calculate_age(dob_day, dob_month, dob_year)
