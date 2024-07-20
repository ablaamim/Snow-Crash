### Level 02 :

* Repeat same previous procedures : 

```bash
$ id && ls -la && pwd
uid=2002(level02) gid=2002(level02) groups=2002(level02),100(users)
total 24
dr-x------ 1 level02 level02  120 Mar  5  2016 .
d--x--x--x 1 root    users    340 Aug 30  2015 ..
-r-x------ 1 level02 level02  220 Apr  3  2012 .bash_logout
-r-x------ 1 level02 level02 3518 Aug 30  2015 .bashrc
----r--r-- 1 flag02  level02 8302 Aug 30  2015 level02.pcap  ---> suspected new file
-r-x------ 1 level02 level02  675 Apr  3  2012 .profile
/home/user/level02
```

* i tried to cat it :

```bash
$ cat level02.pcap
ò@f&N.J'̊$E<@@J>;;ߙO/Y
f&NJJ$'̊E<@@/;;/YOA 8
.f&NB'̊$E4@@JE;;ߙO/YºBsp
f&N֡EE$'̊E7ԣ@@;;/YOB
.f&N͢B'̊$E4@@JD;;ߙO/YºEs`
f&NE'̊$E7@@J@;;ߙO/YºEsW
f&NZBB$'̊E4Ԥ@@;;/YOEŀ
.f&NTT$'̊EFԥ@@;;/YOEŀŧ
. #'$@f&NT'̊$EF@@J0;;ߙO/YźWs
 #'$@f&N)ZZ$'̊ELԦ@@y;;/YOW׀ō
.@f&Nݥ'̊$Ew@@I;;ߙO/Y׺os
8400,38400#SodaCan:0'DISPLAYSodaCan:0xterm@f&N0TT$'̊EFԧ@@~;;/YOo9
.f&N'̊$E~@@I;;ߙO/YsES
b B
1!@f&NFII$'̊E;Ԩ@@;;/YOd#
.f&NаI'̊$E;@@J8;;ߙO/Ydsn
```

* Then i made a research about pcap instruction : [pcap extention](https://www.comparitech.com/net-admin/pcap-guide/)

> PCAP stands for **Packet Capture**, which is a file format used to store network packet data captured from a network interface. It is commonly associated with network analysis and troubleshooting activities...

* i used chatgpt as well, and it suggested to use tshark and follow the tcp stream :

```bash
$ tshark -r level02.pcap -q -z follow,tcp,hex,0
```

* i found a password but it did not work.

```bash
$ su flag02
Password: ft_wandr...NDRel.L0L
su: Authentication failure
```
* Using ascii tables i found out that :

|Dec|Hex|Binary|HTML|Char|Description|
|127|7F|01111111|&#127;|DEL|delete|
|13|0D|00001101|&#13;|CR|Carriage Return|

* So i deleted them from original string :

```bash
$ su flag02
Password: ft_wandrNDRelL0L
su: Authentication failure
```

* After that i tried to delete the 'DEL' (7d) characters :

```
ft_wandrNDRelL0L
     ^^^ et ^
ft_waNDReL0L
```

* Finally : 

```bash
$ su flag02
Password: ft_waNDReL0L
Don't forget to launch getflag !

$ getflag
Check flag.Here is your token : kooda2puivaav1idi4f57q8iq
```