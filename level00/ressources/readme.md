### Level 00 :

---

> this level involves searching for files owned by a specific user (flag00 in this case) across the entire file system (/).

---

Here are usual commands to start testing to find hints on a CTF :

**Find files owned by a specific user (`USER_X`):**
   ```bash
   $ find / -user USER_X
```
> Description: Searches the entire filesystem (/) for files owned by the specified user (USER_X). Useful for identifying files that may contain sensitive information or flags.

**Find files by name (NAME_X) :**
```bash
$ find / -name NAME_X
```

> Description: Searches the entire filesystem (/) for files or directories with the exact name (NAME_X). Helpful for locating specific files mentioned in clues or challenges.

**Find regular files owned by a specific user (USER_X):**
```bash
$ find / -type f -user USER_X
```

> Description: Searches for regular files (-type f) owned by the specified user (USER_X) across the filesystem (/). Useful for pinpointing files that might contain flags or hidden information.

**List running processes:**

```bash
$ ps
```

> Description: Displays currently running processes on the system. Useful for identifying suspicious or privileged processes that might provide hints or access to flags.

**View /etc/shadow file directly:**
```bash
$ cat /etc/shadow
```

> Description: Displays the contents of the /etc/shadow file, which contains password hashes for system accounts. Valuable for extracting credentials or privileged access information.

**View /etc/passwd file:**
```bash
$ cat /etc/passwd
```

> Description: Prints out the contents of the /etc/passwd file, which contains basic information about user accounts on the system. Useful for gathering usernames or identifying potential targets for further exploitation.

**Check sudo privileges (sudo -l):**
```bash
$ sudo -l
```
> Description: Lists the commands that the current user can execute with sudo privileges. Helpful for identifying opportunities for privilege escalation or executing commands as another user.


### This level involves searching for files owned by a specific user :

---

```bash
$ find / -type f -user flag00 2>/dev/null
$ /usr/sbin/john
$ /rofs/usr/sbin/john
$ cat /user/sbin/john
$ cdiiddwpgswtgt
```

* 2>/dev/null : redirect stderr to /dev/null device to discard unwanted output!

> therefore we cat the file /usr/sbin/john, its content is : cdiiddwpgswtgt , and we use this website [link](https://www.cachesleuth.com/multidecoder/) to decrypt it


### The flag captured :

---

```bash
nottoohardhere
```

### Go to next level :

---

```bash
$ su flag00
$ Password: nottoohardhere
$ getflag
$ Check flag.Here is your token : x24ti5gi3x0ol2eh4esiuxias 
$ su level01
$ Password: x24ti5gi3x0ol2eh4esiuxias
```