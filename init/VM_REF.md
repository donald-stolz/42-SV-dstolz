# Virtual Box VM Commands

- Start VM

```
vboxmanage startvm UbuntuServer --type headless
```

- Log into VM

```
ssh -p 2222 <username>@localhost
```

- Shutdown VM

```
vboxmanage controlvm UbuntuServer poweroff
```

- Pause VM

```
vboxmanage controlvm UbuntuServer savestate
```
