# Imager

Simple and fast command-line image manipulator written in C

## Usage

``` text
imager filename [options]

Argument:
    Your image file          (PNG, JPEG/JPG (JFIF) supported)

Options:
    --help                  Shows help message

    --copy                  Copy image
    --move                  Move image
    --info                  Shows information about image
```

## Examples

Only name (will save in the same directory, where program used):  
`./imager image.jpg --copy copy_image.jpg`

Relative path:  
`./imager image.jpg --copy ~/copy_image.jpg`

Full path to the file:  
`./imager image.jpg --copy /home/username/copy_image.jpg`

## Compiling

``` text
gcc functions/*.c utils/*.c image/*.c tests/*.c -o imager
```
