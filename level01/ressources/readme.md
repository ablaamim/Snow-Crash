### Level 01 : 

* First i tried ls -la, find / searching method, id as well nothing suspecious outputs.

```bash
$ ls -la && id && pwd
uid=3000(flag00) gid=3000(flag00) groups=3000(flag00),1001(flag)
total 16
dr-x------ 1 flag00 flag00  120 Aug 30  2015 .
d--x--x--x 1 root   flag    340 Aug 30  2015 ..
-r-x------ 1 flag00 flag00  220 Apr  3  2012 .bash_logout
-r-x------ 1 flag00 flag00 3551 Aug 30  2015 .bashrc
-r-x------ 1 flag00 flag00  675 Apr  3  2012 .profile
-r-x------ 1 flag00 flag00   33 Aug 30  2015 README.txt
/home/flag/flag00
```

The challenge utilized knowledge of Unix-like system files (/etc/passwd and /etc/shadow) and password hashing.

## Security Measures: 

---

Password hashes are stored in /etc/shadow to protect them, while /etc/passwd remains world-readable for necessary user information.

The /etc/passwd entry for flag01: 

```plaintext
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```

This entry is broken down into several fields, separated by colons (:):

1. Username: flag01

 * The username for the account.

2. Password: 42hDRfypTqqnw

* Historically, this field contained the hashed password.

* Modern systems typically use an x here, indicating that the actual password hash is in the /etc/shadow file.

* In this specific challenge, it directly contains a DES-hashed password.

3. User ID (UID): 3001

A unique identifier for the user.

4. Group ID (GID): 3001

A unique identifier for the group.

5. User Info: (empty)

Typically contains additional information about the user (e.g., full name).

6. Home Directory: /home/flag/flag01

The path to the user's home directory.

7. Shell: /bin/bash

The default shell for the user.

### Focus on the DES Part: 42hDRfypTqqnw

---

Why Focus on the DES Part?

*  Historical Password Storage:

> Before the /etc/shadow file was introduced, passwords were stored in the /etc/passwd file.

> DES (Data Encryption Standard) was one of the early hashing algorithms used for password encryption in Unix systems.

> Even though storing passwords directly in /etc/passwd is outdated and insecure, challenges like these might use this method to simulate older systems or specific security scenarios.


## Password Cracking :

---
 
> Tools like John the Ripper can crack password hashes, which is often part of these security challenges.


### Cracking the DES Hash:

---

> Use a password cracking tool like John the Ripper to crack the DES hash and retrieve the plaintext password.


```sh
echo 'flag01:42hDRfypTqqnw' > flag01_hash.txt
john flag01_hash.txt
john --show flag01_hash.txt
```

### Result :

---

> John the Ripper outputs the cracked password: abcdefg.


### Go to next level :

---

```bash
$ su flag01
$ Password: abcdef
$  getflag
$ Check flag.Here is your token :  f2av5il02puano7naaf6adaaf
$ su level02
$ Password: f2av5il02puano7naaf6adaaf
```

