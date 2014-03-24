#!/bin/bash
# create multiresolution windows icon
ICON_DST=../../src/qt/res/icons/secondcoin.ico

convert ../../src/qt/res/icons/secondcoin-16.png ../../src/qt/res/icons/secondcoin-32.png ../../src/qt/res/icons/secondcoin-48.png ${ICON_DST}
