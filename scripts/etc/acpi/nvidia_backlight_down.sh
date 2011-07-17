#!/bin/sh

test -f /sys/class/backlight/nvidia_backlight/brightness || exit 0

VAL=`cat /sys/class/backlight/nvidia_backlight/actual_brightness`
MIN=0
STEP=10

VAL=`expr $VAL - $STEP`

if [ $VAL -lt $MIN ]; then
	VAL=$MIN
fi

echo -n $VAL > /sys/class/backlight/nvidia_backlight/brightness
