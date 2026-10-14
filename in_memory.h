/*
Starting small by putting a lot of limitations on our database system.
-> Support two operations: inserting a row and printing all rows.
-> Reside only in memory (no to disk storage)
-> Support a single, hard-coded table

The table is going to store users and look like this:


column	        type
------------------------------
id	          integer
username	  varchar(32)
email	      varchar(255)


*/