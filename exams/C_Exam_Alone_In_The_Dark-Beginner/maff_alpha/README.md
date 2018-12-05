# maff_alpha

## Subject:
```
Assignment name  : maff_alpha
Expected files   : maff_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays the alphabet, with even letters in uppercase, and
odd letters in lowercase, followed by a newline.

Example:

$> ./maff_alpha | cat -e
aBcDeFgHiJkLmNoPqRsTuVwXyZ$
```

## Results
```
= Host-specific information ====================================================
$> hostname; uname -msr
e1z1r4p3.42.us.org
Darwin 17.2.0 x86_64
$> date
Fri Sep 21 09:14:28 PDT 2018
$> gcc --version
Configured with: --prefix=/Library/Developer/CommandLineTools/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
Apple LLVM version 9.0.0 (clang-900.0.38)
Target: x86_64-apple-darwin17.2.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
$> clang --version
Apple LLVM version 9.0.0 (clang-900.0.38)
Target: x86_64-apple-darwin17.2.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin

= User files collection ========================================================
Collecting user files from Vogsphere
Repository URL: auto-exam/2018/c-exam-alone-in-the-dark-beginner/exam_20180921/dstolz

= Git history ==================================================================
$> git -C /var/folders/s7/x8yywfms2kz8cmyf3126989m0000gp/T/tmpv2hhi2/user log --pretty='%H - %an, %ad : %s'
cb0bba95777b1e9c6c7ea5e0c50a623c8ad1b61f - Exam 42, Fri Sep 21 09:13:59 2018 -0700 : Finished level 0

= Collected files ==========================================
$> ls -lAR /var/folders/s7/x8yywfms2kz8cmyf3126989m0000gp/T/tmpv2hhi2/user
total 8
-rw-r--r--  1 deepthought  deepthought  282 Sep 21 09:14 __GIT_HISTORY
drwxr-xr-x  4 deepthought  deepthought  136 Sep 21 09:14 maff_alpha

/var/folders/s7/x8yywfms2kz8cmyf3126989m0000gp/T/tmpv2hhi2/user/maff_alpha:
total 32
-rwxr-xr-x  1 deepthought  deepthought  8564 Sep 21 09:14 a.out
-rw-r--r--  1 deepthought  deepthought  1008 Sep 21 09:14 maff_alpha.c

= maff_alpha ===================================================================
$> gcc -Wextra -Wall -Werror maff_alpha.c -o user_exe

= Test 1 ===================================================
$> ./mb9a29pbjrkmqhqe78iemqk3 test1.prm
$> diff -U 3 user_output_test1 test1.output | cat -e

Diff OK :D
Grade: 1

= Final grade: 1 ===============================================================
```
