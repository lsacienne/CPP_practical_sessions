TARGETS = exercise_1 exercise_2 exercise_3 exercise_4 \
	exercise_5 exercise_6 exercise_7 exercise_8

DEST = bin

all : $(DEST) $(addprefix $(DEST)/, $(TARGETS))

$(DEST) :
	mkdir $(DEST)

$(DEST)/exercise_1 : exercise_1.cpp
	g++ $< -o $@

$(DEST)/exercise_2 : exercise_2.cpp
	g++ $< -o $@

$(DEST)/exercise_3 : exercise_3.cpp
	g++ $< -o $@

$(DEST)/exercise_4 : exercise_4.cpp
	g++ $< -o $@

$(DEST)/exercise_5 : exercise_5.cpp
	g++ $< -o $@

$(DEST)/exercise_6 : exercise_6.cpp
	g++ $< -o $@

$(DEST)/exercise_7 : exercise_7.cpp
	g++ $< -o $@

$(DEST)/exercise_8 : exercise_8.cpp
	g++ $< -o $@

clean : 
	rm -r $(DEST)