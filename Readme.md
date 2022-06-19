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
Set a variable
```
SET_VARIABLE|variable_name|new_value
```
Add a static value to a variable (in development)
```
ADD_TO_VARIABLE:STATIC|variable_name|static_value
```
Add a variable to another variable (in development)
```
ADD_TO_VARIABLE:VARIABLE|variable_name|other_variable_name
```
Substract a static value from a variable (in development)
```
SUBTRACT_FROM_VARIABLE:STATIC|variable_name|static_value
```
Substract a variable from another variable (in development)
```
SUBTRACT_FROM_VARIABLE:VARIABLE|variable_name|other_variable_name
```
Multiply a variable by a static value (in development)
```
MULTIPLY_VARIABLE:STATIC|variable_name|static_value
```
Multiply a variable by another variable (in development)
```
MULTIPLY_VARIABLE:VARIABLE|variable_name|other_variable_name
```
Divide a variable by a static value (in development)
```
DIVIDE_VARIABLE:STATIC|variable_name|static_value
```
Divide a variable by another variable (in development)
```
DIVIDE_VARIABLE:VARIABLE|variable_name|other_variable_name
```
## Comments
To comment a line of code, simply start the line with `//` like so
```
//PRINT|Hello World
```
