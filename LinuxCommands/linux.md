# Linux

## Shell
- takes input form keyboard and pass it to operating system to execute.

## Terminal 
- lets us interact wtih the shell.
- `ctrl + alt + t` : shortcut for opening termainl.

## Navigating the filesystem
- `@ / ` : its the root directory.
- `@ ../`: its the parents directory.
- `@pwd` : present working directory.
- `@ls` : list all the files and folders in directory.
- `@ls /` : list all the files and folders in home directory.
- `@ls path/` : show content of specified path folder.
- `@ls -l` : gives more details (long format) about files and folders present in folder.
- `@ls -a` : this flag is used to include the hidden files in presented list.
- `@ls -aS` : sort the files by size.
- `@ls Documents/*.cpp` : list only cpp files from Documents directory.
- `@ls -l > files.txt` : create files.txt and add the output of commands to it.
- `@man ls` : gives manual of ls.(help)
- `@cd {path}` : change directory.
- `@cd - ` : change directory to home directory.
- many a times a folder name is seperated by space, in such a situation
  + use backslash before space `@cd My\ Books`
  + use double quotes `@cd "My Books"` for directory name
  + use single quotes `@cd 'My Books'` for directory name


## Cat command
- `@cat {options} {filenames}`
- `cat` : can be used for echoing (repeat whatever you type).
- `cat filename` : display the file contents on terminal. Eg : `cat file1 file2`
- `cat -b list1.txt` : add line number to output and dispay.(skip blank lines)
- `cat -n list1.txt` : add line number including blank line and display.
- `cat > test.txt` : add content you type to file, press `ctrl + d` to exit.(override)
- `cat >> test.txt` : append what u type to file.

## create directory
- `mkdir dir1` : creates directory dir1.
- `mkdir -p dir1/dir2` : create dir1 and dir2.
- `mkdir -p names/{abhas,john,shreya}` : create multiple directory
- `mkdir -p A/B/C/D` : create hierarchy.

## remove directory
- `rmdir {A,B,C,D}` : remove multiple directory
- `rmdir -p A/B/C/D` : remove whole hierarchy.
- `rmdir -pv A/B/C/D` : remove hierarchy and acknowledge user.(v flag)
- rmdir only works if dir are empty.

## remove files and directory
- `rm -r A/B/C/D` : remove all files and folders .(r : recurrsive)

## copy command
- synthax : `cp options source destination`
- Eg : `cp file1.txt file2.txt dir2` : copy file1 n file2 to directory dir2.
- `cp -i file1.txt file2.txt dir1` : i interactive (asks for conformation).
- `cp ../file1.txt ../file2.txt .` : copy file1 n file2 from parent dir to current directory (. means current directory)

