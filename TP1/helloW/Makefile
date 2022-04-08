# differents types de fichiers 
.SUFFIXES:.o.cpp.ln


#---------------------------------
# INITIALISATION DES VARIABLES 
#---------------------------------

# Indiquer le compilateur
CCC = g++

# Les chemins ou se trouvent les fichiers a inclure
INCLUDES= -I/usr/openwin/include

# Options de compilation.
CCFLAGS=  ${INCLUDES} -c

# Options pour le linker.
LFLAGS=  -o 

# Les librairies avec lesquelle on va effectueller l'edition de liens
LIBS=

# Les fichiers sources de l'application
FILES= HelloW.cpp ClientHW.cpp HelloA.cpp HelloB.cpp

#-----------
# LES CIBLES
#-----------

tp:  $(FILES:.cpp=.o)
	$(CCC) -o helloW $(FILES:.cpp=.o) ${LIBS}

clean:
	/bin/rm $(FILES:.cpp=.o) helloW

#-----------------------------------------------------------------------------
# LES REGLES DE DEPENDANCE. Certaines sont implicites mais je recommande d'en 
# mettre une par fichier source. 
#-----------------------------------------------------------------------------

ClientHW.o:ClientHW.cpp HelloW.cpp HelloA.cpp HelloB.cpp HelloW.hpp HelloA.hpp HelloB.hpp
%.o:%.cpp %.hpp

#---------------------------------
# REGLES DE COMPILATION IMPLICITES
#---------------------------------

.cpp.o:; ${CCC} ${CCFLAGS} $*.cpp

