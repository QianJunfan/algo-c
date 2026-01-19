#!/bin/bash

read -p "Problem ID: " pid
read -p "Problem Name: " pname

filename="${pid}.c"
curr_date=$(date +"%b %d, %Y")

cat <<EOF >"$filename"
/* leetcode $pid - $pname
 * $curr_date
 */
EOF

echo "File created: $filename"
