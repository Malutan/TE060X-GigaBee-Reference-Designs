#!/bin/sh
# Projects to release
REPOSITORY=TE060X-GigaBee-Reference-Designs
# Numbers of projects to release (list like '1 2 3 4')
PROJECT_LIST='1 2 3 4 5 6'
# Project 1 description
# List of folders requred to release (First will be used as name)
NAME1='GigaBee_XPS13.2-Axi'
# Tool used to build
TOOL1='XPS-13.2'
# Project Version
VER1='1.0'

# Project 2 description
NAME2='GigaBee_XPS13.2-Axi_lite'
TOOL2='XPS-13.2'
VER2='1.0'

# Project 3 description
NAME3='GigaBee_XPS13.2-Blinkin'
TOOL3='ISE-13.2'
VER3='1.0'

# Project 4 description
NAME4='GigaBee_ISE12.4-MIG'
TOOL4='ISE-12.4'
VER4='1.0'

# Project 5 description
NAME5='GigaBee_XPS13.1-UDP-Datalogger'
TOOL5='ISE-13.1'
VER5='1.0'

# Project 6 description
NAME6='GigaBee_XPS14.2-FlashWriter'
# Tool used to build
TOOL6='XPS-14.2'
# Project Version
VER6='1.0'

############# Do not edit below this line !!!
SUBVER=`git rev-parse --short HEAD`

if [ -z "$PROJECT_LIST" ]; then exit ; fi
cd ..
for l in $PROJECT_LIST
do
	namelist=NAME$l
	tool=TOOL$l
	ver=VER$l
	name=${!namelist}
	set $name
	for proj in ${!namelist}
	do
#		zip -rq $1-${!tool}-v${!ver}.${SUBVER}.zip ${REPOSITORY}/${proj}
		zip -rq $1-v${!ver}.${SUBVER}.zip ${REPOSITORY}/${proj}
	done
done
cd ${REPOSITORY}

