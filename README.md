# Minishell
Tech1: Shell Project, Minishell

Promo 2023, Tech 1.

Credit: Axel Virot.

Copyright Law Section 107 (U.S. Copyright Act, 1976) provides that fair use of a copyrighted work, including such use by reproduction in copies or phonorecords or by any other means for purposes such as criticism, comment, news perortiong, teaching (including multiple copies for classroom use), scholarship, or , is not an infringement of copyright.

Minishell Project:

You have to program a UNIX command interpreter.
The interpreter is expected to display a prompt ( $> , for example) and then wait for you to write a command
line, which must be validated by a newline.
The prompt must be displayed again only after the command execution.
Only basic command lines are expected to executed; no pipes, redirections or any other advanced features.
The executables should be those found in the path, as indicated in the PATH variable.
If the executable cannot be found, you must display an error message and display the prompt again.
Errors must be dealt with and must display the appropriate message on the error output.
You must correctly handle the PATH and the environment (by copying and restoring the initial env).
You must implement the following builtins: cd, setenv, unsetenv, env, exit.
