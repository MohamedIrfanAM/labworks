#!/bin/bash
# for i in "$@"; do
#     echo "$i"
# done | tac


for (( i=$#;i>0;i-- ));do
        echo "${!i}"
done