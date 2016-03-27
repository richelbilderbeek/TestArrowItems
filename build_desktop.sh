#!/bin/bash
qmake TestQtArrowItemsDesktop.pro
make
# Don't run on Travis
# ./TestQtArrowItemsDesktop
