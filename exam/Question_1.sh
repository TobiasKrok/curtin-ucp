#!/bin/bash  
logfile=logfile.txt;
# Simple check to make sure the logfile exists, exits if not
if [ ! -f "$logfile" ]; then

    echo "Couldn't find file named $logfile";
    exit;
fi

# First we get all the lines matching the regex pattern and then we use awk to compare the timestamps

# Regex pa
grep -E '.*(User '.*' logged in)' $logfile | awk '$2 >= "18:00:00" && $2 <= "23:59:59"' 
