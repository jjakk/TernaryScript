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
PRINT|Hello World|NULL
```
Print variable
```
PRINT_VARIABLE|variable_name|NULL
```
## Variables
Create a variable
```
CREATE_VARIABLE|variable_name|variable_value
```
Set a variable
```
SET_VARIABLE|variable_name|new_value
```
## Comments
To comment a line of code, simply start the line with `//` like so
```
//PRINT|Hello World|NULL
```
