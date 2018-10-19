# b_ls
### Summary: In short: This project will make you recode the command “ls”

>Amongst the numerous options available, we are asking you to create the
following: -l, -a, -r and -t.  
>Within your mandatory part you are allowed to use the following functions:
>* write
>* opendir
>* readdir
>* closedir
>* stat
>* lstat
>* getpwuid
>* getgrgid
>* listxattr
>* getxattr
>* time
>* ctime
>* readlink
>* malloc
>* free
>* perror
>* strerror
>* exit
>* printf

## Notes & Pseudo Code  

### Basic Pseudo Code:  
0. Parse command line arguments. Get options and create list of directories.
1. Get directory stats/info for (n) directory.
2. Create a linked list of contents.
3. Send directory's list to sort - Sort based on options.
4. Display list - Display sorted list based on options  
5. Repeat 1-4 for the next item in the list of directories 
 
  
#### Structs:
```h
typedef enum { false, true } t_bool;

typedef struct		s_opt
{
	t_bool	l_op; // use a long listing format
	t_bool	a_op; // --all; do not ignore entries starting with .
	t_bool	r_op; // --reverse; reverse order while sorting
	t_bool	t_op; // sort by modification time
}			t_opt;

typedef struct 			s_dir
{
	char 		*permissions;	// File permissions (intially st_mode); 
	nlink_t 	links;		// Number of links; Careful with how you read symlinks
	char 		*owner;		// Owner name; getpwuid(st_uid)
	char 		*group;		// Owner group; getgrgid(st_gid)
	off_t 		size;		// File size
	time_t 		mtime;		// Time of last modification; Leave in time_t for sort
	char 		*name;		// Name of file; May chang to full path
	struct s_dir	*next;		// Link to next t_dir struct
}				t_dir;

typedef struct		s_dirlist
{
	char			*name;	// Directory name
	t_dir			*head;	// Pointer to head of list containing directory's content
	size_t			total;	// The block size total of the directory
	struct s_dirlist	*next;	// Pointer to the next directory
} 			t_dirlist;
```
  
#### Misc. Links:
[parse permissions to char  *](http://codewiki.wikidot.com/c:system-calls:stat)  
[stat struct](http://pubs.opengroup.org/onlinepubs/009695399/basedefs/sys/stat.h.html)  
[File type checkers](https://www.gnu.org/software/libc/manual/html_node/Testing-File-Type.html)
