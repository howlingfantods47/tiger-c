#!/bin/bash

for filename in ../testcases/*.tig; do
    echo $filename
    ./a.out $filename > "$filename".absyn
done
