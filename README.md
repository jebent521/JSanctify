# Sanctify/README
## Authors:
Jonah Ebent, Evan Whitmer, Tessa Habet, Claire Cardie

## About
Sanctify currently cantains the skeleton of C++ and SQL for making a clone of the Hallow app by Hallow, Inc. (https://hallow.com/).
Different roles are outlined (Admin, Employee, ContentCreator, User) with different access rights within the data base.

## In Sanctify folder
Header files and corresponding cpp files according to the different roles, each with their own terminal menu. The terminal
menus are unique to each role in the SQL Database. There is also a Util.cpp which contains error handling between Visual
Studio 2022/ VScode and SQL Server Management Studio (SSMS). 

Additionally, in the DBInstantiation.txt is the SQL code for generating the tables, constraints, roles, etc. that can be 
copy and pasted into a new query on SSMS.

## Note
DBInstantiation.txt does not actually interface with the app. It is where we wrote the SQL DDL to create the database.

## Start up
An example of what running the project will look like and logging in as a Paid Customer.

![A Picture of the login menu.](Pictures/Screenshot%202023-12-11%20100052.png)

![A picture of the Customer Menu.](Pictures/Screenshot%202023-12-11%20100144.png)