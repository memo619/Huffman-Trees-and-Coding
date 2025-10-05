# Project 2 RecursiveLists

## Student Information:

Guillermo Rojas<br>
Student ID: 008008657<br>
https://github.com/memo619/Huffman-Trees-and-Coding

## Collaboration & Sources:

This work is primarily my own. I used the following resources for learning, debugging, and comparison

I used geeksforgeeks, stackoverflow, and chatGPT to debug and compare my code when I was getting errors despite my reader being good logically.

I used chatGpt to diagnose an error where words were not being properly tokenized and found that I needed an if statement in my Scanner::Scanner function because it wasnt reading the file correctly. 

I used chatGPT to tell me why a missing else statement in my while (input.get(character)) function was not working properpy before I had a if, if, and then no otherstatement. But this lead to errors where an input like "cat" would output "ca" because the<br>
input.putback(character);<br>
break;<br>

was being executed in every iteration because it was not enclosed within a statement.

I tried using a if, if, else statement but that still resulted in errors because the else matched the wrong statement where if, else if, and else was the most logically sound.

I used online resources mainly for debugging, synxtax help, and concept clarification on how the filereading system worked and where the file was being read from because I was having issues with CMake running on VScode.


## Implementation Details:

The scanner class tokenizes the text files by extracting the text from the files into lowercase letters skipping anything that isnt a word and words like "camp's" were properly tokenized while ignoring any characters that werent words. The tokenize() method constantly calls readWord() to take individual tokens until the input file is exhaust. The method has 2 parts where the first part skips all characters that are not alphabetic until it finds the start of a word which is then converted to lowercase and then added to the token. Part 2 of the method continues building the word by checking subsequent characters and properly checking for ' and properly creatig the words.  

## Testing & Status: 

The way I tested is that I copied the scrips from the directory on blue onto project and copied the sample inputs into my input_output directory using the script provided. I then ran a <br>
bash compile_and_test.bash all_texts.txt
for all the sample texts and got tokens with no output being shown which showed clearly that there was no issues with my code. The tokens then were place in the input_output directory after being compared.