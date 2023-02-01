# Pipex
Pipex has been created for the Core curses at 42 Wolfsburg.


The intention is to discover in detail a UNIX mechanism, pipes

## Status:
- Actual status:  on- going.\
- Result :

## Technical considerations:
The  program will be executed as follows:</br>
 ```./pipex file1 cmd1 cmd2 file2```</br>

It must take 4 arguments:</br>
- file1 and file2 are file names.</br>
- cmd1 and cmd2 are shell commands with their parameters.</br>

It must behave exactly the same as the shell command below:</br>
```$> < file1 cmd1 | cmd2 > file2```</br>
```$> ./pipex infile "ls -l" "wc -l" outfile```</br>

Should behave like: </br>
```< infile ls -l | wc -l > outfile```</br>
```$> ./pipex infile "grep a1" "wc -w" outfile```</br>
Should behave like: </br>
```< infile grep a1 | wc -w > outfile```</br>

## Requirements
The project must comply with the following rules:
- Have a Makefile which will compile the source files. It must not relink.
- Have to handle errors thoroughly. In no way the program should quit unexpectedly (segmentation fault, bus error, double free, and so forth).
- The program mustn’t have memory leaks.
- Handle the errors like the shell command:
```< file1 cmd1 | cmd2 > file```

## Theory:
- Pipes -> mechanism that allows processes to communicate with each other. The basic idea behind pipes is that one process can write to the pipe and another process can read from it. This communication occurs through a buffer, where the data written to the pipe is stored until it is read.
 ![image](https://user-images.githubusercontent.com/74324703/216047166-d7324b82-dca4-4daf-87c3-1685f9245174.png)

- fork() -> It creates a child process that is a duplicate of the calling process (the parent process).  </br>
Returns 0 in the child process, and the process ID of the child process in the parent process. This allows the parent process to differentiate between itself and the child process, and to communicate with the child process if necessary.
 </br>
- execve -> is used to execute a new program in place of the current process image. 
This function takes three arguments: the path to the executable file to be executed, 
an array of strings that specify the command-line arguments passed to the program, 
and an array of strings that specify the environment variables for the new process.</br>
```execve(args[0], args, env)```</br>
The execve function replaces the current process image with a new one specified by the path, 
and does not return if successful. If the function fails, it returns -1 and sets the value of errno to indicate the error. </br>

- errno  -> is set to indicate the error when certain functions, such as execve, fail. </br>
Is defined in the errno.h header file  </br>
Is set to a positive non-zero value that corresponds to a specific error code.  </br>
The exact values and meaning of the error codes can vary across different systems, 
but the most common error codes are defined by the POSIX standard and include codes like EACCES (permission denied), 
ENOENT (file or directory not found), and EINVAL (invalid argument). </br>
 </br>
 - waitpid -> is used by a parent process to wait for the termination of one of its child processes. This function blocks the execution of the parent process until the specified child process terminates or a signal is received.</br>
The waitpid function takes three arguments: the process ID of the child process to wait for, a pointer to a status variable that will be filled with the exit status of the child process, and flags that specify the behavior of the function.</br>
```waitpid(pid, &status, 0)```

##
![Generic badge](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

[![ForTheBadge built-with-love](http://ForTheBadge.com/images/badges/built-with-love.svg)](https://GitHub.com/Naereen/)
