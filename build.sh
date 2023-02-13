#!/bin/bash

if [ -d "$HOME/.local/bin" ]; then
    PATH="$PATH:$HOME/.local/bin"
fi

gcc functions/*.c utils/*.c image/*.c tests/*.c -o ~/.local/bin/imager