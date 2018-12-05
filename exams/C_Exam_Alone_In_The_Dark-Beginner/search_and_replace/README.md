# search_and_replace

## Subject:
```
Assignment name  : search_and_replace
Expected files   : search_and_replace.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program called search_and_replace that takes 3 arguments, the first
arguments is a string in which to replace a letter (2nd argument) by
another one (3rd argument).

If the number of arguments is not 3, just display a newline.

If the second argument is not contained in the first one (the string)
then the program simply rewrites the string followed by a newline.

Examples:
$>./search_and_replace "My life for Aizr" "z" "u"
My life for Aiur
$>./search_and_replace "gaetan" "art" "zul" | cat -e
$
$>./search_and_replace "zaz" "r" "u" | cat -e
zaz$
$>./search_and_replace "jacob" "a" "b" "c" "e" | cat -e
$
$>./search_and_replace "In foct, stoff crew ore very nice. They like metol." "o" "a" | cat -e
In fact, staff crew are very nice. They like metal.$
```

## Results
```
= Host-specific information ====================================================
$> hostname; uname -msr
e1z2r4p20.42.us.org
Darwin 17.4.0 x86_64
$> date
Tue Sep 25 09:31:20 PDT 2018
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
Repository URL: auto-exam/2018/c-exam-alone-in-the-dark-beginner/exam_20180925/dstolz

= Git history ==================================================================
$> git -C /var/folders/ms/pvv_67f16cv__t94q07x65hm0000gp/T/tmpxA0tNa/user log --pretty='%H - %an, %ad : %s'
f477dcf6086ba33a6cb1e58e8bc7c88767b6373c - Exam 42, Tue Sep 25 09:30:54 2018 -0700 : Submitting level 1
1b9fb7392a7061420d8edde2168d4734c26dbd8c - Exam 42, Tue Sep 25 09:07:18 2018 -0700 : Submitting level 0

= Collected files ==========================================
$> ls -lAR /var/folders/ms/pvv_67f16cv__t94q07x65hm0000gp/T/tmpxA0tNa/user
total 8
-rw-r--r--  1 deepthought  deepthought  494 Sep 25 09:31 __GIT_HISTORY
drwxr-xr-x  3 deepthought  deepthought  102 Sep 25 09:31 only_z
drwxr-xr-x  3 deepthought  deepthought  102 Sep 25 09:31 search_and_replace

/var/folders/ms/pvv_67f16cv__t94q07x65hm0000gp/T/tmpxA0tNa/user/only_z:
total 8
-rw-r--r--  1 deepthought  deepthought  982 Sep 25 09:31 only_z.c

/var/folders/ms/pvv_67f16cv__t94q07x65hm0000gp/T/tmpxA0tNa/user/search_and_replace:
total 8
-rw-r--r--  1 deepthought  deepthought  1424 Sep 25 09:31 search_and_replace.c

= search_and_replace ===========================================================
$> gcc -Wextra -Wall -Werror search_and_replace.c -o user_exe

= Test 1 ===================================================
$> ./3x0fykchn5rocshg0lnpm5ec
$> diff -U 3 user_output_test1 test1.output | cat -e

Diff OK :D
= Test 2 ===================================================
$> ./sq9wbyxrlfhrlyl54gntydxg
$> diff -U 3 user_output_test2 test2.output | cat -e

Diff OK :D
= Test 3 ===================================================
$> ./13pe1kb84hp02jll32jpbcgk "0YH7RX3KluOIcA"
$> diff -U 3 user_output_test3 test3.output | cat -e

Diff OK :D
= Test 4 ===================================================
$> ./hilqcjq5d5ks5sybvx9zt5nb "5iS4yKYLrcIMG@WMSVrQkfCa3sHB 	wxfk.NIrhGdtvFTEo8pA		0GKgaEWnOxJZjH7i  lEgASmhPDbRnGItj3	oZPVHm2K4Ta1I0JL0GnsNoctUO1O4TmSCiHX8auVny	757mzD39UpN	0uJUk2tBj	-bP4reg3;Od7IH9S7yQMh0Jcr	@" "a" "T"
$> diff -U 3 user_output_test4 test4.output | cat -e

Diff OK :D
= Test 5 ===================================================
$> ./6g32ayki8wuphw1686u6cina " p5yruaxtn93DX6H9NbTe5j8,1gSkXsmDf8qT71y9m1LWX8eqAQzbcd=VSvT6GNxbdPpyr/Qxpw9kv7z7wqvu07Ef2eT*s53TMKzwVIom9Z5twBmDUVFsAQz3W4Ku89pj0RxqPzdOYsDL		?iIxVdN1wX6+QABhpRN4HtFu6Ta53Etwu6sf2AsWFrQXCfSM2" "H" "c"
$> diff -U 3 user_output_test5 test5.output | cat -e

Diff OK :D
= Test 6 ===================================================
$> ./qrpthwu5n60pc9kbfrw79xgt "9fOcR0sV8wKIUz@" "L" "C"
$> diff -U 3 user_output_test6 test6.output | cat -e

Diff OK :D
= Test 7 ===================================================
$> ./kg7inry8mfk3m7pif62k91fm " ?savBwpE8n9P5Cz<1UEwlGrhnY3oIOZpR@oh1bRu rRhi	-9GRMCn81rWOL8dxj3KynsPuMU 8Ffy8jdAHnzim9v9VZOs	2z7LGYM(TWnJMiLHDfC	3" "G" "x"
$> diff -U 3 user_output_test7 test7.output | cat -e

Diff OK :D
= Test 8 ===================================================
$> ./vqwhza2akvfs7glx4djbl5bt "@x1qmDJA8Xh8xFb6UkowAs2Zn ;vU0orEqx7mdBzZe<uWTZdgixm0j4plQJA;Fgk95sV6a7Rb4onhQKP69	*c6pC3d?puLVJtP*yxWli2p9;fcLGSePpI1U3tRi7?f02SdseV	Pwm9BckT 2Na0;mK9E0	?cSXqaTek-2Z4	 6UwtdefARcKkqQl9=" "B" "D"
$> diff -U 3 user_output_test8 test8.output | cat -e

Diff OK :D
= Test 9 ===================================================
$> ./a1ajh7mrfhy3kkz9681vcl5w "365sSYl /xw1GSfqBIUMbYcmd;i5gJf3BNijsyIGa6n2A8	9eliAuz4hNxTcb7	6ikM,iICg2=AcNU4fjDh1Ygzpe?nhofcU	)ghwWZGiHa3sjdoz ?fDNpzm23IR	)mT2uJZBhl3gD68qx	 6rnFML=" "U" "L"
$> diff -U 3 user_output_test9 test9.output | cat -e

Diff OK :D
= Test 10 ==================================================
$> ./90iv0ufithxvvtg06r2viym7 "15Pn0GtmSjE(AQywdax342oRUcaWjrxK7LhS5  ?4uXvLyIpDCMJ*CZqG4Am1JFPaTgK9TdjXba5PKRS /pXymhxitgY." "d" "q"
$> diff -U 3 user_output_test10 test10.output | cat -e

Diff OK :D
= Test 11 ==================================================
$> ./11v5kkc1iatcv47g81nlodkj "	/PCZqX6ct4erBd8G9qKl5bWvN3x8sm +bWEpdn39uRl0w-DgzpCVl7.ij6Y/v4Er14PQpfgRmotvUV	,EKk7s5mzO HU3Ck(BILys4pQuv 21MZBH8kjtb09fFyh7" "k" "G"
$> diff -U 3 user_output_test11 test11.output | cat -e

Diff OK :D
= Test 12 ==================================================
$> ./zwqgsonsx0ie83sozhrfy0ea ">Nmk5x9R 		 YlGcmoJpHK*vmKQ1zru9bkAtLnq		xY2vcqOBdRby40SoBMZjlUgx9OTaC22NYs7MI*I3C	" "W" "n"
$> diff -U 3 user_output_test12 test12.output | cat -e

Diff OK :D
= Test 13 ==================================================
$> ./vvzpfk7djr53ahdqo26jr4b9 "5Rcrs8EGlFQ 	-D8Mi6r3NHunaU>NjxOB(6Mb0JDFm4XzPUaAfh 2cJEu5S	" "V" "u"
$> diff -U 3 user_output_test13 test13.output | cat -e

Diff OK :D
= Test 14 ==================================================
$> ./46dyjv1ahve4cv5wdlunuz84 "1eBld4aUEow 	=YsU59N6;TlD0pZ3B8rPzq1oO9uI	.9edNLs25Pd0hKjYAoU26IXlp;aDUAdXtBZJEv3z)l9Qj8iU0hms		HoLVS1Y		7" "q" "O"
$> diff -U 3 user_output_test14 test14.output | cat -e

Diff OK :D
= Test 15 ==================================================
$> ./bsjtbtkkrlisoepmr9vuvwtm "48cGdihI1oWj9fk6epDPBlM1Ca8fr		PjNJiA2VkTn	<pJCjro16ToHgn8kfzRQl8*Vrv0iDAtWu7ZHjwy@UeOoD<Qb5rD1C1mHehU4c?0FyGsJ3k5WwKz1A (9diBbNTtsgGmj?Lav2FSeczT," "J" "q"
$> diff -U 3 user_output_test15 test15.output | cat -e

Diff OK :D
= Test 16 ==================================================
$> ./950ukp9i1wwmuk342tttl0qz "<v6G	-GLjigPJm4CMH 	  	K6RxobdArEjtpqykz?NvbJ7yit01L>Vsz>plw2a443Fl7CRY6KrPAIy0U*Gfbzt2uNM8QEsC32ezTWRwPxZFL/gEGaDbT9tjX <zIk4wSby2Ct2GOXW3p 	*5l4)QN0Aaexh3Ejs 	 4y1IJN6ZDmRYWEi5 g2PRZ9cfNBrLIv3	+xTb8wpPZ+CT5kUoW(" "K" "v"
$> diff -U 3 user_output_test16 test16.output | cat -e

Diff OK :D
= Test 17 ==================================================
$> ./90zqpsjb9cq8kfto4az7ob1g "8sNMOlg8n5jcF07/0hu6YOQEFv8N	 	<iCndTM9Vec38l29XcTQ8IpOmVa9EfD00d1DPayFleuYb>yin2Q,ZSxj<aMUZduroJtXAR5x941AFkSlw		" "g" "S"
$> diff -U 3 user_output_test17 test17.output | cat -e

Diff OK :D
= Test 18 ==================================================
$> ./dvdof922wsmsmt147qdul3pz "=Orwf19WsIb:hZ3Vj97	70WAH8Ggze -gBG24CADZj ,9DJlFrnC5yBkS 8h5kE8rAUMHlg	 o1f6dRBFDYC0QL7H	AZeB 	(KHsx.AE0eyg -vby3DcNFd5CG	 	 c0sDQ23GerK	   HZK7C8gsVxk0GW*" "Y" "c"
$> diff -U 3 user_output_test18 test18.output | cat -e

Diff OK :D
= Test 19 ==================================================
$> ./yzjyi5v4liv5b4iuzx2jja5n " 	,UtRbSX3NsCjMEq1wTZ8hm  FuU9ZBQvDI*UbQBXWiEOqw9sI7K5dZgYncBT7kR3Oq4	32DoK7lTMw0JhBd5ygwsn19 NiY5A0TdDP6ql934DQga 	64qBgUfc ilZRDwgzPIpHe814ZOYc5vld8UFMJueaD	=Hua50Okt9X6doBb 		8EHvtAoF<tqh601SaLO988PF9.v9gSsG4znCcHNd7PE84LRng9bo7" "K" "t"
$> diff -U 3 user_output_test19 test19.output | cat -e

Diff OK :D
= Test 20 ==================================================
$> ./lby52mspq0q3wp9j5k7unlnt "?E6YzR4UrOT=" "e" "l"
$> diff -U 3 user_output_test20 test20.output | cat -e

Diff OK :D
Grade: 1

= Final grade: 1 ===============================================================
```
