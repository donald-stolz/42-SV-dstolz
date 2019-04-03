# Notes/Pseudo Code

## TODO

- [ ] Error management -> Can't access & does not exist
- [ ] [setuid, setgid and sticky bits](https://linuxconfig.org/how-to-use-special-permissions-the-setuid-setgid-and-sticky-bits)
- [ ] Handling files as args

```c
./src/ft_ls.c
/*
 *1. Parse args
 *		- Get directory args into linked arglist
 *		- If sort options, sort parents first
 * 	2. Call ft_ls on list of args(Parent directory(ies)) with option flags
 * 	3. First check for -R option
 * 		- Update directory list with children
 * 	4. Sort children
 * 	5. Print elements
 * 	6. Return to main
 *  7. Free structures
 */

./src/ft_print.c
/*
 * 0. (Check if arg is single parent && -R) or if multiple
 * 	-	Add t_bool to arguments
 *  -	Check if is_dir; false -> simply print name & \n (Careful w/ -l)
 *  - true don't display dir->path
 *  - false display dir->path w/ ':'
 * 1. Check if l_op;
 * 		- true-> print total then -l children
 * 		- Else iterate through and print children
 * 2. Check -R
 * 		- true -> ft_print_ls children
 * 		- false -> next parent
 */

./src/ft_free.c
/*
 * 0. Get head of list
 * 1. Send children to get freed
 * 2. strdel name & path
 * 3. Go to next
 */
```
