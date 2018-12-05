1. Write a script which displays only the login, UID and Path of each entry of the /etc/passwd file.

```
sudo cat /etc/passwd | awk -F  ":" '{print $1 "   " $3 "   " $6}' | column -t
```

2. Write a script which delete an ACTIVE user on the VM.

```
TODO
```

3. Write a script of your choice

```
TODO
```
