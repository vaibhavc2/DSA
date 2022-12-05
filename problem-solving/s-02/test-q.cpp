// In a university, there is a certain system of credits.Each student is given a 'credit limit' which specifies the maximum credits of a subject they can take.A student can take any number of subjects which are under his / her credit limit.

// There are N students and K subjects.Each subject has a specified number of credits.When a student chooses a subject,
// It becomes a(student, subject) pair.Find the maximum number of possible(subject, student) pairs for the given credit limits and subject credit requirements.

// Input Specification:
// input1: K, denoting the number of subjects
// input2: An array of K elements each denoting the credits to take a subject.
// input3: N, denoting the number of students.
// input4: An array of N elements each denoting the credit limit of a student.

// Output Specification:
// Your function should return the maximum number of possible required pairs.

// Example 1:
// input1: 1
// input2: {48}
// input3: 3
// input4: {28,32,63}

// Output: 1

// Explanation:
// Student 3 can take a subject of credit 63 and less. So student 3 can take subject 1 which is of credit 48.

// Example 2:
// input1: 8
// input2: {44,45,56,39,2,6,17,75}
// input3: 1
// input4: {54}

// Output: 6

// Explanation:
// Student 1 can take subjects with credits (44,45,39,2,6,17) which gives a total of 6 subjects.

// -------------------------------------------------------------------------
