/*
## C keywords and identifiers

------------------
In this tutorial, you will learn about keywords;
reserved words in C programming that are part
of the syntax. Also, you will learn about identifiers
and how to name them.
------------------

### character set
----------------
A character set is a set of alphabets, letters and some 
special characters that are valid in C language
----------------
#### Alphabets

> Uppercase: ABC ...................XYZ
> Lowercase: abc ...................xyz

C accepts both lowercase and uppercase alphabets as variables
and functions

#### Digits

> 0 1 2 3 4 5 6 7 8 9

#### Special characters

> , < > . - ( ) ; & : % { } + / * \ ^

#### White space Characters
--------------
Blank space, newline, horizontal tab, carriage return and form feed
--------------

## C keywords

--------------------
Keywords are predefined, reserved words used in
programming that have special meanings to the compiler.
Keywords are part of the syntax and they cannot be used
as an identifier. For example:

 (reserved) (variable);
> int money;

* Here, 'int' is a keyword that indicates 'money'
is a variable of type 'int'(integer).

### keywords
As C is a case sensitive language, all keywords 
must be written in lowercase. Here is a list of 
all keywords allowed in ANSI C.

| auto | double | int | struct |
--------------------------------
| break | else | long | switch |
--------------------------------
| case | enum | register | typedef |
--------------------------------
| char | extern | return | union |
--------------------------------
| continue | for | signed | void |
--------------------------------
| do | if | static | while |
--------------------------------
| default | goto | sizeof | volatile |
--------------------------------
| const | float | short | unsigned |
--------------------------------

All these keywords, their syntax, and application
will be discussed in their respective topics.
However, if you want a brief overview of these
keywords without going further,
https://www.programiz.com/c-programming/list-all-keywords-c-language

-----------------------
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
|||||||||||||||||||||||||||||||||||||||||||
## C Identifiers

------------------------
Identifier refers to name given to entities such
as variables, functions, structures, etc.

Identifiers must be unique. They are createad
to give a unique name to an entity to identity it
during the execution of the program. For example:

> int money;
> double accountBalance;

Here, 'money' and 'accountBalance' are identifiers.

* Also remember, identifier names must be different
from keywords. You cannot use 'int' as an identifier
because 'int' is a keyword.


--------------------------
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
|||||||||||||||||||||||||||||||||||||||||||

## Rules for naming identifiers

1. A valid identifier can have letters(both uppercase and lowercase letters),
digits and underscores.
2. The first letter of an identifier should be either a letter or a underscore.
3. You cannot use keywords like 'int', 'while' etc. as identifiers.
4. There is no rule on how long an identifier can be. However, you may
run into problems in some compilers if the identifier is longer than 31 characters.

tip: You can choose any name as an identifier if you follow the above rule,
however, give a meaningful names to identifiers that make sense.

 */