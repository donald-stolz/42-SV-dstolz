## Subject:
```
Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./rev_print "rainbow dash" | cat -e
hsad wobniar$
$> ./rev_print "Ponies are awesome" | cat -e
emosewa era seinoP$
$> ./rev_print | cat -e
$
```

## Results
```
= Host-specific information ====================================================
$> hostname; uname -msr
e1z2r5p26.42.us.org
Darwin 17.4.0 x86_64
$> date
Tue Oct  9 09:30:35 PDT 2018
$> gcc --version
Configured with: --prefix=/Library/Developer/CommandLineTools/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
Apple LLVM version 9.0.0 (clang-900.0.39.2)
Target: x86_64-apple-darwin17.4.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
$> clang --version
Apple LLVM version 9.0.0 (clang-900.0.39.2)
Target: x86_64-apple-darwin17.4.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin

= User files collection ========================================================
Collecting user files from Vogsphere
Repository URL: auto-exam/2018/c-exam-alone-in-the-dark-beginner/exam_20181009/dstolz

= Git history ==================================================================
$> git -C /var/folders/kt/mn0_sdqs3ps0djmnx58qhtch0000gp/T/tmpHXlK3k/user log --pretty='%H - %an, %ad : %s'
69dc194a4594c7ba74c3002eca2113a897c19f37 - Exam 42, Tue Oct 9 09:30:22 2018 -0700 : Commiting rev_print
2b00a47da1ad2ba4925431900358493ea3c753a3 - Exam 42, Tue Oct 9 09:09:40 2018 -0700 : Commiting aff_z
 
= Collected files ==========================================
$> ls -lAR /var/folders/kt/mn0_sdqs3ps0djmnx58qhtch0000gp/T/tmpHXlK3k/user
total 8
-rw-r--r--  1 deepthought  deepthought  494 Oct  9 09:30 __GIT_HISTORY
drwxr-xr-x  3 deepthought  deepthought  102 Oct  9 09:30 aff_z
drwxr-xr-x  4 deepthought  deepthought  136 Oct  9 09:30 rev_print

/var/folders/kt/mn0_sdqs3ps0djmnx58qhtch0000gp/T/tmpHXlK3k/user/aff_z:
total 8
-rw-r--r--  1 deepthought  deepthought  91 Oct  9 09:30 aff_z.c

/var/folders/kt/mn0_sdqs3ps0djmnx58qhtch0000gp/T/tmpHXlK3k/user/rev_print:
total 32
-rw-r--r--  1 deepthought  deepthought  12288 Oct  9 09:30 .rev_print.c.swp
-rw-r--r--  1 deepthought  deepthought    227 Oct  9 09:30 rev_print.c
 
= rev_print ====================================================================
$> gcc -Wextra -Wall -Werror rev_print.c -o user_exe 

= Test 1 ===================================================
$> ./g6aae457fd2i975v5g5wghmu 
Command './g6aae457fd2i975v5g5wghmu ' got killed by a Segmentation fault (Signal -11)
Grade: 0

= Final grade: 0 ===============================================================
```
