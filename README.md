# SQLite Database System Components

**Tokenizer**

It breaks SQL text into small meaningful units called "tokens".

- Example:

SELECT username FROM users;

It identifies tokens such as SELCT, username, FROM, users and ;.
Splitting a sentence into words and punctuation.


**Parser**

It checks whether the tokens form a valid SQL statement and determines their relationships.

- Example:

SELECT FROM users;

This statement has a syntax error because the SELECT clause is missing its selected expression.
The parser turns valid input int a structured representation, often a parse tree.

