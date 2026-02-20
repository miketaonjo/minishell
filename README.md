# Minishell – Unix Shell Implementation in C

Minishell is a Unix shell implementation written in C as part of the 42 School curriculum.
It reproduces core Bash behaviors including command execution, pipelines, redirections, environment variable expansion, built-in commands, and signal handling.
The project focuses on process management, file descriptor manipulation, parsing logic, and system-level programming concepts.

Overview

- Language: C
- Architecture: Modular parsing and execution pipeline
- Process Handling: fork, execve, wait
- Inter-process Communication: pipes
- File Descriptor Management: dup2, redirections
- Environment Handling: variable expansion and export management
- Signal Handling: ctrl-c, ctrl-d, ctrl-\
- Focus: Low-level Unix systems programming

## Supported features

- Prompt display<br>
- Command history (up and down arrows)<br>
- System executables available from the environment (<code>ls</code>, <code>cat</code>, <code>grep</code>, etc.)<br>
- Local executables (<code>./minishell</code>)<br>
- Builtin commands :<br>
<code>echo</code> (and option <code>-n</code>)<br>
<code>cd</code> (with only a relative or absolute path)<br>
<code>pwd</code>(no options)<br>
<code>export </code>(no options)<br>
<code>unset</code> (no options)<br>
<code>env</code> (no options or arguments)<br>
<code>exit</code> (with exit number but no other options)<br>
- Pipes <code>|</code> which redirect output from one command to input for the next<br>
- Redirections:<br>
<code>></code>redirects output<br>
<code>>></code> redirects output in append mode<br>
<code><</code> redirects input<br>
<code><< DELIMITER</code> displays a new prompt, reads user input until reaching <code>DELIMITER</code>, redirects user input to command input (does not update history)<br>
- Environment variables (i.e. <code>$USER</code> or <code>$VAR</code>) that expand to their values.<br>
<code>$?</code> expands to the exit status of the most recently executed foreground pipeline.<br>
- User keyboard signals:<br>
<code>ctrl-c</code> displays a new prompt line.<br>
<code>ctrl-d</code> exits minishell<br>
<code>ctrl-\/</code> does nothing<br>

However, Minishell does not support <code>\/</code>, <code>;</code>, <code>&&</code>, <code>||</code>, or wildcards.


## Installation
```bash
git clone <repository_url>
cd minishell
make
```

## Usage
```bash
./minishell (anything from listed above)
```

## Exemple
```bash
./minishell cat Makefile | grep o > out
```
