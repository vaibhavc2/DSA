// this is a runtime error
// when stack memory is demanded more than available in the system (as stack), then stack overflow occurs

// When a stack overflow occurs, the excess data can corrupt other variables and address data, effectively changing variable values and overwriting return addresses. In some cases, this will cause the program to crash. At other times, the program will continue to run, making it more difficult to troubleshoot the problem once the error is discovered. The longer the program runs, the harder this becomes.

// Some situations when stack overflow occurs:-
// When the function calls itself repeatedly/ recursively (infinite times) without stopping, which causes all the function data (local variables, parameters, and return addresses) stacked up, and the available stack cannot store it.
// When a large number of local variables are declared, or there is a very large array declared in the program resulting in the overflow of stack memory