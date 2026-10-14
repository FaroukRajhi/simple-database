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

#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255
#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)
#define ID_SIZE         size_of_attribute(Row, id)
#define USERNAME_SIZE   size_of_attribute(Row, username)
#define EMAIL_SIZE      size_of_attribute(Row, email)
#define ID_OFFSET       0
#define USERNAME_OFFSET (ID_OFFSET + ID_SIZE)
#define EMAIL_OFFSET    (USERNAME_OFFSET + USERNAME_SIZE)
#define ROW_SIZE        (ID_SIZE + USERNAME_SIZE + EMAIL_SIZE)
typedef struct 
{
    u_int32_t id;
    char username[COLUMN_USERNAME_SIZE];
    char email[COLUMN_EMAIL_SIZE];
} Row;

