#!/bin/bash

T="$(date +%s)"
source timeoffset

# get current time,  using bc to trim left zeroes so the C compiler
# does not see octal for values less than 10
(
	echo "// This allow the clock to the set to the current time automatically"
	echo "#pragma once"
	echo "#define MINUTES  $(date +%M | bc)"
	echo "#define HOURS    $(date +%k | bc)"
	echo "#define SECONDS  $(($(date +%S | bc) + $OFFSET))"
) > src/current_time.h

echo "Uploading time $(date +%k | bc):$(date +%M | bc):$(date +%S | bc) + $OFFSET"

ino build && ino upload

T="$(($(date +%s)-T))"

(
	echo "# This allows compensation for compile and upload times"
	echo "OFFSET=$T"
) > timeoffset

# better reset to zero
git checkout src/current_time.h

echo "Time taken in seconds: ${T}"
