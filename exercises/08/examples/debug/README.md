The content of this folder was inspired by [this repository](https://github.com/cme212/course/tree/master/notes/lecture-01).

# Debugging

Most of your programming time will be spent figuring out why your
code doesn't work the way you wanted it to work. Learning how
to discover and fix issues in your code, i.e. debug it, will
help you spend less time troubleshooting your projects
and leave you more time to learn about new software design concepts.

## Defensive programming

The most difficult bugs to identify are those that only slightly change
results of your computation, but otherwise let your code run uninterrupted.
These are also the most costly ones. If your code crashes, you will spend
some time fixing it, but other than extra time you spent on your
code, there is no other damage. If, on the other hand, your code produces
incorrect but believable results, the damage could be much more. For example, 
your company may decide to build a prototype of an aircraft component
based on your computation, only to find in (immensely expensive) hardware tests
that the prototype does not meet the specifications.

Defensive programming means that you try to anticipate mistakes that can 
accidentaly get in your code, and structure your code in the way that it fails
to compile or stops execution if that happens. Take a look, for example,
at the code in [`defensive.cpp`](defensive.cpp).

We implemented a simple function that adds two numbers, but
in the process variable `a` is changed, what was not our intention. 
The output of the code is:
```bash
$ ./defensive
2 + 3 = 3
```
By stating our design intention explicitly, using constant data
types, we can have compiler catch our mistake.
```cpp
// This function should assign (a + b) to b.
// a should be marked as "const"!
void
add(const int& a, int& b)
{
  a += b; // Does not compile.
}
```
Trying to compile the modified code will result in the compile error:
```bash
$ g++ -Wall defensive.cpp
defensive.cpp: In function 'void add(const int&, int&)':
defensive.cpp:5:5: error: assignment of read-only reference 'a'
    5 |   a += b;
      |   ~~^~~~
```
The compiler message provides the description of the problem and the line
where the problem occured, as opposed to the previous case, where the code
run happily without giving us any indication about the damage it was doing
in the background.

Unfortunately, not all bugs can be caught at compile time. In those cases
we need to debug our executable.

## Simple debugging techniques

### Print statements

The most basic and widely used debugging methodology involves inserting print
statements (`std::cout`) in your code to determine the state of various things as the
program is running. It is likely that you are already doing this! Here are some
things to keep in mind:

* Make sure to commit your code to version control before embarking on a print
  statement fueled bug hunt. After you find the bug, it is nice to be able to
  revert the code to clean up all of the print statements.
  
* Make sure to commit your code before you make changes in an attempt to fix the
  bug. It can be very difficult to remember what to undo without version
  control. You want to be able to quickly undo a mess created in an attempt to
  fix a bug.

* You can use `__FILE__` and `__LINE__` preprocessor macros to output the filename
  and line number.  For example, the code:
```cpp
std::cout << "__FILE__: " << __FILE__ << std::endl;
std::cout << "__LINE__: " << __LINE__ << std::endl;
```
will output the file name and line number. See [`print.cpp`](print.cpp).

### Debug macro

It is often handy to use a preprocessor macro for debugging statements.  This can
alleviate some of the burden of always writing `std::cout << x << std::endl;`.
Let's look at the simple example in [`debug_macro.hpp`](debug_macro.hpp). This code defines a "macro" called `BUGPRINT`. If the identifier `PRINT_DEBUG`
is defined, the preprocessor will replace each instance of `BUGPRINT(x)` in
the code with the do-loop in the macro; note that we use a do-while loop such that a call to `BUGPRINT` can be executed as part of `if-else` statements and other control flow (see [here](https://stackoverflow.com/a/1067238)). See [`debug_macro.cpp`](debug_macro.cpp).

Under normal compilation, the call to `BUGPRINT` has no effect:

```bash
$ g++ debug_macro.cpp -o debug_macro
$ ./debug_macro
a = 5
b = 6
```

We add a compiler flag `-DPRINT_DEBUG` to define the identifier
`PRINT_DEBUG` and thus enable preprocessor code replacement:

```bash
$ g++ -DPRINT_DEBUG debug_macro.cpp -o debug_macro
$ ./debug_macro
debug_macro.cpp:14: a * b -> 30
a = 5
b = 6
```
In the output we get a lot of useful information!
The operator `#` in the macro is called "stringizing" operator. It will
return string representation of the expression to which it is applied.

**IMPORTANT NOTE** The macro argument `x` does not behave in the same way as an
argument of a function. Remember -- macro is just a text replacement pattern
applied to your code before compilation. If you, for example, have macro
```cpp
#define F(x) x * 2
```
then using it like this
```cpp
c = F(a + b);
```
will result in the following code being compiled:
```cpp
c = a + b * 2;
```
Because of operator precedence in C++, the result will be *a* + 2*b* instead of
2(*a* + *b*). To avoid mistakes like this, the argument of the macro should always
be put within brackets, even when it may appear redundant:
```cpp
#define F(x) (x) * 2
```
This will ensure that the expression `x` is always evaluated first.

**ANOTHER IMPORTANT NOTE**: if you use a macro like `BUGPRINT`, it is important that the
input have no side-effects.  That is, no variables should be changed.  If a call
to `BUGPRINT` caused variables to change, then you would have different behavior
when the macro is enabled and make your bug even harder to find.


### Assert statements

Assert statements are a useful tool to check conditions in code.  It looks like this:

```cpp
assert(condition);
```

If `condition` evaluates to `true`, nothing happens. If `condition` evaluates to
false, the program will terminate and print a (hopefully useful) error message.
Let's look at the example from <https://en.cppreference.com/w/cpp/error/assert>
(see [`assert1.cpp`](assert1.cpp)).

If we compile and run, we see:

```bash
$ g++ assert1.cpp -o assert1
$ ./assert1
Execution continues past the first assert.
assert1: assert1.cpp:9: int main(): Assertion `2 + 2 == 5' failed.
Aborted
```

`assert` is a preprocessor macro. All `assert` statements can be disabled by
defining `NDEBUG`:

```bash
$ g++ -DNDEBUG assert1.cpp -o assert1
$ ./assert1
Execution continues past the first assert.
Execution continues past the second assert.
```

### Assert statements in functions

It is often a good idea to test preconditions for functions using `assert`
statements.  It could go something like this (see [`assert2.cpp`](assert2.cpp)):

```bash
$ g++ assert2.cpp -o assert2
$ ./assert2
4
assert2: assert2.cpp:16: int non_negative_add(int, int): Assertion `y >= 0' failed.
Aborted
```

We can also disable the `assert` statements at compile time:

```bash
$ g++ -DNDEBUG assert2.cpp -o assert2
$ ./assert2
4
-3
```

### Simple pause

It is often very handy to pause a program so a human can read terminal output
before continuing. This may help you debug a loop, for example. This is easy to
do in C++ with `std::cin.get()` (in `<iostream>`). See [`pause.cpp`](pause.cpp).

Usage:

```bash
$ g++ pause.cpp -o pause
$ ./pause
Before pause.
# (user hit enter)
After pause.
iter: 0
# (user hit enter)
iter: 1
# (user hit enter)
iter: 2
# (user hit enter)
iter: 3
# (user hit enter)
iter: 4
# (user hit enter)
```

Be sure to remove all pauses before releasing your code into the wild. It is
often good to provide a prompt:

```cpp
std::cout << "Hit enter to continue." << std::endl;
std::cin.get();
```

## Command line debugger: GDB

Command line debuggers such as GDB and LLDB come without graphical
bells and whistles, but can be as effective when you get some
experience with them. Once you learn how to use a console-based
debugger, it will be fairly straightforward to learn almost any
graphics-based one.

Let's use this simple C++ code in file [`student1.cpp`](student1.cpp)
to introduce GDB basics.

### Compiling code for debugging

In order to enable debugging, we need to compile the code with `-g` flag to
tell compiler to enable debugging symbols in the executable. It is also
highly desirable to turn off optimization with flag `-O0`, so that the debugger
can keep track of what line in the source code is being executed. We can
build our code by
```
g++ -g -O0 student1.cpp -o student1
```
This code produces no output, so to see what is going on inside we need
to use debugger.

### Starting debugger

To start debugger simply enter `gdb` followed by the executable name
on the command line:
```
$ gdb student1
Reading symbols from student1...
(gdb)
```
To run the executable, enter `run` at the debugger command prompt.
```
(gdb) run
Starting program: /.../debug-intro/student1
[Inferior 1 (process 8686) exited normally]
(gdb)
```
This tells us that the code ran without any errors. By the way, most difficult
bugs to find are those when your code produces believable results and
returns no errors. These are situations when you need a debugger the most.

### Setting break points

Running the code in a debugger by itself does not give you much information.
You typically want to pause at certain places in the code and review what
is going on there. You can set up breakpoints (i.e. places for quiet reflection)
in your code by using debugger `break` command. We want to set a breakpoint
inside the constructor of the Student class at line 6:
```
(gdb) break student1.cpp:6
Breakpoint 1 at 0x40145c: file student1.cpp, line 8.
(gdb) 
```
Now, when we run the code, we stop at the break points we set. The first is the
constructor for `student` instance of class `Student`.
```
(gdb) run
Starting program: /.../debug-intro/student1

Breakpoint 1, Student::Student (this=0x7fffffffdd80, name="Alice", id=112233) at student1.cpp:7
7	    this->name = name;
(gdb)
```
A minimal (text-based) graphical interface can help to navigate within
the code being currently run:
```
(gdb) tui enable
(gdb)
```

Now that we stopped the code execution at the place we wanted,
we would like to inspect variable values there.
You can view the variables in the current scope by typing
```
(gdb) print name
$1 = "Alice"
(gdb) print id
$2 = 112233
```
To continue execution of the code simply type `continue` or `c` at the
debugger command prompt. That gets us to the next break point inside
the constructor for the `other` student instance of the class `Student`
(who happens to be Terry Jones).
```
(gdb) continue
Continuing.

Breakpoint 1, Student::Student (this=0x55555556beb0, name="Bob", id=123456) at student1.cpp:7
7	    this->name = name;
(gdb)
```
We can take a look at the variables again.
```
(gdb) print name
$3 = "Bob"
(gdb)
```
At this point in the code execution,
the constructor argument `name` is set to `Bob`,
while `Student` member variable `this->name` has been initialized
to an empty string, but it has not yet been assigned the value
passed to the constructor.

### Navigating through the code

We saw that command `continue` resumes the code execution
and gets us to the next break point. Command `next` will execute
the current and stop at the next line of the code. 
In this situation, the command `step` will do the same.
```
(gdb) next
8          this->id = id;
(gdb) print this->name
$4 = "Bob"
(gdb) step
9        }
(gdb)
```
The difference between commands `next` and `step` is if the next line
of the code is a function the command `next` will call the function and
stop at the next line of the code.
```
(gdb) next
main () at student1.cpp:25
25        delete other_student;
(gdb) next
27  	  return 0;
(gdb) 
```
The command `step`, on the other hand, will step into
the function. You can use command `finish` to get out of
the function and back to the parent scope.
```
(gdb) next
28  	}
(gdb) step
Student::~Student (this=0x7fffffffdd80, __in_chrg=<optimized out>) at student1.cpp:11
11	  ~Student() { id = 0; }
(gdb) finish
Run till exit from #0  Student::~Student (this=0x7fffffffdd80, 
    __in_chrg=<optimized out>) at student1.cpp:11
0x0000555555556536 in main (argc=1, argv=0x7fffffffded8) at student1.cpp:28
28	}
(gdb) 
```
Let us quickly summarize execution commands:

- `run` -- launches the code execution.
- `break filename:NO` -- sets a breakpoint at line NO of `filename`.
- `continue` -- continues code execution from the current position in the code.
- `next` -- executes the current line of the code and moves to the next line.
- `step` -- executes the current line of the code and steps into the function
if the current line is a function call.
- `finish` -- leaves current scope and moves to the next line in the parent scope.


### Backtrace

This is another quite useful debugging command. Sometimes,
you will mess up your pointers and your code will crash
with segmentation fault. One such example is given in
[`student2.cpp`](student2.cpp) file. This code crashes with a segmentation
fault:
```bash
$ ./student2
Segmentation fault:
```
We recompile the code with proper flags
and launch it in the debugger.
```
(gdb) run
Starting program: /.../debug-intro/student2

Program received signal SIGSEGV, Segmentation fault.
0x00007ffff7d4f148 in std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) () from /lib/x86_64-linux-gnu/libstdc++.so.6
(gdb)
```
This is not very helpful, so we use `backtrace`.
```
(gdb) backtrace
#0  0x00007ffff7d4f148 in std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) ()
   from /lib/x86_64-linux-gnu/libstdc++.so.6
#1  0x0000555555556c29 in std::operator+<char, std::char_traits<char>, std::allocator<char> > (
    __lhs=<error reading variable: Cannot access memory at address 0x8>, 
    __rhs=0x555555557042 " ") at /usr/include/c++/11/bits/basic_string.h:6135
#2  0x000055555555694a in Name::get_name[abi:cxx11]() const (this=0x0)
    at student2.cpp:16
#3  0x0000555555556b31 in Student::get_name[abi:cxx11]() const (
    this=0x55555556beb0) at student2.cpp:38
#4  0x000055555555662d in main (argc=1, argv=0x7fffffffded8) at student2.cpp:50(gdb)
```
We get even more mess than before, but here we can recognize some things.
Reading the backtrace output from the bottom up, we first find that the
problem started in function `main` on line 50 in file `student2.cpp`.
We then find that the issue was in the call to `Student::get_name()` on
line 38 and `Name::get_name()` on line 16.
Since we now narrowed down the problem to accessing the student's name,
we have much better chances of finding the actual bug on line 27,
where we accidentally set pointer to `Name` class to `nullptr` value.
