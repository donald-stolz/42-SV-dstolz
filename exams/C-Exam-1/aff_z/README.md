## Subject:
```
Assignment name  : aff_z
Expected files   : aff_z.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays the first 'z'
character it encounters in it, followed by a newline. If there are no
'z' characters in the string, the program writes 'z' followed
by a newline. If the number of parameters is not 1, the program displays
'z' followed by a newline.

Example:

$> ./aff_z "abc" | cat -e
z$
$> ./aff_z "RaInB0w d4Sh!" | cat -e
z$
$> ./aff_z "ThE C4k3 Is a L|3" | cat -e
z$
$> ./aff_z | cat -e
z$
$> ./aff_z "abc" | cat -e
z$
$> ./aff_z "dubO a POIL" | cat -e
z$
$> ./aff_z "zaz sent le poney" | cat -e
z$
$> ./aff_z | cat -e
z$
```

## Results
```
= Host-specific information ====================================================
$> hostname; uname -msr
e1z3r5p26.42.us.org
Darwin 17.4.0 x86_64
$> date
Tue Oct  9 09:11:08 PDT 2018
$> gcc --version
Configured with: --prefix=/Library/Developer/CommandLineTools/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
Apple LLVM version 9.1.0 (clang-902.0.39.1)
Target: x86_64-apple-darwin17.4.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
$> clang --version
Apple LLVM version 9.1.0 (clang-902.0.39.1)
Target: x86_64-apple-darwin17.4.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin

= User files collection ========================================================
Collecting user files from Vogsphere
Repository URL: auto-exam/2018/c-exam-alone-in-the-dark-beginner/exam_20181009/dstolz

= Git history ==================================================================
$> git -C /var/folders/6x/3ybmbvns2lx7vkvxv3j3s_s80000gp/T/tmp_NeK2C/user log --pretty='%H - %an, %ad : %s'
2b00a47da1ad2ba4925431900358493ea3c753a3 - Exam 42, Tue Oct 9 09:09:40 2018 -0700 : Commiting aff_z
 
= Collected files ==========================================
$> ls -lAR /var/folders/6x/3ybmbvns2lx7vkvxv3j3s_s80000gp/T/tmp_NeK2C/user
total 8
-rw-r--r--  1 deepthought  deepthought  207 Oct  9 09:11 __GIT_HISTORY
drwxr-xr-x  3 deepthought  deepthought  102 Oct  9 09:11 aff_z

/var/folders/6x/3ybmbvns2lx7vkvxv3j3s_s80000gp/T/tmp_NeK2C/user/aff_z:
total 8
-rw-r--r--  1 deepthought  deepthought  91 Oct  9 09:11 aff_z.c
 
= aff_z ========================================================================
$> gcc -Wextra -Wall -Werror aff_z.c -o user_exe 

= Test 1 ===================================================
$> ./y63l91gsxv8rxppk4gf3e9df 
$> diff -U 3 user_output_test1 test1.output | cat -e

Diff OK :D
= Test 2 ===================================================
$> ./kzockbs3nb4kewqpyhyglvs5 "JFtoxaidgj1hTl" "2G0kxu6A" "8V7L2iWZx" "mT690upD" "QgMm0OW"
$> diff -U 3 user_output_test2 test2.output | cat -e

Diff OK :D
= Test 3 ===================================================
$> ./4ye37abu81s5r1gwp40too32 "jWazryc1ZNuDvR"
$> diff -U 3 user_output_test3 test3.output | cat -e

Diff OK :D
= Test 4 ===================================================
$> ./fdfrfo2sb6gbrqmq1alfnmmh "P18jwxFLzJI6OfW"
$> diff -U 3 user_output_test4 test4.output | cat -e

Diff OK :D
= Test 5 ===================================================
$> ./relyxmy36xnwods2ow3fjg44 "OL3y"
$> diff -U 3 user_output_test5 test5.output | cat -e

Diff OK :D
= Test 6 ===================================================
$> ./73e4y0fcalf0c6dc9xq6ntjs "4QXJ3PGFbN"
$> diff -U 3 user_output_test6 test6.output | cat -e

Diff OK :D
Grade: 1

= Final grade: 1 ===============================================================
```
