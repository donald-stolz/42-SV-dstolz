# Union
- [ ] Corrected
## Subject:
```
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
```

## Results
```
= Host-specific information ====================================================
$> hostname; uname -msr
e1z3r6p20.42.us.org
Darwin 17.4.0 x86_64
$> date
Tue Oct  9 10:29:17 PDT 2018
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
$> git -C /var/folders/21/cx8qcgtd517_c73zw3_xgd8c0000gp/T/tmp6er9Lf/user log --pretty='%H - %an, %ad : %s'
66c53b2992551bf71d53c3155f44ab67f65f438d - Exam 42, Tue Oct 9 10:29:05 2018 -0700 : Commiting union, final problem for today
dd416300f106a5c5f8af127d07d1e4ffe70902f5 - Exam 42, Tue Oct 9 09:56:01 2018 -0700 : Commiting ulstr
69dc194a4594c7ba74c3002eca2113a897c19f37 - Exam 42, Tue Oct 9 09:30:22 2018 -0700 : Commiting rev_print
2b00a47da1ad2ba4925431900358493ea3c753a3 - Exam 42, Tue Oct 9 09:09:40 2018 -0700 : Commiting aff_z
 
= Collected files ==========================================
$> ls -lAR /var/folders/21/cx8qcgtd517_c73zw3_xgd8c0000gp/T/tmp6er9Lf/user
total 8
-rw-r--r--  1 deepthought  deepthought  1038 Oct  9 10:29 __GIT_HISTORY
drwxr-xr-x  3 deepthought  deepthought   102 Oct  9 10:29 aff_z
drwxr-xr-x  4 deepthought  deepthought   136 Oct  9 10:29 rev_print
drwxr-xr-x  3 deepthought  deepthought   102 Oct  9 10:29 ulstr
drwxr-xr-x  3 deepthought  deepthought   102 Oct  9 10:29 union

/var/folders/21/cx8qcgtd517_c73zw3_xgd8c0000gp/T/tmp6er9Lf/user/aff_z:
total 8
-rw-r--r--  1 deepthought  deepthought  91 Oct  9 10:29 aff_z.c

/var/folders/21/cx8qcgtd517_c73zw3_xgd8c0000gp/T/tmp6er9Lf/user/rev_print:
total 32
-rw-r--r--  1 deepthought  deepthought  12288 Oct  9 10:29 .rev_print.c.swp
-rw-r--r--  1 deepthought  deepthought    267 Oct  9 10:29 rev_print.c

/var/folders/21/cx8qcgtd517_c73zw3_xgd8c0000gp/T/tmp6er9Lf/user/ulstr:
total 8
-rw-r--r--  1 deepthought  deepthought  500 Oct  9 10:29 ulstr.c

/var/folders/21/cx8qcgtd517_c73zw3_xgd8c0000gp/T/tmp6er9Lf/user/union:
total 8
-rw-r--r--  1 deepthought  deepthought  717 Oct  9 10:29 union.c
 
= union ========================================================================
$> gcc -Wextra -Wall -Werror union.c -o user_exe 

Forbidden function call in 'union.c': 'malloc'
Grade: -42

= Final grade: -42 =============================================================
```
