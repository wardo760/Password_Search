# Password_Search
Uses recursive binary search, iterative binary search, and linear search to search through different documents.

Programming Project Report
Name: Corey Warden
Date: 03/03/2023

Problem Statement:
  The goal of this program was to show different searching functions. These are 
recursive binary search, iterative binary search, and linear search. The inputs were 
multiple text files that had a long list of passwords that were converted to vector 
lists. Another text file that had given passwords that we would search for later in 
the program. And passwords to search for given by the user.
The outputs were the found password(s) and their information and how much 
faster recursive search is over linear search. Error handling was only used if the 
user gave a password that didn’t exist.

Design:
  Some design decisions I made was to have the search functions out put integers 
and print the results of the search in the function itself. This made it easier when I 
needed to return counter variables for the comparative task between linear and 
recursive searching. The cons were that this made it harder to customize the 
outputs in the terminal.
Implementation:
To implement this, I used the starter code given by the instructor as well as my 
class template to help write the Password classes. I then looked up examples of 
binary code and tailored it to work with my code. If that was either just using 
password objects instead of numbers as the items or using iteration to find 
multiple keys. My development timeline was supposed to be over three days but 
because of some unseen errors that had to be pushed an extra day. I will describe 
these errors in the testing section.

Testing:
  I tested my program using the testing information given in the project description. 
Normal inputs were passwords that existed and special inputs were passwords that 
didn’t exist. And everything was working fine up until the comparative task.
I misread this task. I thought it wanted us to use a clock system to see how fast it 
was going but no matter what I did linear search was always about 11 times faster 
than recursive. It was so bad that I had a high-level programmer from Boeing try 
to help me figure it out. Even he couldn’t find out why it wasn’t working even 
after 2 hours of debugging. I finally looked at the task again and saw that it 
actually wanted me to use a counter instead. Unfortunately, it was already 20 
minutes past the due date. I still don’t understand why it’s so much slower when 
using a clock system, but it works with the counter system, so I guess I won’t
question it.
I unfortunately don’t have testing code because the only way I could fully test this 
was in the command prompt and I can’t figure out how to copy code out of there.

Conclusions:
  The overall results were a success, even if it took longer than expected. Next time 
I will make sure I start testing while I have office hours available to me. I will 
keep starting at least 3 days early, it seems like a long enough time for me to 
finish the code. This project took 7 hours and three says t complete without the 
counter mishap. The counter mishap took 3 hours and extended the project a day.
