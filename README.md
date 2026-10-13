# SQLite Database System Components

**Tokenizer**

It breaks SQL text into small meaningful units called "tokens".

- Example:

SELECT username FROM users;

It identifies tokens such as SELECT, username, FROM, users and ;.
Splitting a sentence into words and punctuation.


**Parser**

It checks whether the tokens form a valid SQL statement and determines their relationships.

- Example:

SELECT FROM users;

This statement has a syntax error because the SELECT clause is missing its selected expression.
The parser turns valid input int a structured representation, often a parse tree.

**Code Generator**

It translates the parsed statement into SQLite's internal instructions, called bytecode.
- Steps:

1. Open the users table
2. Read its records.
3. Return the requested columns.
4. Finish execution.

**Virtual Machine**
It executes the bytecode produced by the code generator.
It coordinates operations such as opening table, finding records, comparing values and returning results.

**B-tree**

It organizes table and index data into a structure that makes records easier to locate.

- example:

Imagine a table with one million rows. With a suitable index, SQLite may find a record without scanning every row.
B-trees organize keys and references or records into pages. Tables and indexes have their own B-tree structures in a typical SQLite database.

**Pager**

It handles database pages moving between storage and memory.
Its responsibilities include:

* Reading and writing pages.
* Caching frequently used pages.
* Supporting transaction and recovery mechanisms.
* Coordinating safe changes to the database file.

**OS interface (VFS)**

VFS stands for Virtual File System in SQLite terminology.
It provides a common interface for file operations, locking and other operating-system services. SQLite uses platform-specific implementations to work on systems such as Linux, Windows and macOS.
This layer helps SQLite remain portable across operating systems