#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/zacharymiller/cli-football-simulator/build
  echo Build\ all\ projects
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/zacharymiller/cli-football-simulator/build
  echo Build\ all\ projects
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/zacharymiller/cli-football-simulator/build
  echo Build\ all\ projects
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/zacharymiller/cli-football-simulator/build
  echo Build\ all\ projects
fi

