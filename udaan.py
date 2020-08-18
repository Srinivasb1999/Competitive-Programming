'''
Movie Ticket Reservation Application
We all have booked movie tickets using the numerous ticket booking apps/websites available today.
This question requires the developer to build an application with achieves this functinality.
The application should have the following support:

1. Add a screen
Ability to register a screen - 
a. screen name
b. number of rows
c. total seats per row 
d. list of aisle seats for each row

screen name is the primary identifier. 
Format for command for adding a screen
add-screen <screen-name> <number-of-rows> <total-seats-per-row> <space separated list of aisle seats>
eg: 
add-screen Screen1 12 10 4 5 8 9
This commands registers a screen with same 'Screen1' which has 12 rows with 10 seats each. Seat numbers 4, 5 , 8 and 9 are aisle seats. 
Response format:
success -> if the request is successful
failure -> if the request fails

2. Reserve seats 
Ability to reserve seats in a screen if they are available
Format for command for reserving seats
reserve-seat <screen-name> <row number> <space separated list of seats to be reserved>
eg: 
reserve-seat Screen1 4 5 6 7
This command reserves seats in 'Screen1', row 4, seats 5, 6 and 7 if they are not already reserved. 
Response format:
success -> if the request is successful
failure -> if the request fails

3. Get unservered seats for a row
Ability to fetch unreserved seats for a row in a given screen
Format for command for getting unreserved seats
get-unreserved-seats <screen-name> <row-number>
eg:
get-unreserved-seats Screen1 4
This command returns the list of unreserved seats in 'Screen1' in row 4. 
Response format:
1 2 3 4 8 9 10


4. Suggest seats based on user preference 
This command suggest contiguous seat numbers based on user's preference. This functionality should take into account aisle seats as well since that will decide if contiguous seats are possible for the user's choice. If no contiguous combination is possible, the response should specify that is it is not feasible to fulfil the request. This functionality should also take into account reserved seats based on functionality 2 
Format for the command to get seat suggestion:
suggest-contiguous-seats <screen-name> <number of seats> <row-number> <choice-of-seat-number>
eg: 
suggest-contiguous-seats Screen1 3 3 4
This commands returns list of 3 contiguous seats from row 3 from 'Screen1' either starting or ending with seat number 4. If no such combination exists, the response should be 'none'
Response format: 
2 3 4
If no seat combination exists: 
none


Sample Input and Output sequence: 

Input: (first line give count of input operations for the run of the application)

9
add-screen Screen1 12 10 4 5 8 9
add-screen Screen2 20 25 3 4 12 13 17 18
reserve-seat Screen1 4 5 6 7
reserve-seat Screen2 13 6 7 8 9 10
reserve-seat Screen2 13 4 5 6
get-unreserved-seats Screen2 13
suggest-contiguous-seats Screen1 3 3 4
suggest-contiguous-seats Screen2 4 12 4
suggest-contiguous-seats Screen2 4 10 3

Output:

success
success
success
success
failure
1 2 3 4 5 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
2 3 4
4 5 6 7
none

 

Note:

1. Keywords in both the input and output formats need to be exact matches (these keywords are case-sensative). Response messages should also be exact string matches 

2. Think of logical depedencies between the different types of requests. Input file can have requests in any order. For example, 'add-screen' command can be called after other requests as well. Your application should take into account relevant entity dependencies and validations associated with it. 
'''

'''
# Sample code to perform I/O:

name = input()                  # Reading input from STDIN
print('Hi, %s.' % name)         # Writing output to STDOUT

# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''

# Write your code here

# Class Screen
class Screen:
    def __init__(self, name, no_of_rows, seats_per_row, aisle_per_row):
        self.name = name
        self.no_of_rows = no_of_rows
        self.seats_per_row = seats_per_row      
        self.aisle_per_row = aisle_per_row      # List of aisle seats
        self.matrix = [[0]*seats_per_row]*no_of_rows

    def reserve_seats(self, row, seats):
        for i in seats:
            if self.matrix[row][i - 1]:
                return 'failure'
        for i in seats:
            self.matrix[row][i - 1] = 1
        return 'success'

    def get_unreserved(self, row):
        unreserved_list = []
        for i in range(self.seats_per_row):
            if not self.matrix[row][i]:
                unreserved_list.append(i + 1)
        return unreserved_list
    
    def suggest(self, continuous, row, start_or_end):
        flag1 = True
        seat_list_1 = []
        for i in range(start_or_end - 1, start_or_end - 1 + continuous):
            seat_list_1.append(i+1)
            if self.matrix[row][i]:
                flag1 = False
        flag2 = True
        seat_list_2 = []
        for i in range(start_or_end - continuous, start_or_end):
            seat_list_2.append(i+1)
            if self.matrix[row][i]:
                flag2 = False
        if flag1 and not flag2:
            print(*seat_list_1)
        elif flag2 and not flag1:
            print(*seat_list_2)
        else: print('none')
            


# START MAIN FUNCTION HERE:

if __name__ == "__main__":
    # Create hash map to map each object to it's name
    hasht = {}

    # Function to add screens to the screens list of objects
    def add_screen(screen_name, no_of_rows, seats_per_row, aisle_per_row):
        if screen_name not in hasht:
            hasht[screen_name] = Screen(screen_name, no_of_rows, seats_per_row, aisle_per_row)
            return 'success'
        else: return 'failure'

    # Inputs taken
    t = int(input())
    inputs = [input() for i in range(t)]


    # Parsing each input
    for i in inputs:
        query, screen_name, *numbers = i.split()
        numbers = list(map(int, numbers))
        if query == 'add-screen':
            output1 = add_screen(screen_name, numbers[0], numbers[1], numbers[2:])
            print(output1)
        elif query == 'reserve-seat':
            output2 = hasht[screen_name].reserve_seats(numbers[0], numbers[1:])
            print(output2) #success or failure
        elif query == 'get-unreserved-seats':
            output3 = hasht[screen_name].get_unreserved(numbers[0])
            print(*output3)
        elif query == 'suggest-contiguous-seats':
            hasht[screen_name].suggest(numbers[0], numbers[1], numbers[2])
            
    # print(*[2,3,4])
    # print(*[4,5,6,7]) 
    # print('none')           
        