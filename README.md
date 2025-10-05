# Project 2 RecursiveLists

## Student Information:

Guillermo Rojas
Student ID: 008008657
https://github.com/memo619/Project-2

## Collaboration & Sources:

This work is primarily my own. I used the following resources for learning, debugging, and comparison

I struggled to visualize the function calls recursively even when I understood how the code worked and why it worked so I used ChatGpt to create diagrams to help me understand recursion better and get small examples and explain the ideas of recursion to me. 


I used chatGpt to diagnose errors I had written a recursive call if statement before I checked for if (is_atom(p)) so it was causing an error that I couldn't find because the only error was the order of the  if statements. 

I used this stackoverflow discussion to copy and how to implement premute https://stackoverflow.com/questions/61420151/scheme-generate-all-distinct-permutations-of-a-list it is almost identical to the code I implemented and I used chatGPT to clarify the logic and show me a diagram of how it works


## Implementation Details:

The way this project was implemented was that there is an hpp file that I used to construct functions from and I used contractions like cons(x,y) car(p) cdr(p) and null() to solve all the problems. I used boolean expressions like is_null(p) is_atom(p) eq(a, b) to create if statement to solve the problems as needed. With append being used as a helper in a lot of these problems that I created at the top of the class.

I used base cases to handle null pointers and used recursion to make the problems smaller through cdr or car calls which either goes deeper into the list (car) or goes to the right (cdr)

## Testing & Status: 

I used the example input text to test my code with no issues and I was able to run it mulitple times with simpler inpputs.