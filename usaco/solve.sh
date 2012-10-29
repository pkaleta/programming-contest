#!/usr/bin/env bash


if [ $# -eq 2 ]; then
    USACO_DIR="/home/insane/algo/usaco"
    SECTION_NAME="Section ${1}"
    SECTION_DIR="${USACO_DIR}/${SECTION_NAME}"
    TASK_DIR="${SECTION_DIR}/${2}"
    FILE_NAME="${TASK_DIR}/${2}.cpp"
    EMPTY_FILE="${USACO_DIR}/empty.cpp"
    CONTENT=`cat "$EMPTY_FILE"`

    if [ ! -d "$SECTION_DIR" ]; then
        mkdir "$SECTION_DIR";
    fi
    if [ ! -d "$TASK_DIR" ]; then
        mkdir "$TASK_DIR";
    fi
    if [ ! -e "$FILE_NAME" ]; then
        printf "$CONTENT" $2 $2 $2 > "$FILE_NAME"
    fi
    gvim "$FILE_NAME"
else
    echo "Usage: $0 SECTION_NUMBER TASK_NAME";
    exit 1;
fi

