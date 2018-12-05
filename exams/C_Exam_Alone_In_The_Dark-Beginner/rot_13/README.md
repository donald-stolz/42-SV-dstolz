#rot_13
- [ ] Corrected

## Subject:
```
Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>
```

### Results
```
= Host-specific information ====================================================
$> hostname; uname -msr
e1z1r5p26.42.us.org
Darwin 17.4.0 x86_64
$> date
Tue Nov 13 09:44:37 PST 2018
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
Repository URL: auto-exam/2018/c-exam-alone-in-the-dark-beginner/exam_20181113/dstolz

= Git history ==================================================================
$> git -C /var/folders/r7/xgcz6n1j5rlb_hdd700vb4f80000gp/T/tmp92ny9L/user log --pretty='%H - %an, %ad : %s'
64e6fbd1afe46c134466e7bede6cf788a79ba8de - Exam 42, Tue Nov 13 09:44:25 2018 -0800 : Finished rot 13
e159294d3498b5aa9c9654ecde6b0b271f99152e - Exam 42, Tue Nov 13 09:08:17 2018 -0800 : Finished aff_z
 
= Collected files ==========================================
$> ls -lAR /var/folders/r7/xgcz6n1j5rlb_hdd700vb4f80000gp/T/tmp92ny9L/user
total 8
-rw-r--r--  1 deepthought  deepthought  433 Nov 13 09:44 __GIT_HISTORY
drwxr-xr-x  3 deepthought  deepthought  102 Nov 13 09:44 aff_z
drwxr-xr-x  3 deepthought  deepthought  102 Nov 13 09:44 rot_13

/var/folders/r7/xgcz6n1j5rlb_hdd700vb4f80000gp/T/tmp92ny9L/user/aff_z:
total 8
-rw-r--r--  1 deepthought  deepthought  78 Nov 13 09:44 aff_z.c

/var/folders/r7/xgcz6n1j5rlb_hdd700vb4f80000gp/T/tmp92ny9L/user/rot_13:
total 8
-rw-r--r--  1 deepthought  deepthought  372 Nov 13 09:44 rot_13.c
 
= rot_13 =======================================================================
$> gcc -Wextra -Wall -Werror rot_13.c -o user_exe 
rot_13.c:16:7: error: unused variable 'temp' [-Werror,-Wunused-variable]
        char temp;
             ^
1 error generated.

Could not compile 'user_exe'
Grade: 0

= Final grade: 0 ===============================================================
```
Temp has been removed.