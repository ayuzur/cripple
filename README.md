# cripple

c ripple

a c program that replicates the ripples caused by rainfall in your terminal

## build

compile the main file. Link the math library if necessary

gcc
`gcc main.c -lm -o cripple`

cl
`cl /Fe:cripple main.c`

## usage

run the executable

It can take the width and height of your terminal as the first two command line 
args

ctrl+c to stop

## future changes

- [x] adding fade out for the ripples using character brightness
- [ ] clean up code
