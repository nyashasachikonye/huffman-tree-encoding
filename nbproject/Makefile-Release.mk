#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/CodeTableBuilder.o \
	${OBJECTDIR}/Development/Development.o \
	${OBJECTDIR}/Encoder.o \
	${OBJECTDIR}/FileOperations.o \
	${OBJECTDIR}/FrequencyTally.o \
	${OBJECTDIR}/HuffmanEncode.o \
	${OBJECTDIR}/HuffmanNode.o \
	${OBJECTDIR}/HuffmanTree.o \
	${OBJECTDIR}/HuffmanTreeBuilder.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/huffmantreeencoding

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/huffmantreeencoding: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/huffmantreeencoding ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/CodeTableBuilder.o: CodeTableBuilder.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CodeTableBuilder.o CodeTableBuilder.cpp

${OBJECTDIR}/Development/Development.o: Development/Development.cpp 
	${MKDIR} -p ${OBJECTDIR}/Development
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Development/Development.o Development/Development.cpp

${OBJECTDIR}/Encoder.o: Encoder.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Encoder.o Encoder.cpp

${OBJECTDIR}/FileOperations.o: FileOperations.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FileOperations.o FileOperations.cpp

${OBJECTDIR}/FrequencyTally.o: FrequencyTally.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FrequencyTally.o FrequencyTally.cpp

${OBJECTDIR}/HuffmanEncode.o: HuffmanEncode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HuffmanEncode.o HuffmanEncode.cpp

${OBJECTDIR}/HuffmanNode.o: HuffmanNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HuffmanNode.o HuffmanNode.cpp

${OBJECTDIR}/HuffmanTree.o: HuffmanTree.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HuffmanTree.o HuffmanTree.cpp

${OBJECTDIR}/HuffmanTreeBuilder.o: HuffmanTreeBuilder.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HuffmanTreeBuilder.o HuffmanTreeBuilder.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/huffmantreeencoding

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
