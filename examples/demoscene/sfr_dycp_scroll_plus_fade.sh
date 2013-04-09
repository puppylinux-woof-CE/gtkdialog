#!/bin/bash

# This example requires bash.

[ -z $GTKDIALOG ] && GTKDIALOG=gtkdialog

# Gtkdialog is a C program and the C library will execute a system command
# using /bin/sh so we need to make sure that bash executes any commands.
# Ubuntu users whose /bin/sh links to dash should take note of this fact.
USE_BASH=; [ "`readlink /bin/sh`" != bash ] && USE_BASH="bash -c "

# DYCP Scroll + opacity by SFR'2013
# GPLv2 applies

export TEXT="                     DYCP-Scroller + kinda 'fade' effect (using 'opacity'). Greetings!"

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
  SIN[$i]=$(printf "%.0f" $(echo "s($RAD)*48+72" | bc -l))
done
echo ${SIN[@]} > $SINUS

dycp () {
SIN=( $(<$SINUS) )
read X < $X_POS
read POS < $TEXT_POS
echo '<svg width="384" height="128">
<text font-family="Monospace" font-size="32" font-weight="bold">
<tspan x="'$((0-$X))'" y="'${SIN[0]}'" opacity="'0.$((${SIN[32]}/2))'">'${TEXT:$POS:1}'</tspan>
<tspan x="'$((20-$X))'" y="'${SIN[2]}'" opacity="'0.$((${SIN[34]}/2))'">'${TEXT:$(($POS+1)):1}'</tspan>
<tspan x="'$((40-$X))'" y="'${SIN[4]}'" opacity="'0.$((${SIN[36]}/2))'">'${TEXT:$(($POS+2)):1}'</tspan>
<tspan x="'$((60-$X))'" y="'${SIN[6]}'" opacity="'0.$((${SIN[38]}/2))'">'${TEXT:$(($POS+3)):1}'</tspan>
<tspan x="'$((80-$X))'" y="'${SIN[8]}'" opacity="'0.$((${SIN[40]}/2))'">'${TEXT:$(($POS+4)):1}'</tspan>
<tspan x="'$((100-$X))'" y="'${SIN[10]}'" opacity="'0.$((${SIN[42]}/2))'">'${TEXT:$(($POS+5)):1}'</tspan>
<tspan x="'$((120-$X))'" y="'${SIN[12]}'" opacity="'0.$((${SIN[44]}/2))'">'${TEXT:$(($POS+6)):1}'</tspan>
<tspan x="'$((140-$X))'" y="'${SIN[14]}'" opacity="'0.$((${SIN[46]}/2))'">'${TEXT:$(($POS+7)):1}'</tspan>
<tspan x="'$((160-$X))'" y="'${SIN[16]}'"  opacity="'0.$((${SIN[48]}/2))'">'${TEXT:$(($POS+8)):1}'</tspan>
<tspan x="'$((180-$X))'" y="'${SIN[18]}'" opacity="'0.$((${SIN[50]}/2))'">'${TEXT:$(($POS+9)):1}'</tspan>
<tspan x="'$((200-$X))'" y="'${SIN[20]}'" opacity="'0.$((${SIN[52]}/2))'">'${TEXT:$(($POS+10)):1}'</tspan>
<tspan x="'$((220-$X))'" y="'${SIN[22]}'" opacity="'0.$((${SIN[54]}/2))'">'${TEXT:$(($POS+11)):1}'</tspan>
<tspan x="'$((240-$X))'" y="'${SIN[24]}'" opacity="'0.$((${SIN[56]}/2))'">'${TEXT:$(($POS+12)):1}'</tspan>
<tspan x="'$((260-$X))'" y="'${SIN[26]}'" opacity="'0.$((${SIN[58]}/2))'">'${TEXT:$(($POS+13)):1}'</tspan>
<tspan x="'$((280-$X))'" y="'${SIN[28]}'" opacity="'0.$((${SIN[60]}/2))'">'${TEXT:$(($POS+14)):1}'</tspan>
<tspan x="'$((300-$X))'" y="'${SIN[30]}'" opacity="'0.$((${SIN[62]}/2))'">'${TEXT:$(($POS+15)):1}'</tspan>
<tspan x="'$((320-$X))'" y="'${SIN[32]}'" opacity="'0.$((${SIN[0]}/2))'">'${TEXT:$(($POS+16)):1}'</tspan>
<tspan x="'$((340-$X))'" y="'${SIN[34]}'" opacity="'0.$((${SIN[2]}/2))'">'${TEXT:$(($POS+17)):1}'</tspan>
<tspan x="'$((360-$X))'" y="'${SIN[36]}'" opacity="'0.$((${SIN[4]}/2))'">'${TEXT:$(($POS+18)):1}'</tspan>
<tspan x="'$((380-$X))'" y="'${SIN[38]}'" opacity="'0.$((${SIN[6]}/2))'">'${TEXT:$(($POS+19)):1}'</tspan>
</text>
</svg>' > $PIC


X=$(($X+2))
if [ $X = 20 ]; then
  X=0
  POS=$(($POS+1)); [ $POS -gt ${#TEXT} ] && POS=0
  echo ${SIN[@]:1:63} ${SIN[0]} > $SINUS
  echo $POS > $TEXT_POS
else
  echo ${SIN[63]} ${SIN[@]:0:63} > $SINUS
fi
echo $X > $X_POS
}
export -f dycp && dycp

export MAIN='
<window title="DYCP Scroller + Fade" resizable="false">
    <pixmap>
      <variable>PICTURE</variable>
      <input file>'$PIC'</input>
    </pixmap>
    <timer visible="false" milliseconds="true" interval="50">
      <action>'$USE_BASH'dycp</action>
      <action>refresh:PICTURE</action>
    </timer>
<action signal="hide">exit:abort</action>
</window>
'

case $1 in
	-d | --dump) echo "$MAIN" ;;
	*) $GTKDIALOG -cp MAIN ;;
esac
