#!/bin/bash

# Get a list of all C files in the current directory
c_files=$(find . -name "*.c")

# Loop through each C file and compile it with debugging symbols
for file in $c_files; do
    # Extract the file name without the extension
    file_name=$(basename "$file" .c)
    
    # Compile the C file with debugging symbols
    gcc -g "$file" -o "$file_name"
done

