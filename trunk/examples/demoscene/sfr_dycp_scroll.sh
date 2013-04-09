#!/bin/bash

# This example requires bash.

[ -z $GTKDIALOG ] && GTKDIALOG=gtkdialog

# Gtkdialog is a C program and the C library will execute a system command
# using /bin/sh so we need to make sure that bash executes any commands.
# Ubuntu users whose /bin/sh links to dash should take note of this fact.
USE_BASH=; [ "`readlink /bin/sh`" != bash ] && USE_BASH="bash -c "

# DYCP Scroll by SFR'2013
# GPLv2 applies

export TEXT="             Hey! This is probably the very first DYCP-Scroller for Puppy Linux. ;) Greetings!"

TEMPDIR=/dev/shm/dycp_scroll_$$
mkdir $TEMPDIR
trap 'rm -rf $TEMPDIR' EXIT

export PIC=$TEMPDIR/pic.svg
export SINUS=$TEMPDIR/sinus_table
export X_POS=$TEMPDIR/dycp_x
export TEXT_POS=$TEMPDIR/text_position
echo 0 > $X_POS
echo 0 > $TEXT_POS

# Create sinus table
for i in {0..63}; do
  RAD=`echo "$i*(3.14/32)" | bc -l`
  VAL=`echo "s($RAD) * 48 + 72" | bc -l`
  echo ${VAL/.*} >> $SINUS
done

dycp () {
SIN=( `cat $SINUS` )
read X < $X_POS
read POS < $TEXT_POS
echo '<svg width="256" height="128" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink">
<text font-family="Monospace" font-size="32" font-weight="bold">
<tspan x="'$((10-$X))'" y="'${SIN[0]}'">'${TEXT:$POS:1}'</tspan>
<tspan x="'$((30-$X))'" y="'${SIN[2]}'">'${TEXT:$(($POS+1)):1}'</tspan>
<tspan x="'$((50-$X))'" y="'${SIN[4]}'">'${TEXT:$(($POS+2)):1}'</tspan>
<tspan x="'$((70-$X))'" y="'${SIN[6]}'">'${TEXT:$(($POS+3)):1}'</tspan>
<tspan x="'$((90-$X))'" y="'${SIN[8]}'">'${TEXT:$(($POS+4)):1}'</tspan>
<tspan x="'$((110-$X))'" y="'${SIN[10]}'">'${TEXT:$(($POS+5)):1}'</tspan>
<tspan x="'$((130-$X))'" y="'${SIN[12]}'">'${TEXT:$(($POS+6)):1}'</tspan>
<tspan x="'$((150-$X))'" y="'${SIN[14]}'">'${TEXT:$(($POS+7)):1}'</tspan>
<tspan x="'$((170-$X))'" y="'${SIN[16]}'">'${TEXT:$(($POS+8)):1}'</tspan>
<tspan x="'$((190-$X))'" y="'${SIN[18]}'">'${TEXT:$(($POS+9)):1}'</tspan>
<tspan x="'$((210-$X))'" y="'${SIN[20]}'">'${TEXT:$(($POS+10)):1}'</tspan>
<tspan x="'$((230-$X))'" y="'${SIN[22]}'">'${TEXT:$(($POS+11)):1}'</tspan>
<tspan x="'$((250-$X))'" y="'${SIN[24]}'">'${TEXT:$(($POS+12)):1}'</tspan>
</text>
</svg>' > $PIC


X=$(($X+2))
if [ $X = 20 ]; then
  X=0
  POS=$(($POS+1)); [ $POS -gt ${#TEXT} ] && POS=0
  echo ${SIN[@]:1:63} ${SIN[0]} > $SINUS
else
  echo ${SIN[63]} ${SIN[@]:0:63} > $SINUS
fi
echo $X > $X_POS
echo $POS > $TEXT_POS
}
export -f dycp && dycp

export MAIN='
<window title="DYCP Scroller" resizable="false">
  <vbox>
    <pixmap>
      <variable>PICTURE</variable>
      <input file>'$PIC'</input>
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
