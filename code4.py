# Step 1: Read data from a CSV file and store in a list
def read_csv_file(filename):
    with open(filename, 'r') as file:
        lines = file.readlines()
    return lines

# Step 2: Process student data
def process_student_data(lines):
    student_count = 0
    total_age = 0
    max_age = -1
    min_age = 1000
    oldest_student = ''
    youngest_student = ''
    
    for line in lines[1:]:  # Skip header
        name, age, grade = line.strip().split(',')
        age = int(age)  # Convert age to integer
        student_count += 1
        total_age += age
        
        # Check for oldest student
        if age > max_age:
            max_age = age
            oldest_student = name
        
        # Check for youngest student
        if age < min_age:
            min_age = age
            youngest_student = name
    
    # Calculate average age
    average_age = total_age / student_count if student_count > 0 else 0
    
    return student_count, average_age, oldest_student, max_age, youngest_student, min_age

# Step 3: Write results to a new file
def write_summary_file(student_count, average_age, oldest_student, max_age, youngest_student, min_age):
    with open('student_summary.txt', 'w') as file:
        file.write(f"Number of students: {student_count}\n")
        file.write(f"Average age of students: {average_age:.2f}\n")
        file.write(f"Oldest student: {oldest_student} with age {max_age}\n")
        file.write(f"Youngest student: {youngest_student} with age {min_age}\n")

# Main function to execute the steps
def main():
    input_filename = 'students_info.csv'
    
    # Read data from CSV file
    lines = read_csv_file(input_filename)
    
    # Process student data
    student_count, average_age, oldest_student, max_age, youngest_student, min_age = process_student_data(lines)
    
    # Write results to new file
    write_summary_file(student_count, average_age, oldest_student, max_age, youngest_student, min_age)
    
    print(f"Data has been processed and saved to 'student_summary.txt'.")

if __name__ == '__main__':
    main()
