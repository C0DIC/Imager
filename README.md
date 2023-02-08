# Imager

Simple and fast command-line image manipulator written in C

## Usage

Usage: [filename] [option]

Filename: image-file name (with extension) or full (or relative) path to file

Options:

- --copy
- --move
- in progress...

## Examples

Only name (will save in the same directory, where program used):  
`./imager image.jpg --copy copy_image.jpg`

Relative path:  
`./imager image.jpg --copy ~/copy_image.jpg`

Full path to the file:  
`./imager image.jpg --copy /home/username/copy_image.jpg`

## Compiling

`gcc image/image.c functions/copy.c functions/terminal.c functions/move.c functions/interpreter.c utils/is_image.c tests/test.c -o imager`
