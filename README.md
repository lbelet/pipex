# Pipex
![C](https://img.shields.io/badge/language-C-blue)
![Pipes](https://img.shields.io/badge/technology-Pipes-red)
![42School](https://img.shields.io/badge/school-42-orange)

## Table of Contents
- [Introduction](#introduction)
- [Important Concepts](#important-concepts)
- [Key Learning Outcomes](#key-learning-outcomes)
- [Objectives](#objectives)
- [Common Instructions](#common-instructions)
- [Project Requirements](#project-requirements)
- [Installation / Compile / Run](#installation--compile--run)
- [Example Usage](#example-usage)
- [Additional Resources](#additional-resources)

## Introduction
The Pipex project aims to reproduce the behavior of the shell pipeline. It involves executing two commands in sequence where the output of the first command is used as the input to the second command, leveraging Unix pipes. This project provides practical experience in process creation, inter-process communication (IPC), and file descriptor manipulation.

## Important Concepts
- 📜 **Pipes**: Pipes are used to pass information from one process to another.
- 🔄 **Process Management**: Creation and management of processes using fork, exec, and wait system calls.
- 📄 **File Descriptors**: Manipulation of file descriptors to redirect input and output streams.
- 🔧 **Redirections**: Handling standard input/output redirections to/from files.

## Key Learning Outcomes
- 🔄 **Process Creation**: Learn how to create and manage processes using fork and exec system calls.
- 🔧 **Pipe Usage**: Understand how to use pipes for inter-process communication.
- 📜 **File Descriptor Management**: Develop skills to manipulate file descriptors for redirections.
- 🧩 **Problem Solving**: Apply theoretical knowledge to practical problems involving IPC and process synchronization.

## Objectives
- 🖥️ **Command Execution**: Execute two commands in sequence with the output of the first command passed as input to the second.
- 📜 **File Redirection**: Implement input redirection from a file and output redirection to a file.
- 🔄 **Pipe Management**: Properly manage pipes and file descriptors to ensure correct data flow between processes.
- 🛠️ **Error Handling**: Gracefully handle errors and edge cases, ensuring proper resource cleanup.

## Common Instructions
- 📜 This project is written in C and adheres to the 42 Norm.
- 🚫 Handles all heap-allocated memory properly to avoid leaks.
- 📄 Provides a Makefile with the rules: `$(NAME)`, `all`, `clean`, `fclean`, and `re`.
- ❌ Global variables are forbidden.
- 🛠️ Programs do not quit unexpectedly and manage errors gracefully.

## Project Requirements
This program should be executed as follows:
```
  ./pipex file1 cmd1 cmd2 file2
```

Where `file1` is the input file, `cmd1` is the first command, `cmd2` is the second command, and `file2` is the output file. The program should:
1. **Open file1**: Redirect its contents to the input of `cmd1`.
2. **Create a Pipe**: Redirect the output of `cmd1` to the input of `cmd2`.
3. **Open file2**: Redirect the output of `cmd2` to `file2`.

## Installation / Compile / Run
1. ⬇️ Clone the repository:
    ```
    git clone https://github.com/yourusername/pipex.git
    cd pipex
    ```
2. 🔧 Compile the project:
    ```
    make
    ```
3. ▶️ Run the program:
    ```
    ./pipex file1 cmd1 cmd2 file2
    ```

## Example Usage
▶️ Example session:
    ```
    ./pipex infile "ls -l" "wc -l" outfile
    ```
This will take the contents of `infile`, pass it through `ls -l`, then pass the output of `ls -l` through `wc -l`, and finally save the result to `outfile`.

## Additional Resources
- [Unix Pipes](https://www.gnu.org/software/libc/manual/html_node/Pipes.html)
- [Process Management](https://man7.org/linux/man-pages/man2/fork.2.html)
- [File Descriptor Manipulation](https://man7.org/linux/man-pages/man2/dup.2.html)
- [Redirections](https://tldp.org/LDP/abs/html/io-redirection.html)
