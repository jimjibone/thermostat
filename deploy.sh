# get current time,  using bc to trim left zeroes so the C compiler
# does not see octal for values less than 10
(
	echo "// This allow the clock to the set to the current time automatically"
	echo "#pragma once"
	echo "#define MINUTES  $(date +%M | bc)"
	echo "#define HOURS    $(date +%k | bc)"
	echo "#define SECONDS  $(date +%S | bc)"
) > src/current_time.h

echo "Uploading time $(date +%k | bc):$(date +%M | bc):$(date +%S | bc)"

ino build && ino upload

# better reset to zero
#git checkout src/current_time.h
