#!/bin/sh

test -f /sys/class/backlight/nvidia_backlight/brightness || exit 0

VAL=`cat /sys/class/backlight/nvidia_backlight/actual_brightness`
MAX=`cat /sys/class/backlight/nvidia_backlight/max_brightness`
STEP=10

VAL=`expr $VAL + $STEP`

if [ $VAL -gt $MAX ]; then
	VAL=$MAX
fi

echo -n $VAL > /sys/class/backlight/nvidia_backlight/brightness
