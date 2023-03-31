# Project name : minishell

For this project, the assignment is : 

This project is about creating a simple shell. Yes, your own little bash. You will learn a lot about processes and file descriptors.

It is a team project where you will create a basic shell program in C. It implements redirections and pipes, as well as environment variable expansions and the cd, echo, env, exit, export, pwd and unset builtin commands.

Minishell is a miniature shell program based on Bash. Minishell supports:

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
- Environment variables (i.e. <code>$USER or <code>$VAR) that expand to their values.<br>
<code>$?</code> expands to the exit status of the most recently executed foreground pipeline.<br>
- User keyboard signals:<br>
<code>ctrl-c</code> displays a new prompt line.<br>
<code>ctrl-d</code> exits minishell<br>
<code>ctrl-\</code> does nothing<br>
However, Minishell does not support \, ;, &&, ||, or wildcards.

## Usage

In order to compile :
<code>make</code>

Execution :
<code>./minishell (anything from listed above)</code>

Exemple = 
<code>./minishell cat Makefile | grep o > out</code>
