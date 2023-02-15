# Imager

Simple and fast command-line image manipulator written in C

## Usage

``` text
imager filename [options]

Argument:
    Your image file                 (PNG, JPEG/JPG (JFIF) supported)

Options:
    -?, -h, --help                  Shows help message

    -cp, --copy                     Copy image
    -mv, --move                     Move image
    -i, --info                      Shows information about image
```

## Examples

Only name (will save in the same directory, where program used):  
`imager image.jpg --copy copy_image.jpg`

Relative path:  
`imager image.jpg -cp ~/copy_image.jpg`

Full path to the file:  
`imager image.jpg --copy /home/username/copy_image.jpg`

## Building  

``` text
git clone https://github.com/C0DIC/Imager.git
cd Imager
chmod +x build.sh
./build.sh
```

## Uninstall  

``` text
chmox +x uninstall.sh
./uninstall.sh
```
