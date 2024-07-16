### Level 00 :

---

> this level is based privilege escalation or what is called information gathering during a cybersecurity capture-the-flag (CTF), It involves searching for files owned by a specific user (flag00 in this case) across the entire file system (/). Here's a breakdown of what each part of the command does:

* . find / -type f -user flag00: This command searches (find) starting from the root directory (/) for regular files (-type f) that are owned by the user flag00 (-user flag00).

* 2>&1: Redirects standard error (stderr) to standard output (stdout). This ensures that any error messages are also captured and processed by the subsequent commands.

*   | grep -v "Permission denied": Pipes (|) the output of the find command to grep, which filters (-v) out (Permission denied) lines containing the phrase "Permission denied". This is useful to exclude error messages that indicate access restrictions on certain files or directories.

In a CTF context, this pattern helps in identifying files or directories owned by the flag00 user that might contain clues or flags necessary to progress in the challenge.

### Output of the command :

---

```bash
level00@SnowCrash:~$  find / -type f -user flag00 2>&1 | grep -v "Permission denied"
find: `/proc/2174/task/2174/fd/5': No such file or directory
find: `/proc/2174/task/2174/fdinfo/5': No such file or directory
find: `/proc/2174/fd/5': No such file or directory
find: `/proc/2174/fdinfo/5': No such file or directory
/usr/sbin/john
/rofs/usr/sbin/john

```

> therefore we cat the file /usr/sbin/john, its content is : cdiiddwpgswtgt , and we use this website [link](https://www.cachesleuth.com/multidecoder/) to decrypt it


### The flag captured :

---

```bash
nottoohardhere
```