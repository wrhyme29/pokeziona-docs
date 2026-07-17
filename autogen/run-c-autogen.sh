#!/bin/env bash

APP_NAME=pokedata-autogen
OUTPUT_DIR=output
RECORDED_OUTPUT_FILE=pokemon.json

mkdir -p ${OUTPUT_DIR}

cc -o  ${OUTPUT_DIR}/${APP_NAME} src/autogen.c

if [ $? -ne 0 ]; then 
    exit $? 
fi

if [ ${AUTORUN} ]; then
    if [ ${REDIRECT_OUTPUT} ]; then
        ./${OUTPUT_DIR}/${APP_NAME} > ${OUTPUT_DIR}/${RECORDED_OUTPUT_FILE}
    else
        ./${OUTPUT_DIR}/${APP_NAME}
    fi
fi