# rstr_capitalizer
- [ ] Corrected

## Subject:
```
Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or more strings and, for each argument, puts
the last character that is a letter of each word in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

A letter is a character in the set [a-zA-Z]

If there are no parameters, display \n.

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
$>
```

## Results
```
= Host-specific information ====================================================
$> hostname; uname -msr
e1z2r5p20.42.us.org
Darwin 17.4.0 x86_64
$> date
Fri Sep 21 11:50:27 PDT 2018
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
Repository URL: auto-exam/2018/c-exam-alone-in-the-dark-beginner/exam_20180921/dstolz

= Git history ==================================================================
$> git -C /var/folders/nf/602w9vzn5z94mbng99df9vj00000gp/T/tmpquNqUb/user log --pretty='%H - %an, %ad : %s'
c73a3a515d8b2ff53209734f8305e1ff4286ad19 - Exam 42, Fri Sep 21 11:50:09 2018 -0700 : Submitting level 3, test 2
6150c855c4dadb9cb162f960e3a7c9f6ca5d4df2 - Exam 42, Fri Sep 21 10:56:48 2018 -0700 : Submitting level 3
8f200a0c3d03c1e6e9ca9d097f4d5a6e569b84da - Exam 42, Fri Sep 21 09:55:36 2018 -0700 : Submitting level 2
1a5037fa1f93984868c68b8805507a361607b0bb - Exam 42, Fri Sep 21 09:23:20 2018 -0700 : Finished level 1
cb0bba95777b1e9c6c7ea5e0c50a623c8ad1b61f - Exam 42, Fri Sep 21 09:13:59 2018 -0700 : Finished level 0

= Collected files ==========================================
$> ls -lAR /var/folders/nf/602w9vzn5z94mbng99df9vj00000gp/T/tmpquNqUb/user
total 8
-rw-r--r--  1 deepthought  deepthought  1278 Sep 21 11:50 __GIT_HISTORY
drwxr-xr-x  3 deepthought  deepthought   102 Sep 21 11:50 ft_putstr
drwxr-xr-x  4 deepthought  deepthought   136 Sep 21 11:50 maff_alpha
drwxr-xr-x  3 deepthought  deepthought   102 Sep 21 11:50 max
drwxr-xr-x  3 deepthought  deepthought   102 Sep 21 11:50 paramsum
drwxr-xr-x  3 deepthought  deepthought   102 Sep 21 11:50 rstr_capitalizer

/var/folders/nf/602w9vzn5z94mbng99df9vj00000gp/T/tmpquNqUb/user/ft_putstr:
total 8
-rw-r--r--  1 deepthought  deepthought  1045 Sep 21 11:50 ft_putstr.c

/var/folders/nf/602w9vzn5z94mbng99df9vj00000gp/T/tmpquNqUb/user/maff_alpha:
total 32
-rwxr-xr-x  1 deepthought  deepthought  8564 Sep 21 11:50 a.out
-rw-r--r--  1 deepthought  deepthought  1008 Sep 21 11:50 maff_alpha.c

/var/folders/nf/602w9vzn5z94mbng99df9vj00000gp/T/tmpquNqUb/user/max:
total 8
-rw-r--r--  1 deepthought  deepthought  1205 Sep 21 11:50 max.c

/var/folders/nf/602w9vzn5z94mbng99df9vj00000gp/T/tmpquNqUb/user/paramsum:
total 8
-rw-r--r--  1 deepthought  deepthought  1246 Sep 21 11:50 paramsum.c

/var/folders/nf/602w9vzn5z94mbng99df9vj00000gp/T/tmpquNqUb/user/rstr_capitalizer:
total 8
-rw-r--r--  1 deepthought  deepthought  1709 Sep 21 11:50 rstr_capitalizer.c

= rstr_capitalizer =============================================================
$> gcc -Wextra -Wall -Werror rstr_capitalizer.c -o user_exe

= Test 1 ===================================================
$> ./rqw8t8p6jyu60gwffzxdt4qf
$> diff -U 3 user_output_test1 test1.output | cat -e

Diff OK :D
= Test 2 ===================================================
$> ./8254lofj86bmztxf849g1qhf
$> diff -U 3 user_output_test2 test2.output | cat -e

Diff OK :D
= Test 3 ===================================================
$> ./xqbh925e0ug2yrz4mf36b36h "3hL51lsZP4N8Kkm"
$> diff -U 3 user_output_test3 test3.output | cat -e

Diff OK :D
= Test 4 ===================================================
$> ./euxuxhk9qbgfjtk14wf186zj "=iNxc99PDIx7435R6j-lV9q4fuU<UgqMupOSP		 	nFH0lZ	>w07aMLSvl5B	 )CnM5ReItifH2hzL5vQJSP8"
$> diff -U 3 user_output_test4 test4.output | cat -e
--- user_output_test4	2018-09-21 11:50:30.000000000 -0700$
+++ test4.output	2018-09-21 11:50:30.000000000 -0700$
@@ -1 +1 @@$
-=inxc99pdix7435r6j-lv9q4fuu<ugqmuposp		 	nfh0lz	>w07amlsvl5b	 )cnm5reitifh2hzl5vqjsp8$
+=inxc99pdix7435r6j-lv9q4fuu<ugqmuposP		 	nfh0lZ	>w07amlsvl5B	 )cnm5reitifh2hzl5vqjsp8$

Diff KO :(
Grade: 0

= Final grade: 0 ===============================================================
```
