# repeat_alpha
- [ ] Corrected

## Subject:
```
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
```

## Results
```
= Host-specific information ====================================================
$> hostname; uname -msr
e1z3r1p10.42.us.org
Darwin 17.4.0 x86_64
$> date
Tue Dec  4 09:19:15 PST 2018
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
$> git -C /var/folders/b1/5dqhl81j2yg2l0s49nk26b3r0000gp/T/tmp1yRQgG/user log --pretty='%H - %an, %ad : %s'
190ee376e57189a76fad24d1a440da27aa426fa0 - Exam 42, Tue Dec 4 09:19:00 2018 -0800 : Finish 1
21592204431d5d7540611674576f06a6d78e3428 - Exam 42, Tue Dec 4 09:04:45 2018 -0800 : Finish 0
 
= Collected files ==========================================
$> ls -lAR /var/folders/b1/5dqhl81j2yg2l0s49nk26b3r0000gp/T/tmp1yRQgG/user
total 8
-rw-r--r--  1 deepthought  deepthought  453 Dec  4 09:19 __GIT_HISTORY
drwxr-xr-x  3 deepthought  deepthought  102 Dec  4 09:19 maff_revalpha
drwxr-xr-x  3 deepthought  deepthought  102 Dec  4 09:19 repeat_alpha

/var/folders/b1/5dqhl81j2yg2l0s49nk26b3r0000gp/T/tmp1yRQgG/user/maff_revalpha:
total 8
-rw-r--r--  1 deepthought  deepthought  98 Dec  4 09:19 maff_revalpha.c

/var/folders/b1/5dqhl81j2yg2l0s49nk26b3r0000gp/T/tmp1yRQgG/user/repeat_alpha:
total 8
-rw-r--r--  1 deepthought  deepthought  415 Dec  4 09:19 repeat_alpha.c
 
= repeat_alpha =================================================================
$> gcc -Wextra -Wall -Werror repeat_alpha.c -o user_exe 

= Test 1 ===================================================
$> ./9qbi17h6gzykqmnc04ixuhzc 
$> diff -U 3 user_output_test1 test1.output | cat -e

Diff OK :D
= Test 2 ===================================================
$> ./a78rnl9zgop06slcd95ir300 
$> diff -U 3 user_output_test2 test2.output | cat -e

Diff OK :D
= Test 3 ===================================================
$> ./vijvaa76gi0c0ghpwww49urt "salut" "a" "tous" "tout" "le" "monde"
$> diff -U 3 user_output_test3 test3.output | cat -e

Diff OK :D
= Test 4 ===================================================
$> ./r5wlikm3mfh02ykkyxnedu8s "G4YjV2"
$> diff -U 3 user_output_test4 test4.output | cat -e

Diff OK :D
= Test 5 ===================================================
$> ./1gabsbtvc6dnkx26vq67rzdk "qwtNMdv0CPx"
$> diff -U 3 user_output_test5 test5.output | cat -e

Diff OK :D
= Test 6 ===================================================
$> ./jt8arhsi07szsp9osuprsz87 "IALXnNlFv0iUaK8S5"
$> diff -U 3 user_output_test6 test6.output | cat -e

Diff OK :D
= Test 7 ===================================================
$> ./52udfaowgzk2wgi2s5bikf8o "FjnlTdhbEZUJL MpC6f5zbAisHS EmqYB4i XpmWF fB1nHCL0FwqGlA fcUbOs3xhM LOCRXieV7fG 1Omu4yvHwZ3M HSmF6clQE9rk EMU2mGD j4w1vChtYzeMu wa8bFXxWYPSQ gk6C3 aUQ4nStud yqiCeghlJK6 vyQ18lIYst4F Emr5Y1ygxi0cI UZjJIzkvA0lhtB"
$> diff -U 3 user_output_test7 test7.output | cat -e
--- user_output_test7	2018-12-04 09:19:18.000000000 -0800$
+++ test7.output	2018-12-04 09:19:18.000000000 -0800$
@@ -1 +1 @@$
-FFFFFFjjjjjjjjjjnnnnnnnnnnnnnnllllllllllllTTTTTTTTTTTTTTTTTTTTddddhhhhhhhhbbEEEEEZUUUUUUUUUUUUUUUUUUUUUJJJJJJJJJJLLLLLLLLLLLL MMMMMMMMMMMMMppppppppppppppppCCC6ffffff5zbbAiiiiiiiiisssssssssssssssssssHHHHHHHHSSSSSSSSSSSSSSSSSSS EEEEEmmmmmmmmmmmmmqqqqqqqqqqqqqqqqqYYYYYYYYYYYYYYYYYYYYYYYYYBB4iiiiiiiii XXXXXXXXXXXXXXXXXXXXXXXXppppppppppppppppmmmmmmmmmmmmmWWWWWWWWWWWWWWWWWWWWWWWFFFFFF ffffffBB1nnnnnnnnnnnnnnHHHHHHHHCCCLLLLLLLLLLLL0FFFFFFwwwwwwwwwwwwwwwwwwwwwwwqqqqqqqqqqqqqqqqqGGGGGGGllllllllllllA ffffffcccUUUUUUUUUUUUUUUUUUUUUbbOOOOOOOOOOOOOOOsssssssssssssssssss3xxxxxxxxxxxxxxxxxxxxxxxxhhhhhhhhMMMMMMMMMMMMM LLLLLLLLLLLLOOOOOOOOOOOOOOOCCCRRRRRRRRRRRRRRRRRRXXXXXXXXXXXXXXXXXXXXXXXXiiiiiiiiieeeeeVVVVVVVVVVVVVVVVVVVVVV7ffffffGGGGGGG 1OOOOOOOOOOOOOOOmmmmmmmmmmmmmuuuuuuuuuuuuuuuuuuuuu4yyyyyyyyyyyyyyyyyyyyyyyyyvvvvvvvvvvvvvvvvvvvvvvHHHHHHHHwwwwwwwwwwwwwwwwwwwwwwwZ3MMMMMMMMMMMMM HHHHHHHHSSSSSSSSSSSSSSSSSSSmmmmmmmmmmmmmFFFFFF6cccllllllllllllQQQQQQQQQQQQQQQQQEEEEE9rrrrrrrrrrrrrrrrrrkkkkkkkkkkk EEEEEMMMMMMMMMMMMMUUUUUUUUUUUUUUUUUUUUU2mmmmmmmmmmmmmGGGGGGGDDDD jjjjjjjjjj4wwwwwwwwwwwwwwwwwwwwwww1vvvvvvvvvvvvvvvvvvvvvvCCChhhhhhhhttttttttttttttttttttYYYYYYYYYYYYYYYYYYYYYYYYYzeeeeeMMMMMMMMMMMMMuuuuuuuuuuuuuuuuuuuuu wwwwwwwwwwwwwwwwwwwwwwwa8bbFFFFFFXXXXXXXXXXXXXXXXXXXXXXXXxxxxxxxxxxxxxxxxxxxxxxxxWWWWWWWWWWWWWWWWWWWWWWWYYYYYYYYYYYYYYYYYYYYYYYYYPPPPPPPPPPPPPPPPSSSSSSSSSSSSSSSSSSSQQQQQQQQQQQQQQQQQ gggggggkkkkkkkkkkk6CCC3 aUUUUUUUUUUUUUUUUUUUUUQQQQQQQQQQQQQQQQQ4nnnnnnnnnnnnnnSSSSSSSSSSSSSSSSSSSttttttttttttttttttttuuuuuuuuuuuuuuuuuuuuudddd yyyyyyyyyyyyyyyyyyyyyyyyyqqqqqqqqqqqqqqqqqiiiiiiiiiCCCeeeeeggggggghhhhhhhhllllllllllllJJJJJJJJJJKKKKKKKKKKK6 vvvvvvvvvvvvvvvvvvvvvvyyyyyyyyyyyyyyyyyyyyyyyyyQQQQQQQQQQQQQQQQQ18llllllllllllIIIIIIIIIYYYYYYYYYYYYYYYYYYYYYYYYYssssssssssssssssssstttttttttttttttttttt4FFFFFF EEEEEmmmmmmmmmmmmmrrrrrrrrrrrrrrrrrr5YYYYYYYYYYYYYYYYYYYYYYYYY1yyyyyyyyyyyyyyyyyyyyyyyyygggggggxxxxxxxxxxxxxxxxxxxxxxxxiiiiiiiii0cccIIIIIIIII UUUUUUUUUUUUUUUUUUUUUZjjjjjjjjjjJJJJJJJJJJIIIIIIIIIzkkkkkkkkkkkvvvvvvvvvvvvvvvvvvvvvvA0llllllllllllhhhhhhhhttttttttttttttttttttBB$
+FFFFFFjjjjjjjjjjnnnnnnnnnnnnnnllllllllllllTTTTTTTTTTTTTTTTTTTTddddhhhhhhhhbbEEEEEZZZZZZZZZZZZZZZZZZZZZZZZZZUUUUUUUUUUUUUUUUUUUUUJJJJJJJJJJLLLLLLLLLLLL MMMMMMMMMMMMMppppppppppppppppCCC6ffffff5zzzzzzzzzzzzzzzzzzzzzzzzzzbbAiiiiiiiiisssssssssssssssssssHHHHHHHHSSSSSSSSSSSSSSSSSSS EEEEEmmmmmmmmmmmmmqqqqqqqqqqqqqqqqqYYYYYYYYYYYYYYYYYYYYYYYYYBB4iiiiiiiii XXXXXXXXXXXXXXXXXXXXXXXXppppppppppppppppmmmmmmmmmmmmmWWWWWWWWWWWWWWWWWWWWWWWFFFFFF ffffffBB1nnnnnnnnnnnnnnHHHHHHHHCCCLLLLLLLLLLLL0FFFFFFwwwwwwwwwwwwwwwwwwwwwwwqqqqqqqqqqqqqqqqqGGGGGGGllllllllllllA ffffffcccUUUUUUUUUUUUUUUUUUUUUbbOOOOOOOOOOOOOOOsssssssssssssssssss3xxxxxxxxxxxxxxxxxxxxxxxxhhhhhhhhMMMMMMMMMMMMM LLLLLLLLLLLLOOOOOOOOOOOOOOOCCCRRRRRRRRRRRRRRRRRRXXXXXXXXXXXXXXXXXXXXXXXXiiiiiiiiieeeeeVVVVVVVVVVVVVVVVVVVVVV7ffffffGGGGGGG 1OOOOOOOOOOOOOOOmmmmmmmmmmmmmuuuuuuuuuuuuuuuuuuuuu4yyyyyyyyyyyyyyyyyyyyyyyyyvvvvvvvvvvvvvvvvvvvvvvHHHHHHHHwwwwwwwwwwwwwwwwwwwwwwwZZZZZZZZZZZZZZZZZZZZZZZZZZ3MMMMMMMMMMMMM HHHHHHHHSSSSSSSSSSSSSSSSSSSmmmmmmmmmmmmmFFFFFF6cccllllllllllllQQQQQQQQQQQQQQQQQEEEEE9rrrrrrrrrrrrrrrrrrkkkkkkkkkkk EEEEEMMMMMMMMMMMMMUUUUUUUUUUUUUUUUUUUUU2mmmmmmmmmmmmmGGGGGGGDDDD jjjjjjjjjj4wwwwwwwwwwwwwwwwwwwwwww1vvvvvvvvvvvvvvvvvvvvvvCCChhhhhhhhttttttttttttttttttttYYYYYYYYYYYYYYYYYYYYYYYYYzzzzzzzzzzzzzzzzzzzzzzzzzzeeeeeMMMMMMMMMMMMMuuuuuuuuuuuuuuuuuuuuu wwwwwwwwwwwwwwwwwwwwwwwa8bbFFFFFFXXXXXXXXXXXXXXXXXXXXXXXXxxxxxxxxxxxxxxxxxxxxxxxxWWWWWWWWWWWWWWWWWWWWWWWYYYYYYYYYYYYYYYYYYYYYYYYYPPPPPPPPPPPPPPPPSSSSSSSSSSSSSSSSSSSQQQQQQQQQQQQQQQQQ gggggggkkkkkkkkkkk6CCC3 aUUUUUUUUUUUUUUUUUUUUUQQQQQQQQQQQQQQQQQ4nnnnnnnnnnnnnnSSSSSSSSSSSSSSSSSSSttttttttttttttttttttuuuuuuuuuuuuuuuuuuuuudddd yyyyyyyyyyyyyyyyyyyyyyyyyqqqqqqqqqqqqqqqqqiiiiiiiiiCCCeeeeeggggggghhhhhhhhllllllllllllJJJJJJJJJJKKKKKKKKKKK6 vvvvvvvvvvvvvvvvvvvvvvyyyyyyyyyyyyyyyyyyyyyyyyyQQQQQQQQQQQQQQQQQ18llllllllllllIIIIIIIIIYYYYYYYYYYYYYYYYYYYYYYYYYssssssssssssssssssstttttttttttttttttttt4FFFFFF EEEEEmmmmmmmmmmmmmrrrrrrrrrrrrrrrrrr5YYYYYYYYYYYYYYYYYYYYYYYYY1yyyyyyyyyyyyyyyyyyyyyyyyygggggggxxxxxxxxxxxxxxxxxxxxxxxxiiiiiiiii0cccIIIIIIIII UUUUUUUUUUUUUUUUUUUUUZZZZZZZZZZZZZZZZZZZZZZZZZZjjjjjjjjjjJJJJJJJJJJIIIIIIIIIzzzzzzzzzzzzzzzzzzzzzzzzzzkkkkkkkkkkkvvvvvvvvvvvvvvvvvvvvvvA0llllllllllllhhhhhhhhttttttttttttttttttttBB$

Diff KO :(
Grade: 0

= Final grade: 0 ===============================================================
```