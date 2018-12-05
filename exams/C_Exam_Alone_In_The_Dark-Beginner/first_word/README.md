# first_word
- [ ] Corrected

## Subject:
```
Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its first word, followed by a
newline.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./first_word "FOR PONIES !!" | cat -e
FOR$
$> ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
```

## Results
```
= Host-specific information ====================================================
$> hostname; uname -msr
e1z4r12p17.42.us.org
Darwin 17.5.0 x86_64
$> date
Tue Dec  4 09:34:10 PST 2018
$> gcc --version
Configured with: --prefix=/Library/Developer/CommandLineTools/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
Apple LLVM version 9.1.0 (clang-902.0.39.1)
Target: x86_64-apple-darwin17.5.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
$> clang --version
Apple LLVM version 9.1.0 (clang-902.0.39.1)
Target: x86_64-apple-darwin17.5.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin

= User files collection ========================================================
Collecting user files from Vogsphere
Repository URL: auto-exam/2018/c-exam-alone-in-the-dark-beginner/exam_20181204/dstolz

= Git history ==================================================================
$> git -C /var/folders/cf/bcbh16rd49989k5pghwnltnm0000gp/T/tmpUrjTgV/user log --pretty='%H - %an, %ad : %s'
4d0609d3946a5acccedcd32e46289d0ad4657377 - Exam 42, Tue Dec 4 09:33:56 2018 -0800 : Finish 1.1
190ee376e57189a76fad24d1a440da27aa426fa0 - Exam 42, Tue Dec 4 09:19:00 2018 -0800 : Finish 1
21592204431d5d7540611674576f06a6d78e3428 - Exam 42, Tue Dec 4 09:04:45 2018 -0800 : Finish 0
 
= Collected files ==========================================
$> ls -lAR /var/folders/cf/bcbh16rd49989k5pghwnltnm0000gp/T/tmpUrjTgV/user
total 8
-rw-r--r--  1 deepthought  deepthought  673 Dec  4 09:34 __GIT_HISTORY
drwxr-xr-x  3 deepthought  deepthought  102 Dec  4 09:34 first_word
drwxr-xr-x  3 deepthought  deepthought  102 Dec  4 09:34 maff_revalpha
drwxr-xr-x  3 deepthought  deepthought  102 Dec  4 09:34 repeat_alpha

/var/folders/cf/bcbh16rd49989k5pghwnltnm0000gp/T/tmpUrjTgV/user/first_word:
total 8
-rw-r--r--  1 deepthought  deepthought  215 Dec  4 09:34 first_word.c

/var/folders/cf/bcbh16rd49989k5pghwnltnm0000gp/T/tmpUrjTgV/user/maff_revalpha:
total 8
-rw-r--r--  1 deepthought  deepthought  98 Dec  4 09:34 maff_revalpha.c

/var/folders/cf/bcbh16rd49989k5pghwnltnm0000gp/T/tmpUrjTgV/user/repeat_alpha:
total 8
-rw-r--r--  1 deepthought  deepthought  415 Dec  4 09:34 repeat_alpha.c
 
= first_word ===================================================================
$> gcc -Wextra -Wall -Werror first_word.c -o user_exe 

= Test 1 ===================================================
$> ./u5y63wbtgy0x8w55h38fed1x 
$> diff -U 3 user_output_test1 test1.output | cat -e

Diff OK :D
= Test 2 ===================================================
$> ./52jfu7ffksydijkvltr676ry 
$> diff -U 3 user_output_test2 test2.output | cat -e

Diff OK :D
= Test 3 ===================================================
$> ./ifk521a68ot9g1aquvhzgfgh "salut" "a" "tous" "tout" "le" "monde"
$> diff -U 3 user_output_test3 test3.output | cat -e

Diff OK :D
= Test 4 ===================================================
$> ./gm7eyrx11x6cl1iz6hv6x3yk "SXEa41"
$> diff -U 3 user_output_test4 test4.output | cat -e

Diff OK :D
= Test 5 ===================================================
$> ./bkeopriz2b7l62p3ta0hkm0k "LOkzb97PRM"
$> diff -U 3 user_output_test5 test5.output | cat -e

Diff OK :D
= Test 6 ===================================================
$> ./5o6kquiu0zvcd04lltmrdt4m "JtyWpa3APV"
$> diff -U 3 user_output_test6 test6.output | cat -e

Diff OK :D
= Test 7 ===================================================
$> ./kidk27xz39rz7dcs78hilh32 "5lvSfhCY6 TQcrPqRjy1vFlz KniEwlUXSqI YWE3X nAlmd 2MVHldxAv"
$> diff -U 3 user_output_test7 test7.output | cat -e

Diff OK :D
= Test 8 ===================================================
$> ./ckr4jx4lv0ol6n3b0mp8s1o0 "kr4nQtis18G 6AlWkhsF h4Tkft7lKZXpb lh2JYn1d 97YMP6I KvP2 lP9A bdqQ6NY1M"
$> diff -U 3 user_output_test8 test8.output | cat -e

Diff OK :D
= Test 9 ===================================================
$> ./yjisvnhajkcgahr5j1i4efgm "e4sWrbizSD qx2oAh SGx uzO qO8EVKx NT2qiwAIU vefAxh6KQ2 iOfdyjh2pFIbeDB DSRZK3"
$> diff -U 3 user_output_test9 test9.output | cat -e

Diff OK :D
= Test 10 ==================================================
$> ./0arvbi1jd4z4n5bdwrtswjrc " 		9AG3DMWew7ELf5cN @gPYEcx5mt37qBWncETuy8XRQ  <BxEyl:"
$> diff -U 3 user_output_test10 test10.output | cat -e
--- user_output_test10	2018-12-04 09:34:13.000000000 -0800$
+++ test10.output	2018-12-04 09:34:13.000000000 -0800$
@@ -1 +1 @@$
-$
+9AG3DMWew7ELf5cN$

Diff KO :(
Grade: 0

= Final grade: 0 ===============================================================

```
