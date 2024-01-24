#!/bin/sh

# set this
week="week1"
day="fri"
source_file_name="example.txt"

temp_name="temp.txt"
autograder_file_name="autograder.txt"

##############################
### CREATE ARRAY OF NETIDS ###
##############################

if [ "$USER" = "g73x59" ] ; then
    dir_path="/home" # place where student directories are
    dir_array=($(ls $dir_path | awk '{if ( -d $1 ) print $1}'))
else
    dir_array=($USER)
fi

#############
### TESTS ###
#############

# if grading all, we need the header for D2L
if [ "$USER" = "g73x59" ] ; then
    echo "Username, $d2l_assignment Points Grade <Numeric MaxPoints:5 Weight:4.34782609 Category:Weekly work CategoryWeight:10>,End-of-Line Indicator"
fi
for netid in "${dir_array[@]}"; do
    directory="/home/$netid/csci112_spring2024/classwork/$week/$day"
    source_file="$directory/$source_file_name"
    temp="$directory/$temp_name"
# because we append to autograder, clear it first
    autograder_file="$directory/$autograder_file_name"
    rm $autograder_file 2> $temp


# if grading all, print name for D2L
  if [ "$USER" = "g73x59" ] ; then
    echo -n "#"
    name=$(finger $netid | awk 'NR==1{print $4}' 2>/dev/null)
    echo -n $name
  fi

    
# source file exists: 10 points
    echo "TEST 1: Source file exists" >> $autograder_file
    if [ -f $source_file ]; then
       echo -e "PASS\n"  >> $autograder_file
       if [ "$USER" = "g73x59" ] ; then
           echo ",10,#"
       fi
       echo "full credit" >> $autograder_file
    else
       echo -e "FAIL\n" >> $autograder_file
       if [ "$USER" = "g73x59" ] ; then
          echo ",0,#"
       fi
       echo "There is at least one mistake" >> $autograder_file
    fi
    echo "Last updated on:" >> $autograder_file
    date >> $autograder_file


# cleanup
    rm $temp

done
