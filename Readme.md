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
PRINT:STATIC|Hello World
```
Print a variable's value
```
PRINT:VARIABLE|variable_name
```
Print newline `\n` character
```
PRINT:NEW_LINE
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
Set a variable equal to a static value
```
MODIFY_VARIABLE:SET:STATIC|variable_name|new_value
```
Set a variable equal to the value of another variable
```
MODIFY_VARIABLE:SET:VARIABLE|variable_name|other_variable_name
```
Add a static value to a variable
```
MODIFY_VARIABLE:ADD:STATIC|variable_name|static_value
```
Add a variable to another variable
```
MODIFY_VARIABLE:ADD:VARIABLE|variable_name|other_variable_name
```
Substract a static value from a variable (in development)
```
MODIFY_VARIABLE:SUBTRACT:STATIC|variable_name|static_value
```
Subtract a variable from another variable (in development)
```
MODIFY_VARIABLE:SUBTRACT:VARIABLE|variable_name|other_variable_name
```
## Comments
To comment a line of code, simply start the line with `//` like so
```
//PRINT|Hello World
```
# Examples
## Basic addition calculator
This demo app takes in two decimal numbers and adds them
```
CREATE_VARIABLE|firstNum|0.0
CREATE_VARIABLE|secondNum|0.0
PRINT:STATIC|This is a basic addition calculator app
PRINT:NEW_LINE
PRINT:STATIC|Enter first number: 
INPUT_VARIABLE|firstNum
PRINT:STATIC|Enter second number: 
INPUT_VARIABLE|secondNum
MODIFY_VARIABLE:ADD:VARIABLE|firstNum|secondNum
PRINT:STATIC|The sum of those two numbers is 
PRINT:VARIABLE|firstNum
PRINT:NEW_LINE
```
