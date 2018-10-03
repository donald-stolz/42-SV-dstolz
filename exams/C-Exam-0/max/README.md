## Subject:
```
Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
```

## Results
```
= Host-specific information ====================================================
$> hostname; uname -msr
e1z3r3p16.42.us.org
Darwin 17.4.0 x86_64
$> date
Fri Sep 21 09:56:06 PDT 2018
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
Repository URL: auto-exam/2018/c-exam-alone-in-the-dark-beginner/exam_20180921/dstolz

= Git history ==================================================================
$> git -C /var/folders/04/cb3y2vf957l2n3jlmy3tcx2m0000gp/T/tmp6oHOvC/user log --pretty='%H - %an, %ad : %s'
8f200a0c3d03c1e6e9ca9d097f4d5a6e569b84da - Exam 42, Fri Sep 21 09:55:36 2018 -0700 : Submitting level 2
1a5037fa1f93984868c68b8805507a361607b0bb - Exam 42, Fri Sep 21 09:23:20 2018 -0700 : Finished level 1
cb0bba95777b1e9c6c7ea5e0c50a623c8ad1b61f - Exam 42, Fri Sep 21 09:13:59 2018 -0700 : Finished level 0

= Collected files ==========================================
$> ls -lAR /var/folders/04/cb3y2vf957l2n3jlmy3tcx2m0000gp/T/tmp6oHOvC/user
total 8
-rw-r--r--  1 deepthought  deepthought  754 Sep 21 09:56 __GIT_HISTORY
drwxr-xr-x  3 deepthought  deepthought  102 Sep 21 09:56 ft_putstr
drwxr-xr-x  4 deepthought  deepthought  136 Sep 21 09:56 maff_alpha
drwxr-xr-x  3 deepthought  deepthought  102 Sep 21 09:56 max

/var/folders/04/cb3y2vf957l2n3jlmy3tcx2m0000gp/T/tmp6oHOvC/user/ft_putstr:
total 8
-rw-r--r--  1 deepthought  deepthought  1045 Sep 21 09:56 ft_putstr.c

/var/folders/04/cb3y2vf957l2n3jlmy3tcx2m0000gp/T/tmp6oHOvC/user/maff_alpha:
total 32
-rwxr-xr-x  1 deepthought  deepthought  8564 Sep 21 09:56 a.out
-rw-r--r--  1 deepthought  deepthought  1008 Sep 21 09:56 maff_alpha.c

/var/folders/04/cb3y2vf957l2n3jlmy3tcx2m0000gp/T/tmp6oHOvC/user/max:
total 8
-rw-r--r--  1 deepthought  deepthought  1205 Sep 21 09:56 max.c

= max ==========================================================================
$> gcc -Wextra -Wall -Werror main.c max.c -o user_exe

= Test 1 ===================================================
$> ./xh0syawj382d5u53owj7wful
$> diff -U 3 user_output_test1 test1.output | cat -e

Diff OK :D
= Test 2 ===================================================
$> ./tbosuzalr3kuivg9yecexl7j "-8"
$> diff -U 3 user_output_test2 test2.output | cat -e

Diff OK :D
= Test 3 ===================================================
$> ./37r7blu95m5nsqd1j28lzfvo "20" "3" "-8" "17" "15" "-3"
$> diff -U 3 user_output_test3 test3.output | cat -e

Diff OK :D
= Test 4 ===================================================
$> ./gwpknbacpy04n2yb7dggwu77 "19" "-18" "-1" "-7" "-16" "1" "-3" "-15" "-14" "0" "-8" "-6" "-6" "17" "-9" "6" "1" "-17" "-13" "7" "11" "-4" "-6" "-16" "-7"
$> diff -U 3 user_output_test4 test4.output | cat -e

Diff OK :D
= Test 5 ===================================================
$> ./4zisl0kevqw6uct55m11snms "-10" "2" "-10" "-11" "-19" "-10" "15" "0" "-3"
$> diff -U 3 user_output_test5 test5.output | cat -e

Diff OK :D
= Test 6 ===================================================
$> ./n9ui6w0snelnd09spyqlua37 "-8" "-20" "-16" "-13" "4" "17" "7" "18" "-16" "11" "-16" "-4" "-16" "-18" "-7" "2" "10" "8" "20" "-10" "5" "-18" "9" "9" "-14" "14"
$> diff -U 3 user_output_test6 test6.output | cat -e

Diff OK :D
= Test 7 ===================================================
$> ./6n88e61ppit8z0vd2q2c1a9z "1" "16" "-4" "8" "-4" "4" "14" "-7" "18" "3" "-16" "-5" "1" "-20" "-13" "20" "-1" "12" "7" "14" "-7" "-1" "-2"
$> diff -U 3 user_output_test7 test7.output | cat -e

Diff OK :D
= Test 8 ===================================================
$> ./bi6zq90r16i56rfbiwdcxkss "0" "3" "18" "-20" "7" "-18" "4" "11" "-13" "-9" "-20" "0" "13" "-7" "-4" "-18" "17" "-12" "15" "-8" "-7" "14" "-1" "10" "9" "-16"
$> diff -U 3 user_output_test8 test8.output | cat -e

Diff OK :D
= Test 9 ===================================================
$> ./rp5omnaxy1bm3cq8kg2kpvcm "-12" "-16" "1" "2" "8" "16" "-8" "-13" "15" "2" "-12" "-12" "1" "-2" "-4" "8"
$> diff -U 3 user_output_test9 test9.output | cat -e

Diff OK :D
= Test 10 ==================================================
$> ./6k0tcsc29lgx17qegcg5v28r "-1443069" "19958000" "-11554129" "18543384" "-12091705" "1015493" "-3765097" "962063" "-19660362" "12534978" "3512140" "16358059" "-18466376" "-4979417" "-2086795" "-15186499" "11952319" "10410467"
$> diff -U 3 user_output_test10 test10.output | cat -e

Diff OK :D
= Test 11 ==================================================
$> ./lowvy9bj95vvzvo5ut1awj9q "9590289" "7307840" "-13326405"
$> diff -U 3 user_output_test11 test11.output | cat -e

Diff OK :D
= Test 12 ==================================================
$> ./7m5t9sdcwzhpdpqkhxvjvimj "-17013687" "3128967" "-4726380" "-1098701" "10002447" "-18668244" "-17457014" "18972589" "3243055" "-13899011" "13739979" "-2353923" "2842858" "13823538" "748206" "-2151928" "-14568186" "15878503" "-527225"
$> diff -U 3 user_output_test12 test12.output | cat -e

Diff OK :D
= Test 13 ==================================================
$> ./b4j0bjfwiwwbjomelz3evfvk "-2559657" "7701158" "-2980156" "-18289614" "606177" "15543044" "-15272792" "-5278770" "-8892840" "9559259" "-9128983" "-8447361" "776355" "18372987" "368725" "10626801" "15812803" "-392216" "-16500570" "-3867047" "-8791246" "14408315" "-11490064" "522228" "-6009103" "2202737" "9720364" "-15627606" "-14465282" "4047214" "7680330" "6684913" "-694776" "-16838436" "-15334378" "667792" "15800837" "4545108" "-10780879" "-3645894" "-19304016" "-15488907" "-6430373" "19985301" "6781356" "9881639" "13163516" "-12935644" "17096953" "2534194" "-7959684" "7358035" "-17796806" "-9052317" "-304438" "6196720" "9589815" "-17823225" "-5269065" "16404175"
$> diff -U 3 user_output_test13 test13.output | cat -e

Diff OK :D
= Test 14 ==================================================
$> ./gm6vj9j5sybiwyu9nd3md22p "-5729821" "960040" "-10268859" "-13753037" "-14203689" "-13644966" "-1373085" "8786693" "3299541" "19401079" "-4681062" "-11698180" "15308349" "6217269" "-14870833" "19900239" "-1661941" "5550367" "-1017491" "14590857" "1167551" "7065911" "-10272044" "-9263082" "-7329542" "-7998771" "-2985102" "-3147983" "16326506" "-18857955" "-3523851" "-10046671" "10769357" "14328068" "18427761" "-18323496" "-3484839" "-9265436" "-10193660" "18254733" "3525987" "-16006098" "11960658" "17553659" "8300869" "12774788" "-15449885" "-16166712" "-8051863" "10879279"
$> diff -U 3 user_output_test14 test14.output | cat -e

Diff OK :D
= Test 15 ==================================================
$> ./74pdc6d96vqhxxyfjpaae944 "3458895" "-345310" "13053289" "-17639411" "-2069134" "11987507" "16232419" "-13334338" "-12099319" "16287637" "8400836" "2242666" "-15879816" "8411327" "8227155" "-6659364" "10694248" "14531516" "8833460" "8293072" "10146846" "-220536" "-4058490" "1529130" "14694736" "-3779267" "18311196" "7990704" "-7957588" "19838424" "-9464200" "2791920" "15225023" "-9514403" "-7135231" "-7666692" "3444658" "-16145757" "-13247336" "15609495" "-13631120" "12899284" "-8189438" "15057437" "12573411" "-7970566" "15272535" "17687187" "-3189309" "-6354569" "-4378158" "10888784" "15482536" "9266020" "-7953333" "404628" "-19958359" "-7277767" "5617854" "-19451926" "-16615563"
$> diff -U 3 user_output_test15 test15.output | cat -e

Diff OK :D
= Test 16 ==================================================
$> ./ffxp6cw6msyfpdxk1teuvhz0 "-2380998" "-2910939" "-10907114" "12479799" "-15682003" "13660939" "1895101" "11819995" "16490454" "-14491225" "-2614899" "-14860485" "3129028" "5229697" "7301207" "572155" "6515143" "-13771765" "-8636884" "18497680" "5864414" "19124187" "19032673" "2051902" "8636213" "9315648" "-3768280" "-2457881" "-5664723" "-6244153" "11941942" "-19917204"
$> diff -U 3 user_output_test16 test16.output | cat -e

Diff OK :D
= Test 17 ==================================================
$> ./uq09r767cqgm8vcwqpbdqbij "7593806" "-10490447" "-15306621" "11593301" "-10481503" "-2949129" "1376410" "16193088" "-17435354" "-2342060" "-19767741" "-12500808" "8437631" "9082806" "-14367608" "-1614488" "15785473" "11074744" "3360975" "10416881" "6904018" "7177475" "-15851969" "10451861" "14904015" "16305500" "19383006" "1758841" "-5322202" "15781756" "-13773319" "105416" "9609373" "-2090516" "8891860" "9580809" "-9862043" "-9532724" "-13493645" "-18980497" "7272044" "10129831" "1840106" "2076946" "-19025249" "18735051" "5445100" "17257957" "10138392" "10723476" "-2427298" "-19573266" "-6891244" "8636912" "-9486689" "16039267" "11023548" "9080951" "17583556" "-7857913" "-19666675" "6524236" "18010273" "10045493" "-2979086" "8933892" "19326763" "-4816939" "-6839371" "-4809100"
$> diff -U 3 user_output_test17 test17.output | cat -e

Diff OK :D
= Test 18 ==================================================
$> ./r96qtpf78eviiunkdqycxdzq "19767636" "7772008" "-9914758" "-4179823" "-1007656" "-1677090" "-8847318" "-18694253" "-5889172" "-10688772" "-1472769" "-10196093" "10299915" "-6036998" "13763038" "10359516" "-12495654" "10092909" "-15021521" "14840338" "3790898" "1040943" "-19100349" "8230430" "3747851" "-19347182" "3145881" "1970130" "-16602753" "19858588" "12486272" "-14933613"
$> diff -U 3 user_output_test18 test18.output | cat -e

Diff OK :D
= Test 19 ==================================================
$> ./1rakjyir70byhd2t8yxopq0t "-827951" "6988052" "-12479384"
$> diff -U 3 user_output_test19 test19.output | cat -e

Diff OK :D
= Test 20 ==================================================
$> ./n74ngkqhmqgy4fznn775gwhq "-683408" "2764493" "-1569518" "-10464479" "3737337" "14507522" "6296714" "2826069" "16312673" "2650752" "-3470112" "-632891" "-1420755" "8493937" "10339549" "-1664371" "-6494634" "-1006059" "16910542" "1505967" "-8597194" "18699873" "-5412331" "16218735" "10025832" "11758858" "-5240432" "-19898085" "4354506" "15219301" "-4840558" "-19171964" "-16407992" "-5763257" "-5139502" "5466507" "14964836" "10479794" "15731318" "-16791249" "-3383322" "12075073" "-16956551" "17361504" "302012"
$> diff -U 3 user_output_test20 test20.output | cat -e

Diff OK :D
Grade: 1

= Final grade: 1 ===============================================================
```