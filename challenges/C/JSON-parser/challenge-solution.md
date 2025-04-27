# JSON Parser in C
I have some prior experiences with compiler concepts such as lexical analysis and syntactical analysis from a course I partook in compiler technology, so the concepts needed are not completely foreign to me. I have not, however, finished that course at the time of writing. That is why I think doing this challenge could be helpful for me to get into that headspace again. With that said, below you will find some learning outcomes I hope to gain from this project.

## Learning Outcomes
I will divide the types of outcomes into some different categories to make it simpler for myself and others who may read this.
- Programming: This type of outcome will help me with being more proficient in solving problems and writing code in C.
- Process: What I mean by a process learning outcome is how go about solving the problem itself or rather the way I develop the solution.
- Pipeline: The learing outcomes from how I can setup testing, running my project in a container and setting up github actions for example.


### Programming
- Unit testing in C
- knowledge of error handling
-  knowledge of file handling
- Using and implementing data structures and algorithms in C
### Process
- basic knowledge of implementing test-driven development
- Improved documentation and writing skills
### Pipeline
- Know how to setup a multistage build process
- automated testing using docker
- basic understanding of using github actions

## Step zero
As you already know, I have chosen C as my programming language for this challenge. For this step I will setup a docker compose file and a docker file for running my project as well as the basic files where I will implement my solution. By the end of this step, I will:

- Be able to run my project in a docker container.
- Be able to automatically run tests for the project.
- Know how to do tests in C.
- Have setup all the initial source files.

## Results of Step Zero:
I decided to create two docker files. One for running the tests and one for being able to run the parser on its own. I did not create a docker compose file, since I am not sure it would help me with automating the compilation process. I decided to use a Makefile for automating commands. It is there to rebuild the images when the source files changes, but also to remove the containers or images when using make clean. It had been some time since I last used one, which was good, because I could spend some time writing and learning about how to construct it again. I set up the testing and divided the source files into a file for the json parser functionality and a main.c file for running the parser (without the tests). I found it was unecesary to use CUnit for the tests, since I could have easily done the same with a python script or a bash script. But it gave some practice in writing tests in C, so it was still a good thing to do.

##  Step One:
For this step, I will make my parser be able to handle an invalid empty output and the minimal for a JSON file which is "{}". Solving this step is not difficult, but for the next steps, some knowledge of lexing and parsing will be needed.

## Results of Step One:
I spent a lot of time on debugging and going over my infrastructure again. I had done some initial mistakes when setting up the source files, which led to a lot of debugging to amend those mistakes. For the next step I will spend some time reading in the dragon book to make more informed design decisions for the parser.