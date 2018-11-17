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
e1z1r3p8.42.us.org
Darwin 17.4.0 x86_64
$> date
Tue Sep 25 10:09:25 PDT 2018
$> gcc --version
Configured with: --prefix=/Library/Developer/CommandLineTools/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
Apple LLVM version 9.1.0 (clang-902.0.39.2)
Target: x86_64-apple-darwin17.4.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
$> clang --version
Apple LLVM version 9.1.0 (clang-902.0.39.2)
Target: x86_64-apple-darwin17.4.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin

= User files collection ========================================================
Collecting user files from Vogsphere
Repository URL: auto-exam/2018/c-exam-alone-in-the-dark-beginner/exam_20180925/dstolz

= Git history ==================================================================
$> git -C /var/folders/l0/t_59cnqs7k9_k_mgryzxw_j40000gp/T/tmpRFQOgv/user log --pretty='%H - %an, %ad : %s'
77d1f4220cb6a6babfe00b20e1f1abcef7acdd55 - Exam 42, Tue Sep 25 10:09:04 2018 -0700 : submitting level 2, try 2
f477dcf6086ba33a6cb1e58e8bc7c88767b6373c - Exam 42, Tue Sep 25 09:30:54 2018 -0700 : Submitting level 1
1b9fb7392a7061420d8edde2168d4734c26dbd8c - Exam 42, Tue Sep 25 09:07:18 2018 -0700 : Submitting level 0

= Collected files ==========================================
$> ls -lAR /var/folders/l0/t_59cnqs7k9_k_mgryzxw_j40000gp/T/tmpRFQOgv/user
total 8
-rw-r--r--  1 deepthought  deepthought  795 Sep 25 10:09 __GIT_HISTORY
drwxr-xr-x  3 deepthought  deepthought  102 Sep 25 10:09 only_z
drwxr-xr-x  3 deepthought  deepthought  102 Sep 25 10:09 search_and_replace
drwxr-xr-x  3 deepthought  deepthought  102 Sep 25 10:09 swap_bits
drwxr-xr-x  3 deepthought  deepthought  102 Sep 25 10:09 union

/var/folders/l0/t_59cnqs7k9_k_mgryzxw_j40000gp/T/tmpRFQOgv/user/only_z:
total 8
-rw-r--r--  1 deepthought  deepthought  982 Sep 25 10:09 only_z.c

/var/folders/l0/t_59cnqs7k9_k_mgryzxw_j40000gp/T/tmpRFQOgv/user/search_and_replace:
total 8
-rw-r--r--  1 deepthought  deepthought  1424 Sep 25 10:09 search_and_replace.c

/var/folders/l0/t_59cnqs7k9_k_mgryzxw_j40000gp/T/tmpRFQOgv/user/swap_bits:
total 0
-rw-r--r--  1 deepthought  deepthought  0 Sep 25 10:09 swap_bits.c

/var/folders/l0/t_59cnqs7k9_k_mgryzxw_j40000gp/T/tmpRFQOgv/user/union:
total 8
-rw-r--r--  1 deepthought  deepthought  1621 Sep 25 10:09 union.c

= union ========================================================================
$> gcc -Wextra -Wall -Werror union.c -o user_exe

= Test 1 ===================================================
$> ./nk1njdbedwu4dgyrb9qw9m91
$> diff -U 3 user_output_test1 test1.output | cat -e

Diff OK :D
= Test 2 ===================================================
$> ./xhaymtllig10qmxlew2x5hrl "	 " " 		  "
$> diff -U 3 user_output_test2 test2.output | cat -e

Diff OK :D
= Test 3 ===================================================
$> ./03657g266wdst5rodxirp3jp "c5DztpR"
$> diff -U 3 user_output_test3 test3.output | cat -e

Diff OK :D
= Test 4 ===================================================
$> ./1h473v417o5cv5iinqh39y7i "Zt4zQ0ipg" "Btn6AOPzI7QmoHlRy"
$> diff -U 3 user_output_test4 test4.output | cat -e
--- user_output_test4	2018-09-25 10:09:27.000000000 -0700$
+++ test4.output	2018-09-25 10:09:27.000000000 -0700$
@@ -1 +1 @@$
-t4zQ0ipgBn6AOPI7moHlRy$
+Zt4zQ0ipgBn6AOPI7moHlRy$

Diff KO :(
Grade: 0

= Final grade: 0 ===============================================================
```
