#1 Jan 1900 was a monday
#1 Jan 1901 was a tuesday
day_of_the_week = {0 : "tue", 1 : "thu", 2 : "wed", 3 : "fri", 4 : "sat", 5 : "sun", 6 : "mon"}
days_in_a_month = [31 ,28,31 ,30,31,30,31,31,30,31,30,31]
days = 0
sundays_on_the_first_of_the_month = 0
for year in range (1901,2001):
    for month in range(12):
        if(day_of_the_week[days % 7] == "sun"):
            sundays_on_the_first_of_the_month+=1
        #Leap year
        if(month == 28):
            if((year % 4 == 0 and year % 100 !=0) or (year % 400 == 0)):
                days += 1
        days += days_in_a_month[month]
    

print(f"Total sundays: {sundays_on_the_first_of_the_month}")