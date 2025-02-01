## Chosen language

For this challenge, I have chosen to solve it in C. I was not familiar with reading from files in C nor how I could handle options given as arguments.
As I am writing this, I have already completed the challenge, which I feel is a mistake, as I now have the dreadful task of having to rememeber the steps I took to solve each part of the challenge. Keep that in mind when reading this, as I will do my best to share my thoughts for each step and the overall reflection at the end.
### Setup
To setup the project I made a include folder which is where I put the .h files that one usually has for projects written in C (although this was a small project and I probably did not need it). I then made  a src and a test folder as well as a Makefile to compile the solution. I put the C source code in the src folder.

All that would translate to this folder structure:
```plaintext
/wc-tool
├── include
│   ├──wc-challenge.h
│
├── src
│   ├── wc-challenge.c
├── test
|   ├── test.txt
├── Makefile
└── README.md
```
I also read the manpage as to understand how to use wc. It takes any number of given files and returns the number of newlines, words and bytes for each file. Using the -c option gives the byte count, -l gives the newline count and -w gives the word count in a given file. For the first few solution steps, these are the only options we need to consider when solving the challenge. Later, when I had to add functionality for my implementation to give word,newline and byte count when no option was specified I realized I could have made a more elegant solution earlier, which led to some rewriting of my code.
## Part 1
In this step I was to develop the -c option for my implementation. At first, I took the help of github copilot to write code and I also tried to be proactive and write some functions for the other coming steps. This did not turn out well, as copilot gave me lots of little bugs to debug. So I started over instead (without the help of copilot), where I first learned how to handle command line arguments, as when I tried to manually write the code for detecting options, it did not work. After some trying, I looked my problem up, and learned about using getopt and optind for handling command-line arguments, which worked nicely. The solution ended up being quite simple
```C
int count_chars(FILE *file) {
    int count = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        count++;
    }
    fclose(file);
    return count;
}
```
## Part 2
Given that I had already learnt about using fgetc and how to interact with files using file pointers and reading the file stream using fgetc, implementing the -l option was not too challenging as I only had to change the code so that the counter would increment everytime i found a newline character. I implemented it like below:

```C
int count_lines(FILE *file) {
    int result =0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            result++;
        }
    }
    fclose(file);
    return result;

}
```
## Part 3
