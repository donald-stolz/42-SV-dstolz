/*
 *	1. Parse args
 *		- Get directory args into linked arglist
 *		- If sort options, sort parents first
 * 	2. Call ft_ls on list of args(Parent directory(ies)) with option flags
 * 	3. First check for -R option
 * 		- Update directory list with children
 * 	4. Sort dirlist
 * 	5. Print then free dirlist elements
 * 	6. Return to main
 *  7. Free parent -> Next
 *  8. Free options & end
 * 
 * Options:
 * 	-a -> Show hidden
 * 	-l -> List details
 * 	-R -> List children
 *  -r -> Reverse sort
 * 	-t -> Sort by time
 * 
 * Can possibly save:
 *  - Sort functions besides -R
 * 	- Print functions
 * 
 * Redo:
 * 	- Main
 * 	- ft_ls
 * 	- Arg parser
 */