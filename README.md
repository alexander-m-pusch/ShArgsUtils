# ShArgsUtils
Shell Argument Utilities 



This program makes it easy to get if arguments, and if yes, what associated value was passed to a program from the shell. 

### Example,

```shell
testprogram --someflag --someotherflag --mode somemode --anotheroption anothervalue --andanotherflag
```

would show you that the flags --someflag, --someotherflag, and --andanotherflag were set, as well as that --mode is set to somemode and --anotheroption is set to anothervalue. All of the arguments may be passed in random order, the program will work regardless.

The only downside is that none of the "mode" type key-value pairs may have values that overlap with flags or mode setters.

## Using ShArgsUtils

Include the header in include/ in your project and add libshargsutils.a to you linker's path, that should do the trick.
