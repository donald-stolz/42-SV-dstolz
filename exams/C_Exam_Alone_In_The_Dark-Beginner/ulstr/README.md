# ulstr

## Subject:
```
Assignment name  : ulstr
Expected files   : ulstr.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and reverses the case of all its letters.
Other characters remain unchanged.

You must display the result followed by a '\n'.

If the number of arguments is not 1, the program displays '\n'.

Examples :

$>./ulstr "PeTEr PIpeR pICKeD A PeCK of pIckLEd PEPPers." | cat -e
pEteR piPEr PickEd a pEck OF PiCKleD peppERS.$
$>./ulstr "A pEcK OF picKLED pePPErS PeTEr PIpeR picked.  " | cat -e
a PeCk of PICkled PEppeRs pEteR piPEr PICKED.  $
$>./ulstr | cat -e
$
$>./ulstr "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification." | cat -e
l'EspRIT Ne PEuT PLuS PrOGrESsER S'iL STAgNE ET Si PErSiStENT vaNiTE ET AUTO-JUSTIFICATION.$
$>./ulstr "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  " | cat -e
s'ENtoUrER De SecREt EsT Un SigNe dE MaNqUe dE COnnAIssANcE.  $
$>./ulstr "3:21 Ba  tOut  moUn ki Ka di KE m'en Ka fe fot" | cat -e
3:21 bA  ToUT  MOuN KI kA DI ke M'EN kA FE FOT$
$>./ulstr | cat -e
$
```

## Results
```
= Host-specific information ====================================================
$> hostname; uname -msr
e1z1r5p18.42.us.org
Darwin 17.4.0 x86_64
$> date
Tue Oct  9 09:56:12 PDT 2018
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
Repository URL: auto-exam/2018/c-exam-alone-in-the-dark-beginner/exam_20181009/dstolz

= Git history ==================================================================
$> git -C /var/folders/1h/9fp04d256w75tggx9mqb091r0000gp/T/tmp6s0gdx/user log --pretty='%H - %an, %ad : %s'
dd416300f106a5c5f8af127d07d1e4ffe70902f5 - Exam 42, Tue Oct 9 09:56:01 2018 -0700 : Commiting ulstr
69dc194a4594c7ba74c3002eca2113a897c19f37 - Exam 42, Tue Oct 9 09:30:22 2018 -0700 : Commiting rev_print
2b00a47da1ad2ba4925431900358493ea3c753a3 - Exam 42, Tue Oct 9 09:09:40 2018 -0700 : Commiting aff_z
 
= Collected files ==========================================
$> ls -lAR /var/folders/1h/9fp04d256w75tggx9mqb091r0000gp/T/tmp6s0gdx/user
total 8
-rw-r--r--  1 deepthought  deepthought  763 Oct  9 09:56 __GIT_HISTORY
drwxr-xr-x  3 deepthought  deepthought  102 Oct  9 09:56 aff_z
drwxr-xr-x  4 deepthought  deepthought  136 Oct  9 09:56 rev_print
drwxr-xr-x  3 deepthought  deepthought  102 Oct  9 09:56 ulstr

/var/folders/1h/9fp04d256w75tggx9mqb091r0000gp/T/tmp6s0gdx/user/aff_z:
total 8
-rw-r--r--  1 deepthought  deepthought  91 Oct  9 09:56 aff_z.c

/var/folders/1h/9fp04d256w75tggx9mqb091r0000gp/T/tmp6s0gdx/user/rev_print:
total 32
-rw-r--r--  1 deepthought  deepthought  12288 Oct  9 09:56 .rev_print.c.swp
-rw-r--r--  1 deepthought  deepthought    267 Oct  9 09:56 rev_print.c

/var/folders/1h/9fp04d256w75tggx9mqb091r0000gp/T/tmp6s0gdx/user/ulstr:
total 8
-rw-r--r--  1 deepthought  deepthought  500 Oct  9 09:56 ulstr.c
 
= ulstr ========================================================================
$> gcc -Wextra -Wall -Werror ulstr.c -o user_exe 

= Test 1 ===================================================
$> ./y6t6s7i5le5xl1bp4pqmuw7h 
$> diff -U 3 user_output_test1 test1.output | cat -e

Diff OK :D
= Test 2 ===================================================
$> ./3qca3c8fmnchjtafiwck8ka2 
$> diff -U 3 user_output_test2 test2.output | cat -e

Diff OK :D
= Test 3 ===================================================
$> ./1uq33yyz74ow5gu3ztcjxltz "PN3OWGSK91etTmDk"
$> diff -U 3 user_output_test3 test3.output | cat -e

Diff OK :D
= Test 4 ===================================================
$> ./dopybvciiavsfc4r0pji8tmc "?W2srHOGtfc0Nnlg>P6Y8IFRJEzGAu=TWmf1EhvX @z6DL9I2WH3tkB 	@NdQYsij5)6eRN71EuIpW9tcRCZ8RqgAnvJp;"
$> diff -U 3 user_output_test4 test4.output | cat -e

Diff OK :D
= Test 5 ===================================================
$> ./7ic0dwdwa22ao22rlr4f213d "		>bn6Qp0zy 6cOPp5Z0m Te2ShPsqDMVx -0fukTNX1JUzBKbg48VUuiO0zejyYaGCf	8r5SzcWgkx 1R2aBcN8oHFZ0"
$> diff -U 3 user_output_test5 test5.output | cat -e

Diff OK :D
= Test 6 ===================================================
$> ./67jka9pf0p8cd5po8wjsx2ly "(4UdvNrnt80q9Dwa56ylACPQpwWKV1Loi(NimUcAP<MU2r*3iL2QzI0lVct9X7u 04b0cpNhmSdR36im2pHd 32OoKjsFUy5w7qAGV/GfkUEJ9LWnN24qwST5QuE4OegV87W1	3"
$> diff -U 3 user_output_test6 test6.output | cat -e

Diff OK :D
= Test 7 ===================================================
$> ./tvb3xd5e9epvfjc561quxr0y "4TkcS8yUez3lrxu9WHgPf2E0NoD3gLk9m	96gYN3iDHdE7xp:YjxW5lQwVX1ZEqSd	  g3xaukQW*kJLtXh<yMh0HPNtT1v2lm;d8m2>cX6wtaP		26P51G .lbkuyVMorx4eE8@"
$> diff -U 3 user_output_test7 test7.output | cat -e

Diff OK :D
= Test 8 ===================================================
$> ./y0lhvsy6wtbfb7la02gikfp1 " /Wfa 0mwhx5a	YDsyaW vJe5KcjmtMbZYGU	"
$> diff -U 3 user_output_test8 test8.output | cat -e

Diff OK :D
= Test 9 ===================================================
$> ./nwb2tyr862oc6bsf6kvu41z0 "	)vJKCQpsd8BGqUIL)ficjIe3ZSBJyaHAGp>A10Cd,cCpKYk7EDf+jdFoB89WyV3QAe:N4m7x	<4TOAGubJP5hLI(XNhYw10eklAK )ndb6s176CzG4;V7jTS64me1bJBs)9OZaLd6EsjXC7nKkJ96DV7ZnjNyRpmAQSl9t MwZRnG12z*"
$> diff -U 3 user_output_test9 test9.output | cat -e

Diff OK :D
= Test 10 ==================================================
$> ./2ugwvwwb47snexue7hxifrxw " :t64pZVMv1raPI clSaL0pV3slhIid7Kp27oR3wCyM8Y	6U3sOzup89WFdSDg5iKRFdXWfuve8L1 9"
$> diff -U 3 user_output_test10 test10.output | cat -e

Diff OK :D
= Test 11 ==================================================
$> ./3d5gnin6bymsuw85jgd2chsh "81fX58JAF2GW		=pT93JEH*psrg7w6XcRV5YmO8=zjAsX1DwGSiVY6O7Y6t0yVnGpEH.zVmPJg@x96e+"
$> diff -U 3 user_output_test11 test11.output | cat -e

Diff OK :D
= Test 12 ==================================================
$> ./ooqsjgt9e8fnecf8c97kkjl5 "		hrX-"
$> diff -U 3 user_output_test12 test12.output | cat -e

Diff OK :D
= Test 13 ==================================================
$> ./brmn143voemhu6a59qda55q5 " 7OpPID/TpcIu08fiVlva2ox13PpCY5cqILZA 9tVpY75XS cnX fmrWuJcNsCn4Gq19 9HvndQ6BucWCka 4pTAEfLvIcz0zB1xjYo0 "
$> diff -U 3 user_output_test13 test13.output | cat -e

Diff OK :D
= Test 14 ==================================================
$> ./g06srw5e7goan723pjxkay0w "9t8pk9nKZicLjFB	 	 wIdMfRi8kmLn7lB1:B657eG8OHg2I2TFO8Mu5USX<OsNxYTSgo75GdpNcUYa6X=Un5NHvVLJBDErR:pqYtmL 2n7TkC3ER0gU4pG1Xuv,1oiUmNaVFQuGS/Zvz6scbKI<986YXkP10UsCcjOd		-shxmzy2vIWH66hd6yGwuarFKZPY1."
$> diff -U 3 user_output_test14 test14.output | cat -e

Diff OK :D
= Test 15 ==================================================
$> ./0kvhxidpuhqd9bjf2dhkgo5a "9pzACr97VN0,"
$> diff -U 3 user_output_test15 test15.output | cat -e

Diff OK :D
= Test 16 ==================================================
$> ./ylmer3rdey84sg4ue2wgsk9w "*BKZWTmiD72FhvOIE	:i8HCL:hZIyKQ6DcGVBodpxl	BeFKHOVs@1X3f)Thqs 4NxWPrpE	3Iqp?6GOzqf	6J7fg:"
$> diff -U 3 user_output_test16 test16.output | cat -e

Diff OK :D
= Test 17 ==================================================
$> ./h1b8uwtyj3oqxcc5bglsrqu0 "60lJjqwuyixE,YSEqyBIc4	 91sb-LHdJMegfl/zmFLKM6"
$> diff -U 3 user_output_test17 test17.output | cat -e

Diff OK :D
= Test 18 ==================================================
$> ./s3f4i72ouuq91996ns3zozor ">ZloQ	z6XJKr3cAV2y;Z30q9WSa2E4bpx ,cglP:E2I;MqliK0T faNgHkvnVxL	/18mRDJTX	 2lC0Vym6oN?sbJXg3x4UqtGj16s?TZup2k061Tthz  BfL5yHgKCV *FYf+7UpLm8YokZ6PDuJGW	d0Lzb9wCxvk4B HXnv	  ?heIb3M4GzYRVk7oXQts9jb,"
$> diff -U 3 user_output_test18 test18.output | cat -e

Diff OK :D
= Test 19 ==================================================
$> ./51w9ns3iy2rq1n0yllh6d3fa ",iej8ubqd<on5RWIPM	9RsBiITmp	 (kQtF	>P6C  P4Y9Ql0J;s9P6"
$> diff -U 3 user_output_test19 test19.output | cat -e

Diff OK :D
= Test 20 ==================================================
$> ./y8vrsw9wnjfhzbryzl1nmpg3 "2Cx4bsGN0FlpYHyX8HrbULCsN)8deOMpCEGjJDTNS;j0kM23XPBvI6hArLF <UvSkA8sJbfxLEYd .3KebxdYZD0+lFYcWH9fLwMC3U6qSmGN53ybhYpnjDl  -6BKrls8h7I2zUd1m:ItPC3osVa58F4OYt6Qb )gBPXnWIoEQvYi5q03OqoN9uRf	>N46Pj9mOBotxkIFh	"
$> diff -U 3 user_output_test20 test20.output | cat -e

Diff OK :D
Grade: 1

= Final grade: 1 ===============================================================
```
