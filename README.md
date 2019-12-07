# Xgl - Xg Integration Language

## Introduction

Xgl is the integration language used by the Xg Game Engine.  It is a free format language that resembles "c-Language" and "Java" syntax.  

Xgl is not a compiled or interpreted language, but is translated into a in-memory tree structured that can be executed.  The tree structure can actually be created by either translating the Xgl code or programmatically by invoking the correct library classes to build the in-memory tree structure.

## First Program - Hello World

The first program that we will execute is the proverbial "Hello, World."

```
program;
  print "Hello, World!";
end;
```
This program uses three Xgl commands to print the text "Hello, World" to the console.  The first line, defines the program.  The second line actually executes the text printing.  The third line, ends the program.  All basic Xgl programs start with this basic structure.  

## Variables 

Xgl supports standard variable names.  All variable names must begin with a letter, either "a" through "z" or "A" through "Z".  The name can then contain, numbers "0" through "9", or an "_".  Any other characters are not allowed.  Variables in Xgl are **not** case sensitive.  Therefore, the variables *CAR*, *car*, *Car*, *caR* are all equal and will reference the same variable.  Keywords are not allowed to be used as variables, these are concidered reserved words and should only be used as commands and sub-commands.

Examples of legal variable names:

```
Priority1
start
two_weeks
```

## Types

Xgl supports four native types by use of the following keywords:

- integer
- real
- string
- boolean

## Conditions

## While Loop

## For Loop

## Functions

## Arrays

Mark-Down Resource
https://www.youtube.com/watch?v=eVGEea7adDM
https://help.github.com/en/github/writing-on-github/basic-writing-and-formatting-syntax
