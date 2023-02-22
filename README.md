# Imager

![Imager logo](/misc/imager_poster.png)

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
    -cr, --crop                     Crop image (Only PNG)
    -crp, --crop-percent            Crop image with percent (Only PNG)

    -i, --info                      Shows information about image
```

## Examples

### Copy images  

```text
imager image.png --copy copy_image.png
```

```text
imager image.jpg -cp copy_image.jpg
```

```text
imager image.jpeg -cp
```

### Move/rename images

```text
imager image.png -mv path/where/to/move
```

```text
imager image.jpeg --move image_with_new_name.jpeg
```

### Crop images

By width and height

```text
imager image.png -cr 640 380
```

By percent  

```text
imager image.png -crp 50%
```

## Goals

- Read image files :heavy_check_mark:
- Command-line user interface :heavy_check_mark:
- Copy :heavy_check_mark:
- Move/Rename :heavy_check_mark:
- Properties (info) :heavy_check_mark:
- Resize :x:
- Crop  :heavy_check_mark:

## Building  

``` text
git clone https://github.com/C0DIC/Imager.git
cd Imager
make
```

## Uninstall  

``` text
make clean
```
