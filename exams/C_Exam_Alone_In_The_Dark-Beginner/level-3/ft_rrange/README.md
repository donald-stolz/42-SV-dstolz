# ft_rrange

## Subject:
```
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
```

## Results
```
= Host-specific information ====================================================
$> hostname; uname -msr
e1z1r7p15.42.us.org
Darwin 17.4.0 x86_64
$> date
Fri Sep 21 12:32:39 PDT 2018
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
$> git -C /var/folders/1j/g1t_p42n3yj41r6_nvksm98r0000gp/T/tmpCOXoNR/user log --pretty='%H - %an, %ad : %s'
929d6227c329eaa2978865446d28ec0c6165ffdb - Exam 42, Fri Sep 21 12:32:30 2018 -0700 : Updating level 3 test 3
80c7fcc1010e3facf929007fb2ab95450b27e483 - Exam 42, Fri Sep 21 12:31:21 2018 -0700 : Submitting level 3 test 3
c73a3a515d8b2ff53209734f8305e1ff4286ad19 - Exam 42, Fri Sep 21 11:50:09 2018 -0700 : Submitting level 3, test 2
6150c855c4dadb9cb162f960e3a7c9f6ca5d4df2 - Exam 42, Fri Sep 21 10:56:48 2018 -0700 : Submitting level 3
8f200a0c3d03c1e6e9ca9d097f4d5a6e569b84da - Exam 42, Fri Sep 21 09:55:36 2018 -0700 : Submitting level 2
1a5037fa1f93984868c68b8805507a361607b0bb - Exam 42, Fri Sep 21 09:23:20 2018 -0700 : Finished level 1
cb0bba95777b1e9c6c7ea5e0c50a623c8ad1b61f - Exam 42, Fri Sep 21 09:13:59 2018 -0700 : Finished level 0

= Collected files ==========================================
$> ls -lAR /var/folders/1j/g1t_p42n3yj41r6_nvksm98r0000gp/T/tmpCOXoNR/user
total 8
-rw-r--r--  1 deepthought  deepthought  1780 Sep 21 12:32 __GIT_HISTORY
drwxr-xr-x  3 deepthought  deepthought   102 Sep 21 12:32 ft_putstr
drwxr-xr-x  3 deepthought  deepthought   102 Sep 21 12:32 ft_rrange
drwxr-xr-x  4 deepthought  deepthought   136 Sep 21 12:32 maff_alpha
drwxr-xr-x  3 deepthought  deepthought   102 Sep 21 12:32 max
drwxr-xr-x  3 deepthought  deepthought   102 Sep 21 12:32 paramsum
drwxr-xr-x  3 deepthought  deepthought   102 Sep 21 12:32 rstr_capitalizer

/var/folders/1j/g1t_p42n3yj41r6_nvksm98r0000gp/T/tmpCOXoNR/user/ft_putstr:
total 8
-rw-r--r--  1 deepthought  deepthought  1045 Sep 21 12:32 ft_putstr.c

/var/folders/1j/g1t_p42n3yj41r6_nvksm98r0000gp/T/tmpCOXoNR/user/ft_rrange:
total 8
-rw-r--r--  1 deepthought  deepthought  1413 Sep 21 12:32 ft_rrange.c

/var/folders/1j/g1t_p42n3yj41r6_nvksm98r0000gp/T/tmpCOXoNR/user/maff_alpha:
total 32
-rwxr-xr-x  1 deepthought  deepthought  8564 Sep 21 12:32 a.out
-rw-r--r--  1 deepthought  deepthought  1008 Sep 21 12:32 maff_alpha.c

/var/folders/1j/g1t_p42n3yj41r6_nvksm98r0000gp/T/tmpCOXoNR/user/max:
total 8
-rw-r--r--  1 deepthought  deepthought  1205 Sep 21 12:32 max.c

/var/folders/1j/g1t_p42n3yj41r6_nvksm98r0000gp/T/tmpCOXoNR/user/paramsum:
total 8
-rw-r--r--  1 deepthought  deepthought  1246 Sep 21 12:32 paramsum.c

/var/folders/1j/g1t_p42n3yj41r6_nvksm98r0000gp/T/tmpCOXoNR/user/rstr_capitalizer:
total 8
-rw-r--r--  1 deepthought  deepthought  1709 Sep 21 12:32 rstr_capitalizer.c

= ft_rrange ====================================================================
$> gcc -Wextra -Wall -Werror main.c ft_rrange.c -o user_exe

= Test 1 ===================================================
$> ./uvyt5f5oysxxfjc8r1hgv39f
$> diff -U 3 user_output_test1 test1.output | cat -e

Diff OK :D
= Test 2 ===================================================
$> ./tgwc496x4jf43qmrvpw92kde "21" "2313" "12"
$> diff -U 3 user_output_test2 test2.output | cat -e

Diff OK :D
= Test 3 ===================================================
$> ./waj9kv6arhz29iwo35smty6p "2147483647" "2147483640" "7"
$> diff -U 3 user_output_test3 test3.output | cat -e

Diff OK :D
= Test 4 ===================================================
$> ./lcwoq1nojdoh7mr80rdp749v "-2147483648" "-2147483600" "48"
$> diff -U 3 user_output_test4 test4.output | cat -e

Diff OK :D
= Test 5 ===================================================
$> ./wq1ia5oad790seiehmr7jgyz "0" "0" "1"
$> diff -U 3 user_output_test5 test5.output | cat -e

Diff OK :D
= Test 6 ===================================================
$> ./n062qm772kga184ywwwwxjn9 "879938931" "879938910" "22"
$> diff -U 3 user_output_test6 test6.output | cat -e

Diff OK :D
= Test 7 ===================================================
$> ./lgfwziq5kuldjgdi58le3f7g "1033768484" "1033768530" "47"
$> diff -U 3 user_output_test7 test7.output | cat -e

Diff OK :D
= Test 8 ===================================================
$> ./n9mhcd7w1o0vxequgy54doe9 "-75381792" "-75381828" "37"
$> diff -U 3 user_output_test8 test8.output | cat -e

Diff OK :D
= Test 9 ===================================================
$> ./mnowaxvzyh49873ajhe2uk12 "1227825786" "1227825812" "27"
$> diff -U 3 user_output_test9 test9.output | cat -e

Diff OK :D
= Test 10 ==================================================
$> ./1rddnw0fsf1hxms9lu4xva1x "1194172006" "1194171967" "40"
$> diff -U 3 user_output_test10 test10.output | cat -e

Diff OK :D
= Test 11 ==================================================
$> ./5vnqx8gfk46zks8pv3fm3ou6 "683796365" "683796354" "12"
$> diff -U 3 user_output_test11 test11.output | cat -e

Diff OK :D
= Test 12 ==================================================
$> ./v1pdfdfqkj20hpacx3sg30ky "1938051580" "1938051570" "11"
$> diff -U 3 user_output_test12 test12.output | cat -e

Diff OK :D
= Test 13 ==================================================
$> ./c9bho1auc6k03cbzyq015yic "1760346291" "1760346294" "4"
$> diff -U 3 user_output_test13 test13.output | cat -e

Diff OK :D
= Test 14 ==================================================
$> ./46k4si7mfv7elefpcnfz6dgd "1878257985" "1878257968" "18"
$> diff -U 3 user_output_test14 test14.output | cat -e

Diff OK :D
= Test 15 ==================================================
$> ./6lefoxu5v4z2v44h6cznajwj "583890108" "583890075" "34"
$> diff -U 3 user_output_test15 test15.output | cat -e

Diff OK :D
= Test 16 ==================================================
$> ./9xn3vathyt6qckgtzhob1m6h "-100426986" "-100427021" "36"
$> diff -U 3 user_output_test16 test16.output | cat -e

Diff OK :D
= Test 17 ==================================================
$> ./apl19aummmv4piy8i62xwmri "1649309526" "1649309485" "42"
$> diff -U 3 user_output_test17 test17.output | cat -e

Diff OK :D
= Test 18 ==================================================
$> ./xmdu7tub7i1hil226di7opma "796489896" "796489896" "1"
$> diff -U 3 user_output_test18 test18.output | cat -e

Diff OK :D
= Test 19 ==================================================
$> ./5oivly27r25a73ber9j8pvmv "1922559346" "1922559299" "48"
$> diff -U 3 user_output_test19 test19.output | cat -e

Diff OK :D
= Test 20 ==================================================
$> ./57uk1zgq28vrkr9lf48vhsi9 "-189061975" "-189061997" "23"
$> diff -U 3 user_output_test20 test20.output | cat -e

Diff OK :D
Grade: 1

= Final grade: 1 ===============================================================
```
