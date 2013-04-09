#!/bin/bash

# This example requires bash.

[ -z $GTKDIALOG ] && GTKDIALOG=gtkdialog

# Gtkdialog is a C program and the C library will execute a system command
# using /bin/sh so we need to make sure that bash executes any commands.
# Ubuntu users whose /bin/sh links to dash should take note of this fact.
USE_BASH=; [ "`readlink /bin/sh`" != bash ] && USE_BASH="bash -c "

# DYCP 2 by SFR'2013
# Uses Vovchik's tip: markup "rise" attribute instead of svg
# GPL v2 applies

TEMPDIR=/dev/shm/dycp_$$
mkdir $TEMPDIR
trap 'rm -rf $TEMPDIR' EXIT

export SINUS=$TEMPDIR/sinus_table

# Create sinus table
for i in {0..63}; do
  RAD=`echo "$i*(3.14/64)" | bc -l`
  SIN[$i]=$(printf "%.0f" $(echo "((s($RAD)*100)+10)*1024" | bc -l))
done
echo ${SIN[@]} > $SINUS

# -----------------------------------------------------------------------------

dycp () {
TEXT="DYCP using 'rise' attribute."
SIN=( $(<$SINUS) )

echo -n '<span font="Monospace bold 36" color="black">'
for i in `seq 0 $((${#TEXT}-1))`; do
echo -n '<span rise="'${SIN[$(( ($i*3)&63 ))]}'">'${TEXT:$i:1}'</span>'
done
echo -n '</span>'

echo ${SIN[63]} ${SIN[@]:0:63} > $SINUS
}
export -f dycp

export MAIN='
<window title="DYCP 2" height-request="256" resizable="false">
  <text use-markup="true" wrap="false">
    <variable>DYCP</variable>
    <input>'$USE_BASH'dycp</input>
  </text>
  <timer visible="false" milliseconds="true" interval="50">
    <action>refresh:DYCP</action>
  </timer>
<action signal="hide">exit:abort</action>
</window>
'

case $1 in
	-d | --dump) echo "$MAIN" ;;
	*) $GTKDIALOG -cp MAIN ;;
esac
