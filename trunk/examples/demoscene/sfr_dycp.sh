#!/bin/bash

# This example requires bash.

[ -z $GTKDIALOG ] && GTKDIALOG=gtkdialog

# Gtkdialog is a C program and the C library will execute a system command
# using /bin/sh so we need to make sure that bash executes any commands.
# Ubuntu users whose /bin/sh links to dash should take note of this fact.
USE_BASH=; [ "`readlink /bin/sh`" != bash ] && USE_BASH="bash -c "

# DYCP example by SFR'2013
# GPLv2 applies

export SINUS=/dev/shm/sinus_table
[ -e $SINUS ] && rm $SINUS

# Create sinus table
for i in {0..63}; do
  RAD=`echo "$i*(3.14/32)" | bc -l`
  VAL=`echo "s($RAD) * 48 + 72" | bc -l`
  echo ${VAL/.*} >> $SINUS
done

dycp () {
SIN=( `cat $SINUS` )
echo '<svg width="256" height="128" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink">
<text font-family="Monospace" font-size="32" font-weight="bold">
<tspan x="10" y="'${SIN[0]}'">P</tspan>
<tspan x="30" y="'${SIN[2]}'">U</tspan>
<tspan x="50" y="'${SIN[4]}'">P</tspan>
<tspan x="70" y="'${SIN[6]}'">P</tspan>
<tspan x="90" y="'${SIN[8]}'">Y</tspan>
<tspan x="130" y="'${SIN[12]}'">L</tspan>
<tspan x="150" y="'${SIN[14]}'">I</tspan>
<tspan x="170" y="'${SIN[16]}'">N</tspan>
<tspan x="190" y="'${SIN[18]}'">U</tspan>
<tspan x="210" y="'${SIN[20]}'">X</tspan>
<tspan x="230" y="'${SIN[22]}'">!</tspan>
</text>
</svg>' > /dev/shm/dycp_pic.svg

# Shift array right
echo ${SIN[63]} ${SIN[@]:0:63} > $SINUS
}
export -f dycp && dycp

export MAIN='
<window title="DYCP" resizable="false">
  <vbox>
    <pixmap>
      <variable>PICTURE</variable>
      <input file>/dev/shm/dycp_pic.svg</input>
    </pixmap>
    <button ok></button>
    <timer visible="false" milliseconds="true" interval="50">
      <action>'$USE_BASH'dycp</action>
      <action>refresh:PICTURE</action>
    </timer>
  </vbox>
</window>
'

case $1 in
	-d | --dump) echo "$MAIN" ;;
	*) $GTKDIALOG -cp MAIN ;;
esac
