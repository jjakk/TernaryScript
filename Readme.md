![TernaryScript](./logo/logo.svg)
# Getting Started
## Install
To install the TernaryScript interpreter compile `main.c` in the `src` directory. The resulting executable is the TernaryScript interpreter
## File naming
To make your first TernaryScript program create a file with the `.tys` extentions.
<br>
Ex: `helloWorld.tys`
## Running your program
To run your program, type into terminal or command prompt in the directory of the TernaryScript interpreter the following command
<br>
`./TernaryScript <filename>.tys`
# Basics
## Print
Print plain text
```
PRINT|Hello World
```
Print newline `\n` character
```
PRINT_NEW_LINE
```
Print variable
```
PRINT_VARIABLE|variable_name
```
## Variables
Create a variable
```
CREATE_VARIABLE|variable_name|variable_value
```
Take user input and store to a variable
```
INPUT_VARIABLE|variable_name
```
### Modification
Set a variable equal to a static value (in development)
```
MODIFY_VARIABLE:SET:STATIC|variable_name|new_value
```
Set a variable equal to the value of another variable (in development)
```
MODIFY_VARIABLE:SET:VARIABLE|variable_name|other_variable_name
```
## Comments
To comment a line of code, simply start the line with `//` like so
```
//PRINT|Hello World
```
