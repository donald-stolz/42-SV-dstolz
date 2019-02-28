## Subject:
```
Assignment name  : maff_revalpha
Expected files   : maff_revalpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays the alphabet in reverse, with even letters in
uppercase, and odd letters in lowercase, followed by a newline.

Example:

$> ./maff_revalpha | cat -e
zYxWvUtSrQpOnMlKjIhGfEdCbA$
```

## Results
```
= Host-specific information ====================================================
$> hostname; uname -msr
e1z3r4p22.42.us.org
Darwin 17.4.0 x86_64
$> date
Tue Dec  4 09:04:54 PST 2018
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
Repository URL: auto-exam/2018/c-exam-alone-in-the-dark-beginner/exam_20181204/dstolz

= Git history ==================================================================
$> git -C /var/folders/9z/5gt5l0ts6hx_f15w4qkmclth0000gp/T/tmpqAziW7/user log --pretty='%H - %an, %ad : %s'
21592204431d5d7540611674576f06a6d78e3428 - Exam 42, Tue Dec 4 09:04:45 2018 -0800 : Finish 0
 
= Collected files ==========================================
$> ls -lAR /var/folders/9z/5gt5l0ts6hx_f15w4qkmclth0000gp/T/tmpqAziW7/user
total 8
-rw-r--r--  1 deepthought  deepthought  215 Dec  4 09:04 __GIT_HISTORY
drwxr-xr-x  3 deepthought  deepthought  102 Dec  4 09:04 maff_revalpha

/var/folders/9z/5gt5l0ts6hx_f15w4qkmclth0000gp/T/tmpqAziW7/user/maff_revalpha:
total 8
-rw-r--r--  1 deepthought  deepthought  98 Dec  4 09:04 maff_revalpha.c
 
= maff_revalpha ================================================================
$> gcc -Wextra -Wall -Werror maff_revalpha.c -o user_exe 

= Test 1 ===================================================
$> ./41kl8zbtuur3yeo9wyls8apd
$> diff -U 3 user_output_test1 test1.output | cat -e

Diff OK :D
Grade: 1

= Final grade: 1 ===============================================================

```