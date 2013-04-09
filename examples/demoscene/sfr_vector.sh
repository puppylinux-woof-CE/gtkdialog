#!/bin/bash

# This example requires bash.

[ -z $GTKDIALOG ] && GTKDIALOG=gtkdialog

# Gtkdialog is a C program and the C library will execute a system command
# using /bin/sh so we need to make sure that bash executes any commands.
# Ubuntu users whose /bin/sh links to dash should take note of this fact.
USE_BASH=; [ "`readlink /bin/sh`" != bash ] && USE_BASH="bash -c "

# Line-Vector (+ pseudo Glenz effect) by SFR'2013
# GPLv2 applies
# Req: Gtkdialog >=0.8.0, Bash, bc

export TEMPDIR=/dev/shm/vector_$$
mkdir $TEMPDIR
trap 'rm -rf $TEMPDIR' EXIT

export SINUS=$TEMPDIR/sinus_table
export COSINUS=$TEMPDIR/cosinus_table
export SWITCH=$TEMPDIR/switch
echo 0 > $SWITCH

# Create (co)sinus tables
for i in {0..359}; do
  RAD=`echo "$i*0.0174" | bc -l`	#0.0174 = (3.14/180)
  SIN[$i]=$(printf "%.0f" $(echo "s($RAD)*1000" | bc -l))
  #COS[$i]=$(printf "%.0f" $(echo "c($RAD)*1000" | bc -l))
done
echo ${SIN[@]} > $SINUS
#echo ${COS[@]} > $COSINUS
echo ${SIN[@]:270:90} ${SIN[@]:0:270} > $COSINUS	# <faster than calculating Cosinus on its own

export PIC=$TEMPDIR/pic.svg

export X1=-64; export Y1=-64; export Z1=-64
export X2=-64; export Y2=64; export Z2=-64
export X3=64; export Y3=-64; export Z3=-64
export X4=64; export Y4=64; export Z4=-64
export X5=-64; export Y5=-64; export Z5=64
export X6=-64; export Y6=64; export Z6=64
export X7=64; export Y7=-64; export Z7=64
export X8=64; export Y8=64; export Z8=64

export D=512

echo 0 > $TEMPDIR/xangle
echo 0 > $TEMPDIR/yangle
echo 0 > $TEMPDIR/zangle

# MAIN FUNCTION
vector () {
SIN=( $(<$SINUS) )
COS=( $(<$COSINUS) )

XANGLE=$(<$TEMPDIR/xangle); XANGLE=$(($XANGLE+4)); [ $XANGLE -ge 360 ] && XANGLE=0; echo $XANGLE > $TEMPDIR/xangle
YANGLE=$(<$TEMPDIR/yangle); YANGLE=$(($YANGLE+3)); [ $YANGLE -ge 360 ] && YANGLE=0; echo $YANGLE > $TEMPDIR/yangle
ZANGLE=$(<$TEMPDIR/zangle); ZANGLE=$(($ZANGLE+1)); [ $ZANGLE -ge 360 ] && ZANGLE=0; echo $ZANGLE > $TEMPDIR/zangle

# ROTATE X
NX1=$X1; NX2=$X2; NX3=$X3; NX4=$X4; NX5=$X5; NX6=$X6; NX7=$X7; NX8=$X8

NY1=$(( ((${COS[$XANGLE]} *$Y1) - (${SIN[$XANGLE]} * $Z1)) /1000 ))
NY2=$(( ((${COS[$XANGLE]} *$Y2) - (${SIN[$XANGLE]} * $Z2)) /1000 ))
NY3=$(( ((${COS[$XANGLE]} *$Y3) - (${SIN[$XANGLE]} * $Z3)) /1000 ))
NY4=$(( ((${COS[$XANGLE]} *$Y4) - (${SIN[$XANGLE]} * $Z4)) /1000 ))
NY5=$(( ((${COS[$XANGLE]} *$Y5) - (${SIN[$XANGLE]} * $Z5)) /1000 ))
NY6=$(( ((${COS[$XANGLE]} *$Y6) - (${SIN[$XANGLE]} * $Z6)) /1000 ))
NY7=$(( ((${COS[$XANGLE]} *$Y7) - (${SIN[$XANGLE]} * $Z7)) /1000 ))
NY8=$(( ((${COS[$XANGLE]} *$Y8) - (${SIN[$XANGLE]} * $Z8)) /1000 ))

NZ1=$(( ((${SIN[$XANGLE]} *$Y1) + (${COS[$XANGLE]} * $Z1)) /1000 ))
NZ2=$(( ((${SIN[$XANGLE]} *$Y2) + (${COS[$XANGLE]} * $Z2)) /1000 ))
NZ3=$(( ((${SIN[$XANGLE]} *$Y3) + (${COS[$XANGLE]} * $Z3)) /1000 ))
NZ4=$(( ((${SIN[$XANGLE]} *$Y4) + (${COS[$XANGLE]} * $Z4)) /1000 ))
NZ5=$(( ((${SIN[$XANGLE]} *$Y5) + (${COS[$XANGLE]} * $Z5)) /1000 ))
NZ6=$(( ((${SIN[$XANGLE]} *$Y6) + (${COS[$XANGLE]} * $Z6)) /1000 ))
NZ7=$(( ((${SIN[$XANGLE]} *$Y7) + (${COS[$XANGLE]} * $Z7)) /1000 ))
NZ8=$(( ((${SIN[$XANGLE]} *$Y8) + (${COS[$XANGLE]} * $Z8)) /1000 ))

# ROTATE Y
X1=$(( ((${COS[$YANGLE]} *$NX1) + (${SIN[$YANGLE]} * $NZ1)) /1000 ))
X2=$(( ((${COS[$YANGLE]} *$NX2) + (${SIN[$YANGLE]} * $NZ2)) /1000 ))
X3=$(( ((${COS[$YANGLE]} *$NX3) + (${SIN[$YANGLE]} * $NZ3)) /1000 ))
X4=$(( ((${COS[$YANGLE]} *$NX4) + (${SIN[$YANGLE]} * $NZ4)) /1000 ))
X5=$(( ((${COS[$YANGLE]} *$NX5) + (${SIN[$YANGLE]} * $NZ5)) /1000 ))
X6=$(( ((${COS[$YANGLE]} *$NX6) + (${SIN[$YANGLE]} * $NZ6)) /1000 ))
X7=$(( ((${COS[$YANGLE]} *$NX7) + (${SIN[$YANGLE]} * $NZ7)) /1000 ))
X8=$(( ((${COS[$YANGLE]} *$NX8) + (${SIN[$YANGLE]} * $NZ8)) /1000 ))

Z1=$(( ((${COS[$YANGLE]} * $NZ1) - (${SIN[$YANGLE]} *$NX1)) /1000 ))
Z2=$(( ((${COS[$YANGLE]} * $NZ2) - (${SIN[$YANGLE]} *$NX2)) /1000 ))
Z3=$(( ((${COS[$YANGLE]} * $NZ3) - (${SIN[$YANGLE]} *$NX3)) /1000 ))
Z4=$(( ((${COS[$YANGLE]} * $NZ4) - (${SIN[$YANGLE]} *$NX4)) /1000 ))
Z5=$(( ((${COS[$YANGLE]} * $NZ5) - (${SIN[$YANGLE]} *$NX5)) /1000 ))
Z6=$(( ((${COS[$YANGLE]} * $NZ6) - (${SIN[$YANGLE]} *$NX6)) /1000 ))
Z7=$(( ((${COS[$YANGLE]} * $NZ7) - (${SIN[$YANGLE]} *$NX7)) /1000 ))
Z8=$(( ((${COS[$YANGLE]} * $NZ8) - (${SIN[$YANGLE]} *$NX8)) /1000 ))

# ROTATE Z
NX1=$(( ((${COS[$ZANGLE]} * $X1) - (${SIN[$ZANGLE]} * $NY1)) /1000 ))
NX2=$(( ((${COS[$ZANGLE]} * $X2) - (${SIN[$ZANGLE]} * $NY2)) /1000 ))
NX3=$(( ((${COS[$ZANGLE]} * $X3) - (${SIN[$ZANGLE]} * $NY3)) /1000 ))
NX4=$(( ((${COS[$ZANGLE]} * $X4) - (${SIN[$ZANGLE]} * $NY4)) /1000 ))
NX5=$(( ((${COS[$ZANGLE]} * $X5) - (${SIN[$ZANGLE]} * $NY5)) /1000 ))
NX6=$(( ((${COS[$ZANGLE]} * $X6) - (${SIN[$ZANGLE]} * $NY6)) /1000 ))
NX7=$(( ((${COS[$ZANGLE]} * $X7) - (${SIN[$ZANGLE]} * $NY7)) /1000 ))
NX8=$(( ((${COS[$ZANGLE]} * $X8) - (${SIN[$ZANGLE]} * $NY8)) /1000 ))

NY1=$(( ((${SIN[$ZANGLE]} * $X1) + (${COS[$ZANGLE]} * $NY1)) /1000 ))
NY2=$(( ((${SIN[$ZANGLE]} * $X2) + (${COS[$ZANGLE]} * $NY2)) /1000 ))
NY3=$(( ((${SIN[$ZANGLE]} * $X3) + (${COS[$ZANGLE]} * $NY3)) /1000 ))
NY4=$(( ((${SIN[$ZANGLE]} * $X4) + (${COS[$ZANGLE]} * $NY4)) /1000 ))
NY5=$(( ((${SIN[$ZANGLE]} * $X5) + (${COS[$ZANGLE]} * $NY5)) /1000 ))
NY6=$(( ((${SIN[$ZANGLE]} * $X6) + (${COS[$ZANGLE]} * $NY6)) /1000 ))
NY7=$(( ((${SIN[$ZANGLE]} * $X7) + (${COS[$ZANGLE]} * $NY7)) /1000 ))
NY8=$(( ((${SIN[$ZANGLE]} * $X8) + (${COS[$ZANGLE]} * $NY8)) /1000 ))

# PERSPECTIVE
XX1=$(( ($NX1*$D/($Z1+$D)) +128 ))
XX2=$(( ($NX2*$D/($Z2+$D)) +128 ))
XX3=$(( ($NX3*$D/($Z3+$D)) +128 ))
XX4=$(( ($NX4*$D/($Z4+$D)) +128 ))
XX5=$(( ($NX5*$D/($Z5+$D)) +128 ))
XX6=$(( ($NX6*$D/($Z6+$D)) +128 ))
XX7=$(( ($NX7*$D/($Z7+$D)) +128 ))
XX8=$(( ($NX8*$D/($Z8+$D)) +128 ))

YY1=$(( ($NY1*$D/($Z1+$D)) +128 ))
YY2=$(( ($NY2*$D/($Z2+$D)) +128 ))
YY3=$(( ($NY3*$D/($Z3+$D)) +128 ))
YY4=$(( ($NY4*$D/($Z4+$D)) +128 ))
YY5=$(( ($NY5*$D/($Z5+$D)) +128 ))
YY6=$(( ($NY6*$D/($Z6+$D)) +128 ))
YY7=$(( ($NY7*$D/($Z7+$D)) +128 ))
YY8=$(( ($NY8*$D/($Z8+$D)) +128 ))

S=$(<$SWITCH); ((S++)); echo $S > $SWITCH
if [ $S -lt 512 ]; then
echo '<svg width="256" height="256">
<line x1="'$XX1'" y1="'$YY1'" x2="'$XX2'" y2="'$YY2'" stroke="black" stroke-width="3" stroke-linecap="round"/>
<line x1="'$XX2'" y1="'$YY2'" x2="'$XX4'" y2="'$YY4'" stroke="black" stroke-width="3" stroke-linecap="round"/>
<line x1="'$XX4'" y1="'$YY4'" x2="'$XX3'" y2="'$YY3'" stroke="black" stroke-width="3" stroke-linecap="round"/>
<line x1="'$XX3'" y1="'$YY3'" x2="'$XX1'" y2="'$YY1'" stroke="black" stroke-width="3" stroke-linecap="round"/>
<line x1="'$XX1'" y1="'$YY1'" x2="'$XX5'" y2="'$YY5'" stroke="black" stroke-width="3" stroke-linecap="round"/>
<line x1="'$XX5'" y1="'$YY5'" x2="'$XX6'" y2="'$YY6'" stroke="black" stroke-width="3" stroke-linecap="round"/>
<line x1="'$XX6'" y1="'$YY6'" x2="'$XX2'" y2="'$YY2'" stroke="black" stroke-width="3" stroke-linecap="round"/>
<line x1="'$XX5'" y1="'$YY5'" x2="'$XX7'" y2="'$YY7'" stroke="black" stroke-width="3" stroke-linecap="round"/>
<line x1="'$XX7'" y1="'$YY7'" x2="'$XX8'" y2="'$YY8'" stroke="black" stroke-width="3" stroke-linecap="round"/>
<line x1="'$XX3'" y1="'$YY3'" x2="'$XX7'" y2="'$YY7'" stroke="black" stroke-width="3" stroke-linecap="round"/>
<line x1="'$XX4'" y1="'$YY4'" x2="'$XX8'" y2="'$YY8'" stroke="black" stroke-width="3" stroke-linecap="round"/>
<line x1="'$XX8'" y1="'$YY8'" x2="'$XX6'" y2="'$YY6'" stroke="black" stroke-width="3" stroke-linecap="round"/>
</svg>' > $PIC
else
echo '<svg width="256" height="256">
<path d="M '$XX1' '$YY1' L '$XX5' '$YY5' L '$XX6' '$YY6' L '$XX2' '$YY2' Z" stroke="black" stroke-width="3" fill="green" opacity="0.7" />
<path d="M '$XX3' '$YY3' L '$XX7' '$YY7' L '$XX8' '$YY8' L '$XX4' '$YY4' Z" stroke="black" stroke-width="3" fill="red" opacity="0.7" />
<path d="M '$XX2' '$YY2' L '$XX6' '$YY6' L '$XX8' '$YY8' L '$XX4' '$YY4' Z" stroke="black" stroke-width="3" fill="cyan" opacity="0.7" />
<path d="M '$XX3' '$YY3' L '$XX7' '$YY7' L '$XX5' '$YY5' L '$XX1' '$YY1' Z" stroke="black" stroke-width="3" fill="brown" opacity="0.7" />
<path d="M '$XX8' '$YY8' L '$XX7' '$YY7' L '$XX5' '$YY5' L '$XX6' '$YY6' Z" stroke="black" stroke-width="3" fill="yellow" opacity="0.7" />
<path d="M '$XX1' '$YY1' L '$XX2' '$YY2' L '$XX4' '$YY4' L '$XX3' '$YY3' Z" stroke="black" stroke-width="3" fill="orange" opacity="0.7" />
<text x="'$((${SIN[$XANGLE]}/16+86))'" y="256" font="Monospace" font-size="22" font-weight="bold">The End</text>
</svg>' > $PIC
fi
}
export -f vector


export MAIN='
<window title="Line Vector" resizable="false">
    <pixmap>
      <variable>PICTURE</variable>
      <input file>'$PIC'</input>
    </pixmap>
    <timer visible="false" milliseconds="true" interval="75">
      <action>'$USE_BASH'vector</action>
      <action>refresh:PICTURE</action>
    </timer>
<action signal="hide">exit:abort</action>
</window>
'

case $1 in
	-d | --dump) echo "$MAIN" ;;
	*) $GTKDIALOG -cp MAIN ;;
esac
