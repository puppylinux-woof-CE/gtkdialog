#!/bin/bash

# This example requires bash.

[ -z $GTKDIALOG ] && GTKDIALOG=gtkdialog

# Gtkdialog is a C program and the C library will execute a system command
# using /bin/sh so we need to make sure that bash executes any commands.
# Ubuntu users whose /bin/sh links to dash should take note of this fact.
USE_BASH=; [ "`readlink /bin/sh`" != bash ] && USE_BASH="bash -c "

# Interference Circles by SFR'2013
# GPLv2 applies
# Req: Gtkdialog >=0.8.0, Bash, rsvg-convert, bc

TEMPDIR=/dev/shm/interference_$$
mkdir $TEMPDIR
trap 'rm -rf $TEMPDIR' EXIT

export PIC=$TEMPDIR/pic.svg
export PIC_IN=$TEMPDIR/pic_in.png
export PIC_TEMP=$TEMPDIR/pic_temp.png
export SINUS=$TEMPDIR/sinus_table
: > $SINUS

echo '<svg width="256" height="256">' > $PIC_TEMP
for i in {1..255..4}; do
  echo '<circle cx="128" cy="128" r="'$i'" fill="none" stroke="black" stroke-width="1" />' >> $PIC_TEMP
done
echo '</svg>' >> $PIC_TEMP
rsvg-convert -f png -w 256 -h 256 $PIC_TEMP > $PIC_IN

# Create sinus table
for i in {0..63}; do
  RAD=`echo "$i*(3.14/32)" | bc -l`
  VAL=`echo "s($RAD) * 32 + 33" | bc -l`
  echo ${VAL/.*} >> $SINUS
done

interference () {
SIN=( $(<$SINUS) )
echo ${SIN[63]} ${SIN[@]:0:63} > $SINUS

echo '<svg width="256" height="256" viewBox="64 64 192 192">
<image x="'${SIN[8]}'" y="'${SIN[16]}'" width="256" height="256" xlink:href="'$PIC_IN'"  />
<image x="'$((${SIN[16]}/2))'" y="'${SIN[32]}'" width="256" height="256" xlink:href="'$PIC_IN'" />
</svg>' > $PIC
}
export -f interference

export MAIN='
<window title="Interference Circles" resizable="false">
    <pixmap>
      <variable>PICTURE</variable>
      <input file>'$PIC'</input>
    </pixmap>
    <timer visible="false" milliseconds="true" interval="75">
      <action>'$USE_BASH'interference</action>
      <action>refresh:PICTURE</action>
    </timer>
<action signal="hide">exit:abort</action>
</window>
'

case $1 in
	-d | --dump) echo "$MAIN" ;;
	*) $GTKDIALOG -cp MAIN ;;
esac
