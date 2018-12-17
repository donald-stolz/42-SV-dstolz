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
TODO: Setup a file with 42 header i.e. 't42 main.c' -> creates blank file with header already completed
- Could add options i.e. -h to create a basic header -m for basic main
- Worst case copy header and use own variables for date & time
/usr/share/vim/vim80/plugin/stdheader.vim
```
