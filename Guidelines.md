# Guidelines
My personal C coding guidelines for maintaining consistency.
Code style gude is build on top of the norminette style rules.

## Project

### Project structure
```
build/					- Temporary build files
	obj/				- Object files
lib/					- Libraries
	%library_name%/
include/%project_name%/			- Public header files
include-internal/%project_name%/	- Private (internal) header files
src/					- Source files
Makefile				- A Makefile
%project_name%.a			- Linked static library
%project_name%				- Linked executable
```

## Code style

### Include ordering
```
<Definition includes>

<System includes>

<Library includes>

<Project includes>
```

### Naming convention
1.	Defines, compile-time constants, enum members: `UPPER_CASE`  
	Everything else: `snake_case`  

2.	External functions:  
	`[namespace_][subject_]function`  
	Internal functions:  
	`_[namespace_][subject_]function`  
	Static functions:  
	`_[subject_]function`  

	Where:  
	`[something]` means that `something` is optional.  
	A subject is the value type the function operates on, like `list_add` or `mutex_lock`.  

4.	The function name sould be a verb, for example:

	❌Wrong            | ✔️Right
	--------           | --------
	`initialization()` | `initialize()`
	`new_something()`  | `create_something()`

5.	Struct constructors:  
	```c
	// Create struct instance
	t_struct struct_create(...);
	// Allocate struct instance
	t_struct *struct_alloc(...);
	// Initialize existing struct instance
	void struct_init(t_struct *instance, ...);
	```

6.	Struct destructors:
	```c
	// Deinitialize (free, etc.) struct members, but not the struct itself
	void struct_destroy(t_struct *instance);
	// Deinitialize struct members and the struct itself
	void *struct_free(t_struct *instance);
	```

6.	Functions in header files should be formatted as follows:
	```c
	void
	do_something(int a, int b);

	char
	*do_something_else(int a, char *b);
	```
	As this works well with the norm and generally looks nice.

### Structures & pointers
Passing structures to functions should generally be done by pointers, as this
requires significantly less stack space and helps avoiding errors.

### Mallocs & error handling
It's recommended to avoid mallocs so the code will require less error handling. When working with structs use `create` or `init` instead of `alloc` when possible.

In a library project, all possible malloc errors should be properly handled so the function won't quit unexpectedly. In an excutable, however, it's recommended to exit the program immediately.
