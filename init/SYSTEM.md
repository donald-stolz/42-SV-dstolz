1. In what file can you find the installed version of your Debian? Define: Debian.

```
/etc/debian_version
```

2. ?What command can you use to rename your system?

```
hostname "new_name"
```

3. ?What file has to be modified to make it permanent?

```
/etc/hostname
```

4. What command gives you the time since your system was last booted?

```
uptime
```

5. Name the command that determines the state of the SSH service.

```
service ssh status
```

6. Name the command that reboots the SSH service.

```
service ssh restart
```

7. Figure out the PID of the SSHD service.

```

```

8. What file contains the RSA keys of systems that are authorized to connect via SSH?

```
/etc/ssh/sshd_config
```

9. What command lets you know who is connected to the System?

```
who
```

10. Name the command that lists the partition tables of drives?

```
sudo  fdisk -l
```

11. Name the command that displays the available space left and used on the system in an humanly understandable way

```
df -h
```

12. Figure out the exact size of each folder of /var in a humanly understandable way followed by the path of it

```
sudo du -h /var/*
```

13. Name the command that find, in real time, currently running processes

```
top
```

14. Run the ‘tail -f /var/log/syslog‘ command in background

```
tail -f /var/log/syslog &
```

15. Find the command that kills the background command’s process

```
pkill tail
```

16. Find the service which makes it possible to run specific tasks following a regular schedule

```
cron
```

17. Find the command that allows you to connect via ssh on the VM.(In parallel with the graphic session)

```

```

18. Find the command that kills ssh service

```

```

19. List all services which are started at boot time and name this kind of services

```

```

20. List all existing users on the VM

```

```

21. List all real users on the VM

```

```

22. Find the command that add a new local user

```

```

23. Explain how connect yourself as new user. (With graphic session and ssh session)

```

```

24. Find the command that list all packages

```

```
