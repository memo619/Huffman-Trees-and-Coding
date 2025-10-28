# Project 3 Huffman Trees and Encoding

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

Used course materials and lecture notes for BST and priority queue algorithms. Referenced C++ documentation for std::sort and std::vector operations.

 Used online resources to understand how to properly traverse the tree for code assignment and pre-order traversal for the header file. ChatGPT helped fix an issue where I was adding an extra newline at the end of the .hdr file which was causing all my header tests to fail. The fix was to remove the extra out << '\n'; line at the end of writeHeader() function since each line already had a newline.


## Implementation Details:

The scanner class tokenizes the text files by extracting the text from the files into lowercase letters skipping anything that isnt a word and words like "camp's" were properly tokenized while ignoring any characters that werent words. The tokenize() method constantly calls readWord() to take individual tokens until the input file is exhaust. The method has 2 parts where the first part skips all characters that are not alphabetic until it finds the start of a word which is then converted to lowercase and then added to the token. Part 2 of the method continues building the word by checking subsequent characters and properly checking for ' and properly creatig the words.  

The BinSearchTree class counts word frequencies using recursive insertion. Each node stores a word and its count. When inserting, if the word exists, its count increments; otherwise a new node is created with count=1. The inorderCollect() method traverses the tree left-node-right to produce lexicographically sorted pairs.

The writeHeader() function writes codes in pre-order traversal as "word code" format. The encode() function replaces each token with its Huffman code and writes the bitstream to the .code file with 80-character line wrapping.


## Testing & Status: 

The way I tested is that I copied the scrips from the directory on blue onto project and copied the sample inputs into my input_output directory using the script provided. I then ran a <br>
bash compile_and_test.bash all_texts.txt
for all the sample texts and got tokens with no output being shown which showed clearly that there was no issues with my code. The tokens then were place in the input_output directory after being compared.Used bash compile_and_test_project3_part2.bash to test 11 input files. Results:
All 11 files tested successfully<br>
Both .tokens and .freq outputs matched references perfectly<br>
Summary: 22 matches, 0 differences<br>
All output files (.tokens, .freq, .hdr, .code) generate correctly for all test cases from small files (14 tokens) to large files (35,484 tokens)