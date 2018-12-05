# only_z
## Subject:
```
Assignment name  : only_z
Expected files   : only_z.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a 'z' character on the standard output.
```

## Results
```
= Host-specific information ====================================================
$> hostname; uname -msr
e1z1r5p22.42.us.org
Darwin 17.4.0 x86_64
$> date
Tue Sep 25 09:07:38 PDT 2018
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
Repository URL: auto-exam/2018/c-exam-alone-in-the-dark-beginner/exam_20180925/dstolz

= Git history ==================================================================
$> git -C /var/folders/2y/f1yrjh791q1b59dn8j3rf9480000gp/T/tmpzhYN9t/user log --pretty='%H - %an, %ad : %s'
1b9fb7392a7061420d8edde2168d4734c26dbd8c - Exam 42, Tue Sep 25 09:07:18 2018 -0700 : Submitting level 0

= Collected files ==========================================
$> ls -lAR /var/folders/2y/f1yrjh791q1b59dn8j3rf9480000gp/T/tmpzhYN9t/user
total 8
-rw-r--r--  1 deepthought  deepthought  229 Sep 25 09:07 __GIT_HISTORY
drwxr-xr-x  3 deepthought  deepthought  102 Sep 25 09:07 only_z

/var/folders/2y/f1yrjh791q1b59dn8j3rf9480000gp/T/tmpzhYN9t/user/only_z:
total 8
-rw-r--r--  1 deepthought  deepthought  982 Sep 25 09:07 only_z.c

= only_z =======================================================================
$> gcc -Wextra -Wall -Werror only_z.c -o user_exe

= Test 1 ===================================================
$> ./734cbe4tn9h7thjgnqszdavb
$> diff -U 3 user_output_test1 test1.output | cat -e

Diff OK :D
Grade: 1

= Final grade: 1 ===============================================================
```
