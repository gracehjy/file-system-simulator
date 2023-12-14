--TEST CASES (ALL RUN AS EXPECTED)--

1. `q` to quit

        Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
        $  q
        
        Process finished with exit code 139 (interrupted by signal 11: SIGSEGV)

2. `help` to display list of commands

        $  help
        Commands: 
        cat
        cp
        ds
        ls
        rm
        rn
        touch
        touchcat

3. `help [command]` to display info about a command. ex. for cat:

        $  help cat
        cat is a utility that is useful for concatenating files; it can also be used to write to a file.
        cat can be invoked with the command: cat <filename> [-a]
        -a will display the current contents of the file and append new content to it.

4. `ls`

        $  ls



