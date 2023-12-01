#!/bin/bash

# Set the Internal Field Separator (IFS) to newline
IFS=$'\n'

# Initialize a counter variable 'c'
c=1

# Read lines from input.txt and process them
while IFS= read -r line
do
    # Check if the line number is even
    if ((c % 2 == 0))
    then
        # Append the even lines to output.txt
        echo "Processing line: $line"
        echo "$line" >> output.txt
    fi
    # Increment the counter
    ((c++))
done < abcd.txt
